#include "./draw_window.h"
#include "../../utils/Utils.h"
#include "../../utils/Colors.h"
#include <string>

using namespace std;

DrawWindow::DrawWindow(int width, int height, Vector2 pos)
{
    this->width = width;
    this->height = height;
    this->pos = pos;
    widgets.push_back(new Button("Clear",
                                 new Color(255, 0, 0),
                                 new Color(0), 0, height - 50, 100, 50,
                                 clearPoints));

    widgets.push_back(new Button("Diminuir",
                                 new Color(0),
                                 new Color(4), 150, height - 100, 100, 50,
                                 [=]()
                                 {
                                     step -= 1;
                                 }));
    widgets.push_back(new Button("Aumentar",
                                 new Color(0),
                                 new Color(4), 300, height - 100, 100, 50,
                                 [=]()
                                 {
                                     step += 1;
                                 }));
}

void DrawWindow::render()
{
    CV::color(Color::white);
    CV::rectFill(pos, Vector2(width, height));
    CV::color(0, 0, 0);
    CV::rect(pos, Vector2(pos.x + width, pos.y + height));
    curve = Utils::bezierCurve(points, 1 / (float)step);

    string text = "Numero de pontos que define a curva " + to_string(step);
    CV::text(150, height - 40, text.c_str());

    for (auto widget : widgets)
    {
        widget->Render();
    }

    for (auto p : points)
    {
        p.draw();
    }
}

void DrawWindow::mouse(int button, int state, int wheel, int direction, int x, int y)
{
    for (auto widget : widgets)
    {
        if (widget->onClick(x, y, state))
        {
            return;
        }
    }
    // verifica se mouse está dentro da janela
    if (x > pos.x && x < pos.x + width && y > pos.y && y < pos.y + height)
    {
        // clique com o botão esquerdo do mouse
        if (button == 0 && state == 0)
        {
            // se não existe nem um ponto cria um novo ponto
            if (points.empty())
            {
                points.push_back(Point(Vector2(x, y)));
            }

            // Verifica se o clique foi em algum dos pontos existentes se foi, seleciona o ponto
            for (int i = 0; i < points.size(); i++)
            {
                if (points[i].isInside(x, y))
                {
                    selected = i;
                }
            }

            // se o clique não foi em nenhum ponto, cria um novo ponto
            if (selected == -1)
            {
                points.push_back(Point(Vector2(x, y)));
            }
        }

        // Se algum ponto estiver selecionado, move o ponto selecionado
        if (selected != -1)
        {
            points[selected].set(Vector2(x, y));
        }

        // deseleciona o ponto ao soltar o botão esquerdo do mouse
        if (button == 0 && state == 1)
        {
            selected = -1;
        }
    }
}
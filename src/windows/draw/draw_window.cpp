#include "./draw_window.h"
#include "../../utils/Utils.h"
#include "../../utils/Colors.h"

DrawWindow::DrawWindow(int width, int height, Vector2 pos)
{
    this->width = width;
    this->height = height;
    this->pos = pos;
    widgets.push_back(new Button("Clear",
                                 new Color(255, 0, 0),
                                 new Color(0), 0, height - 50, 100, 50,
                                 clearPoints));
}

void DrawWindow::render()
{
    CV::color(Color::white);
    CV::rectFill(pos, Vector2(width, height));
    CV::color(0, 0, 0);
    CV::rect(pos, Vector2(pos.x + width, pos.y + height));
    curve = Utils::bezierCurve(points);

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
    for (auto widget : widgets)
    {
        widget->onClick(x, y, state);
    }
}
#include "view_window.h"
#include "../../matrix/matrix.h"

ViewWindow::ViewWindow(int width, int height, Vector2 pos, DrawWindow *drawWindow)
{
    this->width = width;
    this->height = height;
    this->pos = pos;
    this->drawWindow = drawWindow;
}

void ViewWindow::render()
{
    CV::translate(this->pos.x, this->pos.y);
    CV::color(0, 0, 0);
    CV::rect(Vector2(0, 0), Vector2(width, height));
    points = drawWindow->curve;
    points = sweep(points);
    for (auto p : points)
    {
        CV::point(p.x, p.y);
    }
}

void ViewWindow::mouse(int button, int state, int wheel, int direction, int x, int y)
{
    // verifica se mouse está dentro da janela
    if (x > pos.x && x < pos.x + width && y > pos.y && y < pos.y + height)
    {
        // clique com o botão esquerdo do mouse
        if (button == 0 && state == 0)
        {
        }
    }
}

vector<Vector2> ViewWindow::sweep(vector<Vector2> points)
{
    vector<Vector2> newPoints;
    // rotaciona os pontos formando 18 hemisferios
    for (int j = 0; j < 18; j++)
    {

        for (int i = 0; i < points.size(); i++)
        {
            float angle = j * 20;
            Vector3 p = Vector3(points[i].x, points[i].y, 0);
            p = Matrix::rotateY(angle) * p;
            p = Matrix::translate3d(width / 2, 0, 300) * p;
            newPoints.push_back(p.project(300));
        }
    }

    return newPoints;
}

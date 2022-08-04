#include "view_window.h"

ViewWindow::ViewWindow(int width, int height, Vector2 pos, Window *drawWindow)
{
    this->width = width;
    this->height = height;
    this->pos = pos;
    this->drawWindow = drawWindow;
}

void ViewWindow::render()
{
    CV::color(0, 0, 0);
    CV::rect(pos, Vector2(pos.x + width, pos.y + height));
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
#include "view_window.h"
#include "../../matrix/matrix.h"

ViewWindow::ViewWindow(int width, int height, Vector2 pos, DrawWindow *drawWindow)
{
    this->width = width;
    this->height = height;
    this->pos = pos;
    this->drawWindow = drawWindow;
    translateX = width / 2;
    translateY = 0;
    translateZ = 300;

    widgets.push_back(new CheckBox(pos.x + 10, height - 30, 20, 20, new Color(4), "Perspectiva", [=]()
                                   { isPerspective = !isPerspective; }));

    widgets.push_back(new CheckBox(pos.x + 10, height - 50, 20, 20, new Color(4), "Rotaciona no eixo X", [=]()
                                   { rotatingX = !rotatingX; }));

    widgets.push_back(new CheckBox(pos.x + 10, height - 70, 20, 20, new Color(4), "Rotaciona no eixo Y", [=]()
                                   { rotatingY = !rotatingY; }));

    widgets.push_back(new CheckBox(pos.x + 10, height - 90, 20, 20, new Color(4), "Rotaciona no eixo Z", [=]()
                                   { rotatingZ = !rotatingZ; }));
}

void ViewWindow::render()
{
    CV::translate(this->pos.x, this->pos.y);
    CV::color(0, 0, 0);
    CV::rect(Vector2(0, 0), Vector2(width, height));
    points = drawWindow->curve;
    pointsMatrix = sweep(points);
    draw(projectPoints(pointsMatrix, isPerspective));
    CV::translate(0, 0);
    for (auto widget : widgets)
    {
        widget->Render();
    }
    if (rotatingX)
    {
        rotationX += 1;
    }
    if (rotatingY)
    {
        rotationY += 1;
    }
    if (rotatingZ)
    {
        rotationZ += 1;
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
    for (auto widget : widgets)
    {
        widget->onClick(x, y, state);
    }
}

void ViewWindow::keyboard(int key)
{
    switch (key)
    {
    // seta para esquerda
    case 200:
        translateX--;
        break;
    // seta para cima
    case 201:
        translateY++;
        break;
    // seta para direita
    case 202:
        translateX++;
        break;
    // seta para baixo
    case 203:
        translateY--;
        break;
    // mais
    case 43:
        translateZ++;
        break;
    // menos
    case 45:
        translateZ--;
        break;
    }
}

vector<vector<Vector3>> ViewWindow::sweep(vector<Vector2> points)
{
    vector<vector<Vector3>> matrix(18);
    // rotaciona os pontos formando 18 hemisferios
    for (int c = 0; c < 18; c++)
    {
        for (int l = 0; l < points.size(); l++)
        {
            float angle = c * 20;
            Vector3 p = Vector3(points[l].x, points[l].y, 0);
            p = Matrix::rotateY(angle) * p;
            p = Matrix::rotateX(rotationX) * Matrix::rotateY(rotationY) * Matrix::rotateZ(rotationZ) * p;
            p = Matrix::translate3d(translateX, translateY, translateZ) * p;
            matrix[c].push_back(p);
        }
    }

    return matrix;
}

void ViewWindow::draw(vector<vector<Vector2>> matrix)
{
    for (int l = 0; l < matrix.size(); l++)
    {
        for (int c = 0; c < matrix[l].size(); c++)
        {
            if (c != matrix[l].size() - 1)
            {
                CV::line(matrix[l][c], matrix[(l + 1) % matrix.size()][c]);
                CV::line(matrix[l][c], matrix[l][(c + 1) % matrix[l].size()]);
                CV::line(matrix[l][c], matrix[(l + 1) % matrix.size()][(c + 1) % matrix[l].size()]);
            }
        }
    }
}

vector<vector<Vector2>> ViewWindow::projectPoints(vector<vector<Vector3>> matrix, bool perspectiveProjection)
{
    vector<vector<Vector2>> projectedMatrix(matrix.size());
    for (int c = 0; c < matrix.size(); c++)
    {
        for (int l = 0; l < matrix[c].size(); l++)
        {
            projectedMatrix[c].push_back(
                perspectiveProjection
                    ? matrix[c][l].perspectiveProjection(translateZ)
                    : matrix[c][l].orthographicProjection());
        }
    }
    return projectedMatrix;
}

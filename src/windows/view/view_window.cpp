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
    pointsMatrix = sweep(points);
    draw(projectPoints(pointsMatrix, true));
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
            p = Matrix::translate3d(width / 2, 0, 300) * p;
            matrix[c].push_back(p);
        }
    }

    return matrix;
}

void ViewWindow::draw(vector<vector<Vector2>> matrix)
{
    for (int c = 0; c < matrix.size(); c++)
    {
        for (int l = 0; l < matrix[c].size(); l++)
        {
            CV::line(matrix[c][l], matrix[c][(l + 1) % matrix[c].size()]);
            CV::line(matrix[c][l], matrix[(c + 1) % matrix.size()][l]);
            CV::line(matrix[c][l], matrix[(c + 1) % matrix.size()][(l + 1) % matrix[c].size()]);
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
                    ? matrix[c][l].perspectiveProjection(300)
                    : matrix[c][l].orthographicProjection());
        }
    }
    return projectedMatrix;
}

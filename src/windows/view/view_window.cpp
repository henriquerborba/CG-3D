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

    widgets.push_back(new Button("Diminuir",
                                 new Color(0),
                                 new Color(4), pos.x + 250, height - 100, 100, 50,
                                 [=]()
                                 {
                                     hemispheres -= 2;
                                 }));
    widgets.push_back(new Button("Aumentar",
                                 new Color(0),
                                 new Color(4), pos.x + 400, height - 100, 100, 50,
                                 [=]()
                                 {
                                     hemispheres += 2;
                                 }));
}

void ViewWindow::render()
{
    CV::translate(this->pos.x, this->pos.y);
    CV::color(0, 0, 0);
    CV::rect(Vector2(0, 0), Vector2(width, height));
    points = drawWindow->curve;
    pointsMatrix = sweep(points, hemispheres);
    draw(projectPoints(pointsMatrix, isPerspective));
    string text = "Quantidade de hemisferios: " + to_string(hemispheres);
    CV::text(250, height - 40, text.c_str());
    string faces_text = "Quantidade de faces: " + to_string(drawWindow->step * hemispheres * 2);
    CV::text(250, height - 120, faces_text.c_str());

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
    // verifica se mouse est?? dentro da janela
    if (x > pos.x && x < pos.x + width && y > pos.y && y < pos.y + height)
    {
        // clique com o bot??o esquerdo do mouse
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

vector<vector<Vector3>> ViewWindow::sweep(vector<Vector2> points, int hemispheres)
{
    vector<vector<Vector3>> matrix(hemispheres);
    // rotaciona os pontos formando h hemisferios
    for (int c = 0; c < hemispheres; c++)
    {
        for (size_t l = 0; l < points.size(); l++)
        {
            float angle = c * (360 / hemispheres);
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
    for (size_t l = 0; l < matrix.size(); l++)
    {
        for (size_t c = 0; c < matrix[l].size(); c++)
        {
            if (c != matrix[l].size() - 1)
            {
                CV::line(matrix[l][c], matrix[(l + 1) % matrix.size()][(c + 1) % matrix[l].size()]);
                CV::line(matrix[l][c], matrix[l][(c + 1) % matrix[l].size()]);
            }
            CV::line(matrix[l][c], matrix[(l + 1) % matrix.size()][c]);
        }
    }
}

vector<vector<Vector2>> ViewWindow::projectPoints(vector<vector<Vector3>> matrix, bool perspectiveProjection)
{
    vector<vector<Vector2>> projectedMatrix(matrix.size());
    for (size_t c = 0; c < matrix.size(); c++)
    {
        for (size_t l = 0; l < matrix[c].size(); l++)
        {
            projectedMatrix[c].push_back(
                perspectiveProjection
                    ? matrix[c][l].perspectiveProjection(translateZ)
                    : matrix[c][l].orthographicProjection());
        }
    }
    return projectedMatrix;
}

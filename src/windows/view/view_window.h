#ifndef __VIEW_WINDOW_H__
#define __VIEW_WINDOW_H__

#include <vector>
#include "../window.h"
#include "../draw/draw_window.h"
#include "../../vectors/vector3.h"
#include "../../point/point.h"
#include "../../widgets/checkbox/checkbox.h"

using namespace std;

class ViewWindow : public Window
{
private:
    DrawWindow *drawWindow;
    vector<Vector2> points;
    vector<vector<Vector3>> pointsMatrix;
    bool isPerspective = false;

public:
    ViewWindow() = default;
    ViewWindow(int width, int height, Vector2 pos, DrawWindow *drawWindow);
    virtual ~ViewWindow() = default;
    virtual void render();
    virtual void mouse(int button, int state, int wheel, int direction, int x, int y);
    vector<vector<Vector3>> sweep(vector<Vector2> points);
    void draw(vector<vector<Vector2>> matrix);
    vector<vector<Vector2>> projectPoints(vector<vector<Vector3>> matrix, bool perspectiveProjection);
};

#endif // __VIEW_WINDOW_H__
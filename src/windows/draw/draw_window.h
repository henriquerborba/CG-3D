#ifndef __DRAW_WINDOW__H__
#define __DRAW_WINDOW__H__

#include <vector>
#include "../window.h"
#include "../../point/point.h"

using namespace std;

class DrawWindow : public Window
{
private:
    int selected = -1;
    vector<Point> points;

public:
    DrawWindow() = default;
    DrawWindow(int width, int height, Vector2 pos);
    virtual ~DrawWindow() = default;
    virtual void render();
    virtual void keyboard(int key);
    virtual void keyboardUp(int key);
    virtual void mouse(int button, int state, int wheel, int direction, int x, int y);
};

#endif // __DRAW_WINDOW__H__
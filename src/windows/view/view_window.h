#ifndef __VIEW_WINDOW_H__
#define __VIEW_WINDOW_H__

#include <vector>
#include "../window.h"
#include "../draw/draw_window.h"
#include "../../point/point.h"

using namespace std;

class ViewWindow : public Window
{
private:
    Window *drawWindow;

public:
    ViewWindow() = default;
    ViewWindow(int width, int height, Vector2 pos, Window *drawWindow);
    virtual ~ViewWindow() = default;
    virtual void render();
    virtual void mouse(int button, int state, int wheel, int direction, int x, int y);
};

#endif // __VIEW_WINDOW_H__
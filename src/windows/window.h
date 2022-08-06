#ifndef __WINDOW__H__
#define __WINDOW__H__

#include "../vectors/Vector2.h"
#include "../widgets/button/button.h"

class Window
{
protected:
    Window() = default;
    Window(int width, int height, Vector2 pos);

    int width, height;
    Vector2 pos;
    vector<Widget *> widgets;

public:
    virtual ~Window() = default;
    virtual void render() = 0;
    virtual void mouse(int button, int state, int wheel, int direction, int x, int y) = 0;
};

#endif // __WINDOW__H__
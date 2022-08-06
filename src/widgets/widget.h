#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED

#include "../utils/colors.h"
#include <functional>

using namespace std;

class Widget
{
protected:
    int x, y;
    int width, height;
    Color *color = new Color(1);
    function<void(void)> callBack;

public:
    Widget();
    ~Widget() {}
    Widget(int x, int y, int width, int height, function<void(void)> callBack);
    Widget(int x, int y, int width, int height, Color *color, function<void(void)> callBack);
    Widget(int x, int y, int width, int height);
    virtual void Render() = 0;

    bool onClick(int mx, int my, int state)
    {
        if (mx >= x && mx <= x + width && my >= y && my <= y + height && state == 0)
        {
            callBack();
        }
    }
};

#endif // WIDGET_H_INCLUDED

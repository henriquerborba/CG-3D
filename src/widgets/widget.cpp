#include "widget.h"
#include <iostream>

Widget::Widget()
{
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    callBack = NULL;
};

Widget::Widget(int x, int y, int width, int height, function<void(void)> callBack)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->callBack = callBack;
};

Widget::Widget(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->callBack = NULL;
};

Widget::Widget(int x, int y, int width, int height, Color *color, function<void(void)> callBack)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->color = color;
    this->callBack = callBack;
};

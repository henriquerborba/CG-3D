#ifndef __POINT_H__
#define __POINT_H__

#include "../vectors/Vector2.h"
#include "../canvas/gl_canvas2d.h"

class Point : public Vector2
{
public:
    Vector2 pos;
    float color[3] = {0, 0, 0};
    int hitBox = 5;

    Point(Vector2 pos);

    void set(Vector2 pos);
    void set(float x, float y);

    void draw();
    bool isInside(float x, float y);

    ~Point();
};

#endif // __POINT_H__
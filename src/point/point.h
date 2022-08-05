#ifndef __POINT_H__
#define __POINT_H__

#include "../canvas/gl_canvas2d.h"
#include "../vectors/Vector2.h"
#include "../vectors/Vector3.h"

class Point : public Vector2
{
public:
    Vector2 pos;
    float color[3] = {0, 0, 0};
    int hitBox = 5;

    Point(Vector2 pos);
    Point(Vector2 pos, float color[3]);

    void set(Vector2 pos);
    void set(float x, float y);

    void draw();
    bool isInside(float x, float y);

    Vector3 toVector3(void);

    ~Point();
};

#endif // __POINT_H__

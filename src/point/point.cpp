#include "point.h"

Point::Point(Vector2 pos) : Vector2(pos.x, pos.y)
{
    this->pos = pos;
};

void Point::draw()
{
    CV::color(this->color);
    CV::rectFill(pos.x - hitBox, pos.y - hitBox, pos.x + hitBox, pos.y + hitBox);
};

void Point::set(Vector2 pos)
{
    this->pos = pos;
    this->x = pos.x;
    this->y = pos.y;
};

bool Point::isInside(float x, float y)
{
    if (x > pos.x - hitBox && x < pos.x + hitBox && y > pos.y - hitBox && y < pos.y + hitBox)
    {
        return true;
    }
    return false;
};

Point::~Point(){};
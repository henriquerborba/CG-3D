#include <iostream>
#include "../../widgets/button/button.h"
#include "../../canvas/gl_canvas2d.h"
#include "../widget.h"
using namespace std;

Button::Button(const char *label, int x, int y, int width, int height, function<void(void)> onClick) : Widget(x, y, width, height, onClick)
{
    this->label = label;
}

Button::Button(const char *label, int x, int y, int width, int height) : Widget(x, y, width, height)
{
    this->label = label;
}

Button::Button(const char *label, Color *labelColor, Color *backgroundColor, int x, int y, int width, int height, function<void(void)> onClick) : Widget(x, y, width, height, onClick)
{
    this->label = label;
    this->labelColor = labelColor;
    this->color = backgroundColor;
};

Button::Button(const char *label, Color *backgroundColor, int x, int y, int width, int height, function<void(void)> onClick) : Widget(x, y, width, height, onClick)
{
    this->label = label;
    this->color = backgroundColor;
}

void Button::Render()
{
    CV::color(color->get());
    CV::rectFill(x, y, x + width, y + height);
    CV::color(labelColor->get());
    CV::text(x + width / 2 - strlen(label) * 4, y + height / 2, label);
}

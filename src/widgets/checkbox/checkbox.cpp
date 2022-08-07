#include "checkbox.h"
#include "../../utils/colors.h"

CheckBox::CheckBox(int x, int y, int width, int height, function<void(void)> onClick) : Widget(x, y, width, height)
{
    checked = false;
    callBack = [=]()
    {
        checked = !checked;
        onClick();
    };
}

CheckBox::CheckBox(int x, int y, int width, int height, Color *color, const char *description, function<void(void)> onClick) : Widget(x, y, width, height)
{
    cout << "x" << x + width << "y" << y + height << endl;
    checked = false;
    callBack = [=]()
    {
        checked = !checked;
        onClick();
    };
    this->description = description;
    this->color = color;
}

void CheckBox::Render()
{
    CV::color(Color::black);
    CV::rect(x, y, x + width, y + height);
    if (checked)
    {
        CV::color(Color::blue);
        CV::rectFill(x + 1, y + 1, x + width - 1, y + height - 1);
    }
    CV::color(color->get());
    CV::text(x + width + 5, y + height / 2, description);
}
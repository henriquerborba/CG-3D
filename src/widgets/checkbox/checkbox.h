#ifndef __CHECKBOX_H__
#define __CHECKBOX_H__

#include "../widget.h"
#include "../../canvas/gl_canvas2d.h"

class CheckBox : public Widget
{
    bool checked;
    const char *description;

public:
    CheckBox(int x, int y, int width, int height, function<void(void)> onClick);
    CheckBox(int x, int y, int width, int height, Color *color, const char *description, function<void(void)> onClick);
    void Render();
    void mouse(int button, int state, int wheel, int direction, int x, int y);
    bool isChecked();
    void setChecked(bool checked);
};

#endif // __CHECKBOX_H__
#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
using namespace std;

#include "../widget.h"
#include "../../utils/colors.h"
#include <functional>

using namespace std;

class Button : public Widget
{
private:
    const char *label;
    Color *labelColor = new Color(0, 0, 0);

public:
    Button(const char *label, int x, int y, int width, int height, function<void(void)> onClick);
    ~Button(){};
    Button(const char *label, int x, int y, int width, int height);
    Button(const char *label, Color *backgroundColor, int x, int y, int width, int height, function<void(void)> onClick);
    Button(const char *label, Color *labelColor, Color *backgroundColor, int x, int y, int width, int height, function<void(void)> onClick);

    void Render();
};

#endif // BUTTON_H_INCLUDED

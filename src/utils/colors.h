#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

class Color
{
    float colors[14][3] =
        {
            {0, 0, 0},       // Black
            {0.5, 0.5, 0.5}, // Gray
            {1, 0, 0},       // Red
            {0, 1, 0},       // Green
            {0, 0, 1},       // Blue
            {0, 1, 1},       // Cyan
            {1, 0, 1},       // Magenta
            {1, 1, 0},       // Yellow
            {1, 0.5, 0},     // Orange
            {0.5, 0, 0},     // Brown
            {0.5, 0.5, 0},   // Olive
            {0, 0.5, 0.5},   //
            {0.5, 0, 0.5},   //
            {1, 1, 1},       // white
    };
    float color[3] = {0, 0, 0};

public:
    Color() {}
    Color(float r, float g, float b)
    {
        color[0] = r / 255;
        color[1] = g / 255;
        color[2] = b / 255;
    }
    Color(int indx)
    {
        color[0] = colors[indx][0];
        color[1] = colors[indx][1];
        color[2] = colors[indx][2];
    }

    float r()
    {
        return color[0] * 255;
    }

    float g()
    {
        return color[1] * 255;
    }

    float b()
    {
        return color[2] * 255;
    }

    // Método que retorna a cor
    float *get()
    {
        return color;
    };

    static const int black = 0;
    static const int gray = 1;
    static const int red = 2;
    static const int green = 3;
    static const int blue = 4;
    static const int cyan = 5;
    static const int magenta = 6;
    static const int yellow = 7;
    static const int orange = 8;
    static const int brown = 9;
    static const int olive = 10;
    static const int teal = 11;
    static const int purple = 12;
    static const int white = 13;
};

#endif // COLOR_H_INCLUDED

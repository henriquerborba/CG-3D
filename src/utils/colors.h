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
    }
};

#endif // COLOR_H_INCLUDED

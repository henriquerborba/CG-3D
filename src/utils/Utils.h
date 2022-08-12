#ifndef __UTILS_H__
#define __UTILS_H__

#include "../point/point.h"
using namespace std;

class Utils
{
public:
    // função que desenha uma curva de bezier dado um vetor de pontos.
    static vector<Vector2> bezierCurve(vector<Point> pontos, float step = 0.01f)
    {
        vector<Vector2> curve;
        CV::color(0, 0, 0);
        int n = pontos.size() - 1;
        int nFatorial = factorial(n);
        for (float t = 0; t < 1; t += step)
        {
            Vector2 p = Vector2(0, 0);
            for (int i = 0; i <= n; i++)
            {
                p += pontos[i] * pow(t, i) * pow(1 - t, n - i) * (nFatorial / (factorial(i) * factorial(n - i)));
            }
            CV::point(p);
            curve.push_back(p);
        }
        for (int i = 0; i < curve.size() - 1; i++)
        {
            CV::line(curve[i], curve[i + 1]);
        }
        return curve;
    }

    static int factorial(int number)
    {
        int fact = 1;
        for (int i = 1; i <= number; i++)
        {
            fact *= i;
        }

        return fact;
    }
};

#endif // UTILS_H_INCLUDED
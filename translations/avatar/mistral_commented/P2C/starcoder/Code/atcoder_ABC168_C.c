#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, h, m;
    scanf("%d %d %d %d", &a, &b, &h, &m);
    double C = abs(360 / 60 * m - 360 / 12 * h - 360 / 12 / 60 * m);
    if (C > 180)
    {
        C = 360 - C;
    }
    double cosC = cos(C * M_PI / 180);
    printf("%.2lf\n", sqrt(a * a + b * b - 2 * a * b * cosC));
    return 0;
}

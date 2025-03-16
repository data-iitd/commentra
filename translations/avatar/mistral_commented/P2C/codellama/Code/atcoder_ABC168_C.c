#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, h, m;
    double C, cosC;

    scanf("%d %d %d %d", &a, &b, &h, &m);

    C = abs(360 / 60 * m - 360 / 12 * h - 360 / 12 / 60 * m);
    if (C > 180)
        C = 360 - C;

    cosC = cos(C * M_PI / 180);

    printf("%.3lf\n", sqrt(a * a + b * b - 2 * a * b * cosC));

    return 0;
}

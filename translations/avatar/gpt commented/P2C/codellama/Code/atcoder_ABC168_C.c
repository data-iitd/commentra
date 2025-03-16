#include <stdio.h>
#include <math.h>

int main()
{
    // Read input values for hours (h), minutes (m), and lengths (a, b)
    int a, b, h, m;
    scanf("%d %d %d %d", &a, &b, &h, &m);

    // Calculate the angle C between the hour and minute hands of the clock
    // The formula calculates the absolute difference in degrees
    double C = fabs(360 / 60 * m - 360 / 12 * h - 360 / 12 / 60 * m);

    // If the angle is greater than 180 degrees, find the smaller angle
    if (C > 180)
        C = 360 - C;

    // Calculate the cosine of angle C in radians
    double cosC = cos(radians(C));

    // Use the Law of Cosines to calculate the length of the third side of the triangle
    // formed by the lengths a, b, and the angle C
    printf("%.2lf\n", sqrt(a * a + b * b - 2 * a * b * cosC));

    return 0;
}


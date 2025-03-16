#include <stdio.h>
#include <math.h>

int main() {
    int a, b, h, m;
    scanf("%d %d %d %d", &a, &b, &h, &m);

    // Calculating the angle C between the hour and minute hands of a clock
    double C = fabs(360.0 / 60 * m - 360.0 / 12 * h - 360.0 / 12 / 60 * m);

    // Adjusting the angle C if it is greater than 180 degrees
    if (C > 180.0) {
        C = 360.0 - C;
    }

    // Calculating the cosine of angle C in radians
    double cosC = cos(C * M_PI / 180.0);

    // Calculating the length of the line segment connecting the tips of the hour and minute hands using the Law of Cosines
    double length = sqrt(a * a + b * b - 2 * a * b * cosC);

    // Printing the length of the line segment
    printf("%.10f\n", length);

    return 0;
}

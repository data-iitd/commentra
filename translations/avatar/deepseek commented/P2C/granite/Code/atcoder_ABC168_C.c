

#include <stdio.h>
#include <math.h>

int main() {
    int a, b, h, m;
    scanf("%d %d %d %d", &a, &b, &h, &m);
    // Taking input values for the lengths of the sides of the triangle and the time

    double C = fabs(360.0 / 60.0 * m - 360.0 / 12.0 * h - 360.0 / 12.0 / 60.0 * m);
    // Calculating the angle C between the hour and minute hands of a clock

    if (C > 180.0) {
        C = 360.0 - C;
    }
    // Adjusting the angle C if it is greater than 180 degrees

    double cosC = cos(C * M_PI / 180.0);
    // Calculating the cosine of angle C in radians

    printf("%.2lf\n", sqrt(a * a + b * b - 2 * a * b * cosC));
    // Printing the length of the line segment connecting the tips of the hour and minute hands using the Law of Cosines

    return 0;
}
// Printing the length of the line segment connecting the tips of the hour and minute hands using the Law of Cosines



Translate the above C code to Java and end with comment "
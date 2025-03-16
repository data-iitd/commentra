#include <stdio.h>
#include <math.h>

int main() {
    int a, b, h, m;
    scanf("%d %d %d %d", &a, &b, &h, &m);

    // Calculate the angle C between hour hand and minute hand
    double C = fabs(360.0 / 60.0 * m - 360.0 / 12.0 * h - 360.0 / 12.0 / 60.0 * m);
    if (C > 180.0) {
        // If angle C is greater than 180 degrees, subtract it from 360 to get the correct value
        C = 360.0 - C;
    }

    // Convert angle C to radians
    double radiansC = C * M_PI / 180.0;

    // Calculate the cosine of angle C
    double cosC = cos(radiansC);

    // Calculate and print the length of the side of the right triangle formed by the hour and minute hands
    double length = sqrt(a * a + b * b - 2 * a * b * cosC);
    printf("%.10f\n", length);

    return 0;
}

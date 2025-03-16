#include <stdio.h>
#include <math.h>

int main() {
    int a, b, h, m;
    scanf("%d %d %d %d", &a, &b, &h, &m);

    // Calculate the angle C between the hour and minute hands of the clock
    double C = fabs(360.0 / 60.0 * m - 360.0 / 12.0 * h - 360.0 / 12.0 / 60.0 * m);

    // If the angle is greater than 180 degrees, find the smaller angle
    if (C > 180.0) {
        C = 360.0 - C;
    }

    // Convert angle C to radians
    double radiansC = C * M_PI / 180.0;

    // Use the Law of Cosines to calculate the length of the third side of the triangle
    double length = sqrt(a * a + b * b - 2 * a * b * cos(radiansC));

    // Print the result
    printf("%.10f\n", length);

    return 0;
}

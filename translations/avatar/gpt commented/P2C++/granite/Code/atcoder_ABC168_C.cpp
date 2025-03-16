
#include <iostream>
#include <cmath>

int main() {
    // Read input values for lengths (a, b) and time (h, m)
    double a, b, h, m;
    std::cin >> a >> b >> h >> m;

    // Calculate the angle C between the hour and minute hands of the clock
    // The formula calculates the absolute difference in degrees
    double C = std::abs(360 / 60 * m - 360 / 12 * h - 360 / 12 / 60 * m);

    // If the angle is greater than 180 degrees, find the smaller angle
    if (C > 180) {
        C = 360 - C;
    }

    // Calculate the cosine of angle C in radians
    double cosC = std::cos(C * M_PI / 180);

    // Use the Law of Cosines to calculate the length of the third side of the triangle
    // formed by the lengths a, b, and the angle C
    std::cout << std::sqrt(a * a + b * b - 2 * a * b * cosC) << std::endl;

    return 0;
}


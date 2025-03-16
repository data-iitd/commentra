
#include <iostream>
#include <cmath>

int main() {
    // Assign values to variables a, b, h, and m using the input function and cin object
    int a, b, h, m;
    std::cin >> a >> b >> h >> m;

    // Calculate the angle C between hour hand and minute hand
    double C = std::abs(360.0 / 60 * m - 360.0 / 12 * h - 360.0 / 12 / 60 * m);
    if (C > 180) {
        // If angle C is greater than 180 degrees, subtract it from 360 to get the correct value
        C = 360 - C;
    }

    // Calculate the cosine of angle C
    double cosC = std::cos(C * M_PI / 180);

    // Calculate and print the length of the side of the right triangle formed by the hour and minute hands
    std::cout << std::sqrt(a * a + b * b - 2 * a * b * cosC) << std::endl;

    return 0;
}


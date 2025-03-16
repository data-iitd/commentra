#include <iostream>
#include <cmath>
#include <cstdlib>

int main() {
    int a, b, h, m;
    std::cin >> a >> b >> h >> m;

    double C = fabs(360.0 / 60 * m - 360.0 / 12 * h - 360.0 / 12 / 60 * m);
    if (C > 180) {
        C = 360 - C;
    }
    
    double cosC = cos(C * M_PI / 180.0);
    std::cout << sqrt(a * a + b * b - 2 * a * b * cosC) << std::endl;

    return 0;
}

// <END-OF-CODE>

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int a, b, h, m;
    cin >> a >> b >> h >> m;

    // Calculating the angle C between the hour and minute hands of a clock
    double C = abs(360.0 / 60 * m - 360.0 / 12 * h - 360.0 / 12 / 60 * m);

    // Adjusting the angle C if it is greater than 180 degrees
    if (C > 180) {
        C = 360 - C;
    }

    // Calculating the cosine of angle C in radians
    double cosC = cos(C * M_PI / 180);

    // Printing the length of the line segment connecting the tips of the hour and minute hands using the Law of Cosines
    cout << fixed << setprecision(10) << sqrt(a * a + b * b - 2 * a * b * cosC) << endl;

    return 0;
}


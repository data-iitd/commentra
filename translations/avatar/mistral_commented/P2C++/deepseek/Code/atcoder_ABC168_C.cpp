#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int main() {
    int a, b, h, m;
    cin >> a >> b >> h >> m;

    // Calculate the angle C between hour hand and minute hand
    double C = abs(360.0 / 60 * m - 360.0 / 12 * h - 360.0 / 12 / 60 * m);
    if (C > 180) {
        // If angle C is greater than 180 degrees, subtract it from 360 to get the correct value
        C = 360 - C;
    }

    // Calculate the cosine of angle C
    double cosC = cos(C * M_PI / 180);

    // Calculate and print the length of the side of the right triangle formed by the hour and minute hands
    double length = sqrt(a * a + b * b - 2 * a * b * cosC);
    cout << length << endl;

    return 0;
}



#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, h, m;
    cin >> a >> b >> h >> m;
    // Taking input values for the lengths of the sides of the triangle and the time

    double C = abs(360.0 / 60 * m - 360.0 / 12 * h - 360.0 / 12 / 60 * m);
    // Calculating the angle C between the hour and minute hands of a clock

    if (C > 180) {
        C = 360 - C;
    }
    // Adjusting the angle C if it is greater than 180 degrees

    double cosC = cos(C * M_PI / 180);
    // Calculating the cosine of angle C in radians

    cout << fixed << setprecision(10) << sqrt(a * a + b * b - 2 * a * b * cosC) << endl;
    // Printing the length of the line segment connecting the tips of the hour and minute hands using the Law of Cosines

    return 0;
}
// Printing the length of the line segment connecting the tips of the hour and minute hands using the Law of Cosines



Translate the above Python code to Java and end with comment "
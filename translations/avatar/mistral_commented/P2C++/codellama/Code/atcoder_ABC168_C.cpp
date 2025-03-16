#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Declare variables a, b, h, and m
    int a, b, h, m;

    // Assign values to variables a, b, h, and m using the input function
    cin >> a >> b >> h >> m;

    // Calculate the angle C between hour hand and minute hand
    double C = abs(360 / 60 * m - 360 / 12 * h - 360 / 12 / 60 * m);
    if (C > 180)
    {
        // If angle C is greater than 180 degrees, subtract it from 360 to get the correct value
        C = 360 - C;
    }

    // Calculate the cosine of angle C
    double cosC = cos(radians(C));

    // Calculate and print the length of the side of the right triangle formed by the hour and minute hands
    cout << sqrt(a * a + b * b - 2 * a * b * cosC) << endl;

    return 0;
}


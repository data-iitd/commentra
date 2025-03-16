#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Include necessary headers
    // This code uses the standard input/output library and the math library for mathematical constants and functions

    double r;
    // Read the input value for the radius of the circle
    cin >> r;

    // Calculate the area of the circle (πr^2) and the circumference (2πr)
    double area = r * r * M_PI;
    double circumference = 2 * M_PI * r;

    // Print the results to the standard output
    cout << area << " " << circumference << endl;
    return 0;
}


#include<iostream>

using namespace std;

int main() {
    // Declare integer variables to hold the input values and results
    int a, b, c, d;

    // Read two integer values from user input
    cin >> a >> b;

    // Calculate the area of a rectangle (length * width)
    c = a * b;

    // Calculate the perimeter of a rectangle (2 * (length + width))
    d = 2 * a + 2 * b;

    // Output the calculated area and perimeter
    cout << c << " " << d << endl;

    // Return 0 to indicate successful completion of the program
    return 0;
}

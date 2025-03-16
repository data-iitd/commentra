#include <iostream>

using namespace std;

int main() {
    // Declare two integer variables to hold the input values
    int a, b;

    // Read two integers from the user input
    cin >> a >> b;

    // Calculate and print the product of a and b, and the perimeter of a rectangle with sides a and b
    cout << a * b << " " << 2 * (a + b) << endl;

    // Return 0 to indicate successful execution of the program
    return 0;
}

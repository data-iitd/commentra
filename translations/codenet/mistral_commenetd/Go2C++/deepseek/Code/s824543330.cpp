#include <iostream>
using namespace std;

int main() {
    // Declare two integer variables, a and b
    int a, b;

    // Read the values of a and b from the standard input
    cin >> a >> b;

    // Check if the product of a and b is even using the modulo operator (%).
    // If the result is zero, it means that a and b are both even or one of them is even and the other is a multiple of 2.
    if ((a * b) % 2 == 0) {
        // If the condition is true, print the message "Even"
        cout << "Even" << endl;
    } else {
        // If the condition is false, print the message "Odd"
        cout << "Odd" << endl;
    }

    return 0;
}


#include <iostream>
using namespace std;

int main() {
    // Declare two integer variables "a" and "b"
    int a, b;

    // Read input values from the standard input using the "cin" function
    cin >> a >> b;

    // Calculate the product of "a" and "b" and store it in a new variable "product"
    int product = a * b;

    // Check if the product is even or odd using an if statement
    if (product % 2 == 0) {
        // If the product is even, print the message "Even" to the standard output
        cout << "Even" << endl;
    } else {
        // If the product is odd, print the message "Odd" to the standard output
        cout << "Odd" << endl;
    }

    return 0;
}


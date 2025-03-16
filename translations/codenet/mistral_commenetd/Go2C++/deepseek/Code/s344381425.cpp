#include <iostream>
using namespace std;

int main() {
    // Declare three integer variables "a", "b", and "c"
    int a, b, c;

    // Read the values of "a", "b", and "c" from the standard input
    cin >> a >> b >> c;

    // Check if the condition "a < b && b < c" is true using an if statement
    if (a < b && b < c) {
        // If the condition is true, print the string "Yes" to the standard output
        cout << "Yes" << endl;
    } else {
        // If the condition is false, print the string "No" to the standard output
        cout << "No" << endl;
    }

    // Return from the main function
    return 0;
}


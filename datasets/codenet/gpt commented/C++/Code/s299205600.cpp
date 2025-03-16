#include <iostream>
#include <string>
using namespace std;

int main() {
    // Declare variables to hold the input values
    int a;
    int b;

    // Read two integer values from the user
    cin >> a;
    cin >> b;

    // Declare a variable to store the result
    int result;

    // Determine the result based on the comparison of a and b
    if (a > b) {
        // If a is greater than b, calculate result as 2 * a - 1
        result = 2 * a - 1;
    } else if (a == b) {
        // If a is equal to b, calculate result as 2 * a
        result = 2 * a;
    } else {
        // If a is less than b, calculate result as 2 * b - 1
        result = 2 * b - 1;
    }

    // Output the result to the console
    cout << result << endl;

    return 0; // Indicate that the program ended successfully
}

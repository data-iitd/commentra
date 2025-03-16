#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a; // Read the first integer input
    cin >> b; // Read the second integer input
    int res = a; // Initialize result variable with the value of a

    // Enter a while loop that continues as long as a is greater than or equal to b
    while (a >= b) {
        res += (a / b); // Update result by adding the integer division of a by b
        a = (a / b) + (a % b); // Update a to be the sum of the integer division and remainder
    }

    cout << res << endl; // Print the final value of res
    return 0;
}

// <END-OF-CODE>

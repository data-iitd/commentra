#include <iostream>
using namespace std;

int main() {
    // Ask the user to input an integer value
    int n;
    cin >> n;

    // Initialize a variable i and set its value to n
    for (int i = n; i > 0; --i) {
        // Check if n is divisible by the current value of i
        if (n % i == 0) {
            // If the condition is true, update the value of n to i
            n = i;
            // Print the current value of i
            cout << i << " ";
        }
    }

    return 0;
}

// <END-OF-CODE>

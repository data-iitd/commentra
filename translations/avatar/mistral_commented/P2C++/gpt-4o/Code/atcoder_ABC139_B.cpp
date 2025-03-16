#include <iostream>
using namespace std;

int main() {
    // Get two integers from user input, separated by a space
    int a, b;
    cin >> a >> b;

    // Initialize the variable 'hole' to 1
    int hole = 1;

    // Initialize the variable 'i' to 0
    int i = 0;

    // Initialize the variable 'check' to true
    bool check = true;

    // Loop until the condition is not met
    while (check) {
        // Check if the value of 'hole' is greater than or equal to 'b'
        if (hole >= b) {
            // If the condition is met, set 'check' to false to terminate the loop
            check = false;
        } else {
            // If the condition is not met, update the value of 'hole'
            hole = a * (i + 1) - i;
            // Increment the value of 'i' by 1
            i++;
        }
    }

    // Once the loop terminates, print out the value of 'i' as the result
    cout << i << endl;

    return 0;
}

// <END-OF-CODE>

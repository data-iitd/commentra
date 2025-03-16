#include <iostream> // Step 1: Include the iostream header for input/output
using namespace std;

int main() {
    int t; // Step 5: Declare a variable to hold the number of test cases
    cin >> t; // Step 4: Read the number of test cases
    int count = 0; // Step 6: Initialize a counter to keep track of the number of times the condition is met

    // Step 7: Use a while loop to iterate through each test case
    while (t-- > 0) {
        int a, b, c; // Step 8: Declare variables to hold the values for each test case
        cin >> a >> b >> c; // Step 8: Read the values of a, b, and c for each test case

        // Step 9: Check if any of the values are 1 or if all three values are 1
        if ((a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1) || (a == 1 && b == 1 && c == 1)) {
            count++; // Step 10: Increment the counter if the condition is met
        }
    }

    // Step 11: Print the counter value after the loop
    cout << count << endl;

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>



#include <iostream> // Step 1: Include the necessary header file for input/output

using namespace std; // Step 2: Use the "std" namespace for the standard library

int main() {
    int t; // Step 3: Declare the variable "t" to store the number of test cases
    cin >> t; // Step 4: Read the number of test cases from the user

    int count = 0; // Step 6: Initialize a counter to keep track of the number of times the condition is met

    // Step 7: Use a while loop to iterate through each test case
    while (t-- > 0) {
        int a, b, c; // Step 8: Declare variables "a", "b", and "c" to store the values of a, b, and c for each test case
        cin >> a >> b >> c; // Step 8: Read the values of a, b, and c for each test case

        // Step 9: Check if any of the values are 1 or if all three values are 1
        if ((a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1) || (a == 1 && b == 1 && c == 1)) {
            count++; // Step 10: Increment the counter if the condition is met
        }
    }

    // Step 11: Print the counter value after the loop
    cout << count << endl; // Step 11: Print the counter value

    return 0; // Step 12: Return 0 to indicate successful execution
}


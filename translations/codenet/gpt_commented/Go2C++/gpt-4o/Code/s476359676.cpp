#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Function to read the next integer from input
int nextInt(istringstream &iss) {
    int i;
    iss >> i; // Read the next integer
    return i; // Return the integer value
}

int main() {
    // Read the entire input into a string
    string input;
    getline(cin, input);
    istringstream iss(input);

    // Read the number of integers to process
    int n = nextInt(iss);

    // Initialize variables for the answer and the previous integer
    int ans = 0;
    int aPrev = 0;

    // Loop through each integer input
    for (int i = 0; i < n; i++) {
        int a = nextInt(iss); // Read the next integer

        // Check conditions based on the current and previous integers
        if (a > i || a > aPrev + 1) { // If the current integer is greater than the index or previous integer + 1
            cout << -1 << endl; // Print -1 and exit if the condition is met
            return 0;
        } else if (a == aPrev + 1) { // If the current integer is exactly one more than the previous integer
            ans++; // Increment the answer
        } else { // For all other cases
            ans += a; // Add the current integer to the answer
        }
        aPrev = a; // Update the previous integer to the current one
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>

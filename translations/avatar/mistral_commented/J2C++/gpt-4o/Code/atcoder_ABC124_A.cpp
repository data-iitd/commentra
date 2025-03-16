#include <iostream>  // Include the iostream library for input and output
using namespace std;  // Use the standard namespace

int main() {  // Entry point of the C++ application
    int a, b;  // Declare two integer variables
    cin >> a >> b;  // Read two integers from standard input

    int sum = 0;  // Initialize sum variable to 0

    for (int i = 0; i < 2; i++) {  // Iterate through two iterations
        if (a >= b) {  // Check if a is greater than or equal to b
            sum += a;  // Add a to sum
            a--;  // Decrement a by 1
        } else {
            sum += b;  // Add b to sum
            b--;  // Decrement b by 1
        }
    }

    cout << sum << endl;  // Print the value of sum to standard output
    return 0;  // Return 0 to indicate successful completion
}

// <END-OF-CODE>

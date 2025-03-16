#include <iostream> // Including the iostream library for input and output
using namespace std;

int main() {
    // Creating variables to hold user input
    int a, b;
    
    // Reading two integers from the user
    cin >> a; // First integer input
    cin >> b; // Second integer input
    
    int sum = 0; // Initializing a variable to hold the sum of selected integers
    
    // Loop to iterate twice to calculate the sum
    for (int i = 0; i < 2; i++) {
        // Check if 'a' is greater than or equal to 'b'
        if (a >= b) {
            sum += a; // Add 'a' to the sum
            a = a - 1; // Decrement 'a' by 1
        } else {
            sum += b; // Add 'b' to the sum
            b = b - 1; // Decrement 'b' by 1
        }
    }
    
    // Output the final sum to the console
    cout << sum << endl;

    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>

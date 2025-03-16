
#include <iostream> // Importing the iostream library for input/output operations

using namespace std; // Using the standard namespace for iostream

int main() {
    int a, b; // Declaring two integer variables 'a' and 'b'
    
    // Reading two integers from the user
    cin >> a >> b;
    
    int sum = 0; // Initializing a variable to hold the sum of selected integers
    
    // Loop to iterate twice to calculate the sum
    for (int i = 0; i < 2; i++) {
        // Check if 'a' is greater than or equal to 'b'
        if (a >= b) {
            sum += a; // Add 'a' to the sum
            a--; // Decrement 'a' by 1
        } else {
            sum += b; // Add 'b' to the sum
            b--; // Decrement 'b' by 1
        }
    }
    
    // Output the final sum to the console
    cout << sum << endl; // Using endl to insert a new line after printing the sum
    
    return 0; // Returning 0 to indicate successful program execution
}


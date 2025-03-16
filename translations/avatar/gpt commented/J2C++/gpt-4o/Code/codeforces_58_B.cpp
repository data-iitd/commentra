#include <iostream> // Including the iostream library for input and output
using namespace std; // Using the standard namespace

int main() {
    // Creating a variable to hold the input number
    int n;
    
    // Reading an integer input from the user
    cin >> n;
    
    // Printing the input number
    cout << n << " " << endl;
    
    // Initializing a variable m to hold the current divisor, starting with n
    int m = n;
    
    // Looping from n-1 down to 1 to find and print all divisors of n
    for (int i = n - 1; i > 0; i--) {
        // Checking if i is a divisor of m
        if (m % i == 0) {
            // Printing the divisor
            cout << i << " " << endl;
            // Updating m to the current divisor
            m = i;
        }
    }
    
    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>

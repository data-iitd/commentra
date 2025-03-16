#include <iostream> // Including the iostream library for input and output
#include <cmath>    // Including the cmath library for mathematical functions

using namespace std; // Using the standard namespace

int main() { // Defining the main function
    int q; // Variable to store the number of test cases
    cin >> q; // Reading the number of test cases from the console

    while (q-- > 0) { // Starting a while loop that runs q times
        int n; // Variable to store the integer 'n'
        cin >> n; // Reading the integer 'n' from the console

        long long s = 0; // Initializing the long long variable 's' with zero value

        int x = (int)(log(n) / log(2)); // Calculating the integer 'x' using the logarithmic formula
        x++; // Incrementing the value of 'x' by 1

        s = -1 * (long long)pow(2, x) + 2 + ((long long)n * (long long)(n + 1)) / 2 - (long long)pow(2, x); // Calculating the value of 's' using the given formula

        cout << s << endl; // Printing the value of 's' to the console
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>

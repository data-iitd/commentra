
// Importing necessary libraries
#include <iostream>
#include <string>
#include <algorithm>

// Main function
int main() {
    // Reading input for number of test cases
    int n;
    std::cin >> n;

    // Reading input for number of operations
    int m;
    std::cin >> m;

    // Calling reverse function for m and adding it to n
    int t = reverse(m);
    std::cout << t + n << std::endl;

    // Returning 0 to indicate successful execution
    return 0;
}

// Function for reversing a number
int reverse(int n) {
    // Base case for numbers less than 10
    if (n < 10)
        return n * 10;

    // Initializing variables
    int t = n, r = 0;

    // Reversing the number
    while (t > 0) {
        // Adding the digit to the reversed number
        r = (r * 10) + t % 10;

        // Moving to the next digit
        t = t / 10;
    }

    // Returning the reversed number
    return r;
}

// End of code

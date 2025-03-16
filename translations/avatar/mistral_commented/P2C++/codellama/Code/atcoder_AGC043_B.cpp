#include <iostream>
#include <cmath>

using namespace std;

// Define a helper function 'twos_in_factorial' to count the number of twos in the factorial of a given number
int twos_in_factorial(int n) {
    // Calculate the number of twos in the factorial of 'n' using the number of '1' bits in the binary representation of 'n'
    return n - __builtin_popcount(n);
}

// Define a helper function 'parity_of_nCr' to check if the index 'i' has odd parity in the combination 'nCr'
bool parity_of_nCr(int n, int i) {
    // Use the 'twos_in_factorial' function to calculate the number of twos in 'n', 'n-i', and 'i'
    int f = twos_in_factorial;
    // Return True if the difference between the number of twos in 'n' and the sum of twos in 'n-i' and 'i' is greater than zero
    return f(n) - f(n - i) - f(i) > 0;
}

// Check if the input is valid and process the given problem
int main() {
    // Read the input values from the standard input
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    // Initialize a flag to indicate if there is no '1' in the list of numbers
    bool no_one = false;
    
    // If there is no '1' in the list of numbers, then replace each number by half of it
    if (no_one = (1 not in nums)) {
        for (int i = 0; i < n; i++) {
            nums[i] /= 2;
        }
    }
    
    // Initialize a flag to indicate if the result is odd
    bool is_odd = false;
    
    // Iterate through each number in the list and check if it satisfies the given condition
    for (int i = 0; i < n; i++) {
        // Skip the number if it doesn't satisfy the parity condition
        if (!parity_of_nCr(n - 1, i) && nums[i] & 1) {
            // Toggle the 'is_odd' flag
            is_odd ^= 1;
        }
    }
    
    // Print the result based on the value of the 'is_odd' flag
    if (!is_odd) {
        cout << 0 << endl;
    } else {
        // If there is no '1' in the list of numbers, then print the result with the 'no_one' flag shifted to the left
        cout << 1 << (no_one << 1) << endl;
    }
    
    return 0;
}


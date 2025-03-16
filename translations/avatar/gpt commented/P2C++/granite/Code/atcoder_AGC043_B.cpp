
#include <iostream>
#include <cmath>

// Function to calculate the number of factors of 2 in n!
int twos_in_factorial(int n) {
    // Calculate the number of factors of 2 in n! by subtracting the count of 1s in the binary representation of n from n
    return n - __builtin_popcount(n);
}

// Function to determine the parity (even or odd) of the binomial coefficient C(n, i)
bool parity_of_nCr(int n, int i) {
    int f = twos_in_factorial;  // Reference to the function that calculates the number of factors of 2
    // The binomial coefficient C(n, i) is odd if the number of factors of 2 in n! is greater than the sum of factors of 2 in (n-i)! and i!
    return f(n) - f(n - i) - f(i) > 0;
}

int main() {
    // Read an integer n from input
    int n;
    std::cin >> n;
    // Read a list of integers, subtracting 1 from each input value
    int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        nums[i]--;
    }

    bool no_one = true;  // Flag to check if there are no '1's in the input list
    for (int i = 0; i < n; i++) {
        if (nums[i]!= 0) {
            no_one = false;  // Set the flag to False since there were '1's
            break;
        }
    }

    bool is_odd = false;  // Flag to track if the overall parity is odd
    for (int i = 0; i < n; i++) {
        // Check the parity of C(n-1, i) and if num is odd
        if (!parity_of_nCr(n - 1, i) && nums[i] % 2 == 1) {
            is_odd =!is_odd;  // Toggle the is_odd flag if the conditions are met
        }
    }

    // Print the result based on the parity
    if (!is_odd) {
        std::cout << 0 << std::endl;  // If the overall parity is even, print 0
    } else {
        std::cout << (1 << no_one) << std::endl;  // If odd, print 1 or 2 based on the no_one flag
    }

    return 0;
}


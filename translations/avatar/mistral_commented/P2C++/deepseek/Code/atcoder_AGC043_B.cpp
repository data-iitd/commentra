#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Function to calculate the number of twos in the factorial of a given number
int twos_in_factorial(int n) {
    // Calculate the number of twos in the factorial of 'n' using the number of '1' bits in the binary representation of 'n'
    return n - __builtin_popcount(n);
}

// Function to check if the index 'i' has odd parity in the combination 'nCr'
bool parity_of_nCr(int n, int i) {
    // Use the 'twos_in_factorial' function to calculate the number of twos in 'n', 'n-i', and 'i'
    int f = twos_in_factorial;
    // Return true if the difference between the number of twos in 'n' and the sum of twos in 'n-i' and 'i' is greater than zero
    return f(n) - f(n - i) - f(i) > 0;
}

int main() {
    // Read the input values from the standard input
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
        --nums[i]; // Adjusting the input to be 0-based index
    }
    
    // Initialize a flag to indicate if there is no '1' in the list of numbers
    bool no_one = false;
    
    // If there is no '1' in the list of numbers, then replace each number by half of it
    if (std::find(nums.begin(), nums.end(), 1) == nums.end()) {
        for (int &num : nums) {
            num /= 2;
        }
        no_one = true;
    }
    
    // Initialize a flag to indicate if the result is odd
    bool is_odd = false;
    
    // Iterate through each number in the list and check if it satisfies the given condition
    for (int i = 0; i < n; ++i) {
        // Skip the number if it doesn't satisfy the parity condition
        if (!parity_of_nCr(n - 1, i) && nums[i] % 2 == 1) {
            // Toggle the 'is_odd' flag
            is_odd = !is_odd;
        }
    }
    
    // Print the result based on the value of the 'is_odd' flag
    if (!is_odd) {
        std::cout << 0 << std::endl;
    } else {
        // If there is no '1' in the list of numbers, then print the result with the 'no_one' flag shifted to the left
        std::cout << (1 << no_one) << std::endl;
    }
    
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int twos_in_factorial(int n) {
    // Calculate the number of factors of 2 in n! by subtracting the count of 1s in the binary representation of n from n
    return n - std::count(std::to_string(n).begin(), std::to_string(n).end(), '1');
}

bool parity_of_nCr(int n, int i) {
    // Determine the parity (even or odd) of the binomial coefficient C(n, i)
    auto f = twos_in_factorial;  // Reference to the function that calculates the number of factors of 2
    // The binomial coefficient C(n, i) is odd if the number of factors of 2 in n! is greater than the sum of factors of 2 in (n-i)! and i!
    return f(n) - f(n - i) - f(i) > 0;
}

int main() {
    // Read an integer n from input
    int n;
    std::cin >> n;
    // Read a list of integers, subtracting 1 from each input value
    std::vector<int> nums;
    std::string input;
    std::cin >> input;
    for (char c : input) {
        nums.push_back(c - '1');
    }

    bool no_one = false;  // Flag to check if there are no '1's in the input list
    if (std::find(nums.begin(), nums.end(), 1) == nums.end()) {
        // If there are no '1's, divide each number in nums by 2
        for (int& num : nums) {
            num /= 2;
        }
        no_one = true;  // Set the flag to True since there were no '1's
    }

    bool is_odd = false;  // Flag to track if the overall parity is odd
    for (int i = 0; i < nums.size(); ++i) {
        // Check the parity of C(n-1, i) and if num is odd
        if (!parity_of_nCr(n - 1, i) && nums[i] & 1) {
            is_odd ^= 1;  // Toggle the is_odd flag if the conditions are met
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

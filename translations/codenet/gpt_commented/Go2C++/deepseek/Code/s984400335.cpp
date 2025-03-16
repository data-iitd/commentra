#include <iostream>
#include <vector>
#include <algorithm> // for std::min

// min function takes a variable number of integer arguments and returns the minimum value among them.
int min(std::vector<int> nums) {
    // Initialize min with the first element of nums
    int min = nums[0];
    // Iterate over each value in nums to find the minimum
    for (int v : nums) {
        // Update min if the current value is less than the current min
        if (v < min) {
            min = v;
        }
    }
    // Return the minimum value found
    return min;
}

int main() {
    // Declare variables to hold input values
    int n, a, b;
    // Read three integers from standard input
    std::cin >> n >> a >> b;

    // Calculate the minimum of n*a and b, and print the result
    std::cout << min({n*a, b}) << std::endl;

    return 0;
}

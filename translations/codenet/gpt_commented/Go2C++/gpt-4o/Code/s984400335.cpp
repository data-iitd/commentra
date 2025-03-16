#include <iostream>
#include <initializer_list>
#include <algorithm>

// min function takes a variable number of integer arguments and returns the minimum value among them.
int min(std::initializer_list<int> nums) {
    // Use std::min_element to find the minimum value in the initializer list
    return *std::min_element(nums.begin(), nums.end());
}

int main() {
    // Declare variables to hold input values
    int n, a, b;
    // Read three integers from standard input
    std::cin >> n >> a >> b;

    // Calculate the minimum of n*a and b, and print the result
    std::cout << min({n * a, b}) << std::endl;

    return 0;
}

// <END-OF-CODE>

#include <iostream>

int main() {
    int n; // Declare an integer variable to store the input value
    std::cin >> n; // Read an input value for `n` from the user
    int ans = 0; // Initialize a variable `ans` to 0 to store the final answer

    // Loop through values of `i` starting from 1
    for (int i = 1; i * i < n; i++) {
        if (n % i == 0 && n % (n / i - 1) == i) { // Check if `i` is a divisor of `n` and if `n/(i-1)` is also a divisor of `n`
            ans += n / i - 1; // Add `n/(i-1) - 1` to `ans` if both conditions are met
        }
    }

    std::cout << ans << std::endl; // Print the value of `ans`
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>

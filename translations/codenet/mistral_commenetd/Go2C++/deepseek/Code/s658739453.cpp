#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdint>

const int64_t d = 1000000007; // Define a constant 'd' as an integer

int main() {
    int n, p;
    std::cin >> n; // Read the first integer 'n' from the standard input
    std::cin >> p; // Read the second integer 'p' from the standard input

    std::unordered_map<int64_t, int64_t> mdans; // Initialize an empty map 'mdans' for storing distinct numbers

    // Read 'p' distinct numbers from the standard input and store them in the map 'mdans'
    for (int index = 0; index < p; index++) {
        int64_t n1;
        std::cin >> n1;
        mdans[n1] = n1; // Store the number 'n1' in the map 'mdans' with its own key
    }

    std::vector<int64_t> dp(n + 1, 0); // Initialize a vector 'dp' of size 'n+1' with a default value of '0'
    dp[0] = 1; // Initialize the first element of the vector 'dp' with a value of '1'
    dp[1] = 1; // Initialize the second element of the vector 'dp' with a value of '1'

    // Initialize the third element of the vector 'dp' with a value of '0' if the number '1' is present in the map 'mdans'
    if (mdans.find(1) != mdans.end()) {
        dp[1] = 0;
    }

    // Calculate the remaining elements of the vector 'dp' using the previous elements
    for (int i = 2; i <= n; i++) {
        if (mdans.find(int64_t(i)) != mdans.end()) {
            continue; // Skip the current iteration if the number 'i' is present in the map 'mdans'
        }
        dp[i] = (dp[i - 1] + dp[i - 2]) % d; // Calculate the current element of the vector 'dp' as the sum of the previous two elements modulo 'd'
    }

    // Print the final result
    std::cout << dp[n] << std::endl; // Print the value of the last element of the vector 'dp'

    return 0;
}

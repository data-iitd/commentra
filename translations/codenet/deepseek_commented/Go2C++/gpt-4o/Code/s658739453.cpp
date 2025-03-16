#include <iostream>
#include <unordered_map>

const int d = 1000000007;

int main() {
    int n, p;
    std::cin >> n; // Read the value of n from standard input
    std::cin >> p; // Read the value of p from standard input

    std::unordered_map<long long, long long> mdans;
    for (int index = 0; index < p; index++) {
        long long n1;
        std::cin >> n1; // Read each value into the map mdans
        mdans[n1] = n1;
    }

    std::vector<long long> dp(n + 1, 0);
    dp[0] = 1; // Initialize the first element of dp vector
    dp[1] = 1; // Initialize the second element of dp vector

    if (mdans.count(1)) { // Check if the value 1 is in the map mdans
        dp[1] = 0; // Set dp[1] to 0 if 1 is in the map
    }

    for (int i = 2; i <= n; i++) {
        if (mdans.count(i)) { // Check if the current value i is in the map mdans
            continue; // Skip to the next iteration if i is in the map
        }
        dp[i] = (dp[i - 1] + dp[i - 2]) % d; // Calculate dp[i] as the sum of dp[i-1] and dp[i-2], modulo d
    }

    std::cout << dp[n] << std::endl; // Print the value at dp[n]
    return 0;
}

// <END-OF-CODE>

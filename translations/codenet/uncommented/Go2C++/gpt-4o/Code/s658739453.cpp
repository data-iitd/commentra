#include <iostream>
#include <unordered_map>

const int d = 1000000007;

int main() {
    int n, p;
    std::cin >> n >> p;

    std::unordered_map<long long, long long> mdans;
    for (int index = 0; index < p; index++) {
        long long n1;
        std::cin >> n1;
        mdans[n1] = n1;
    }

    std::vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    if (mdans.find(1) != mdans.end()) {
        dp[1] = 0;
    }

    for (int i = 2; i <= n; i++) {
        if (mdans.find(i) != mdans.end()) {
            continue;
        }
        dp[i] = (dp[i - 1] + dp[i - 2]) % d;
    }

    std::cout << dp[n] << std::endl;

    return 0;
}

// <END-OF-CODE>

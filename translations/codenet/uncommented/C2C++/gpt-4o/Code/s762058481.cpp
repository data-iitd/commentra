#include <iostream>
#include <vector>
#include <cstdlib> // for abs

int chmin(int a, int b) {
    return (a > b) ? b : a;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> dp(n, 10000);
    std::vector<int> h(n);

    for (int i = 0; i < n; ++i)
        std::cin >> h[i];

    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (i == 1) {
            dp[1] = abs(h[1] - h[0]);
        } else {
            dp[i] = chmin(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
        }
    }
    std::cout << dp[n - 1] << std::endl;
    return 0;
}

// <END-OF-CODE>

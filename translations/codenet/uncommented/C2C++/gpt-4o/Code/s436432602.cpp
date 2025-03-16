#include <iostream>
#include <vector>

void run() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    std::vector<int> dp(k + 1, 0);
    for (int i = 1; i <= k; i++) {
        int win = 0;
        for (int j = 0; j < n && a[j] <= i; j++) {
            if (dp[i - a[j]] == 0) {
                win = 1;
            }
        }
        dp[i] = win;
    }
    std::cout << (dp[k] ? "First" : "Second") << std::endl;
}

int main() {
    run();
    return 0;
}

// <END-OF-CODE>

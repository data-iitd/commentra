#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int H, N, A, B;
    std::cin >> H >> N;
    
    std::vector<int> dp(H + 10001, std::numeric_limits<int>::max());
    for (int l = 1; l < H + 10001; l++) {
        dp[l] = std::numeric_limits<int>::max();
    }
    
    int amax = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> A >> B;
        if (A >= amax) {
            amax = A;
        }
        dp[A] = min(dp[A], B);
        for (int j = A + 1; j <= H + amax + 1; j++) {
            dp[j] = min(dp[j], dp[j - A] + B);
        }
    }
    
    int result = std::numeric_limits<int>::max();
    for (int i = H; i <= H + amax; i++) {
        result = min(result, dp[i]);
    }
    
    std::cout << result << std::endl;
    return 0;
}

// <END-OF-CODE>

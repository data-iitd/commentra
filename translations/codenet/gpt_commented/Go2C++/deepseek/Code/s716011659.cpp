#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arrA(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arrA[i];
    }

    std::vector<int> cumSumA(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cumSumA[i + 1] = cumSumA[i] + arrA[i];
    }

    long long ans = LLONG_MAX;
    for (int i = 1; i < n; ++i) {
        long long diff = std::abs(static_cast<long long>(cumSumA[n]) - 2 * cumSumA[i]);
        if (diff < ans) {
            ans = diff;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}


#include <iostream>
#include <vector>
#include <cmath>

int main() {
    long startTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    const long long div = std::pow(10, 9) + 7;
    std::vector<long long> A(n);
    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> A[i];
    }

    for (int i = 0; i < 60; ++i) {
        long long a = 0;
        long long count1 = 0;

        for (int j = 0; j < n; ++j) {
            if (A[j] & (1LL << i)) {
                ++count1;
            }
        }

        a = a + count1 * (n - count1);

        for (int j = 0; j < i; ++j) {
            a = (a << 1) % div;
        }

        ans += a;
        ans %= div;
    }

    std::cout << ans << '\n';
    long long endTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
}

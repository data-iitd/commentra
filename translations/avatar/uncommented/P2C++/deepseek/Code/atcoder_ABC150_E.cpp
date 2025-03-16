#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::accumulate

int main() {
    const long long mod = 1000000007;
    long long n;
    std::cin >> n;
    std::vector<long long> c(n);
    for (long long i = 0; i < n; ++i) {
        std::cin >> c[i];
    }
    std::sort(c.begin(), c.end(), std::greater<long long>());
    long long b = std::pow(2, 2 * n - 2) % mod;
    long long a = 2 * b % mod;
    long long ans = 0;
    for (long long i = 0; i < n; ++i) {
        ans += c[i] * (a + i * b) % mod;
        ans %= mod;
    }
    std::cout << ans << std::endl;
    return 0;
}

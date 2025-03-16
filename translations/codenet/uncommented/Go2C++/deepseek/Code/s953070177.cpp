#include <iostream>
#include <vector>
#include <cstdlib> // for std::abs

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> aa(n + 2);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> aa[i + 1];
        sum += std::abs(aa[i + 1] - aa[i]);
    }
    sum += std::abs(aa[n + 1] - aa[n]);

    for (int i = 1; i <= n; ++i) {
        int ans = sum - std::abs(aa[i + 1] - aa[i]) - std::abs(aa[i] - aa[i - 1]) + std::abs(aa[i + 1] - aa[i - 1]);
        std::cout << ans << '\n';
    }

    return 0;
}

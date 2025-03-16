#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> r[i];
    }
    int ans = std::abs(r[0]);
    for (int i = 1; i < n; ++i) {
        ans += std::abs(r[i] - r[i - 1]);
    }
    std::cout << ans << std::endl;
    return 0;
}


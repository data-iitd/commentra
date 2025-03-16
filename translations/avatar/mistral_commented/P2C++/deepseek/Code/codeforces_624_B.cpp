#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end(), std::greater<int>());

    long long pre = LLONG_MAX;
    long long ans = 0;

    for (int j = 0; j < n; ++j) {
        ans += std::max(0, std::min(static_cast<long long>(pre) - 1, static_cast<long long>(a[j])));
        pre = std::min(static_cast<long long>(pre) - 1, static_cast<long long>(a[j]));
    }

    std::cout << ans << std::endl;

    return 0;
}

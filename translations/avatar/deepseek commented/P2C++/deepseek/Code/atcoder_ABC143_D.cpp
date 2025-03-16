#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::accumulate

int main() {
    int n;
    std::cin >> n;
    std::vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i];
    }

    std::sort(l.begin(), l.end());

    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int a = l[i];
            int b = l[j];

            auto left = std::lower_bound(l.begin(), l.end(), std::max(a - b, b - a));
            auto right = std::lower_bound(l.begin(), l.end(), a + b);

            int tmp = std::max(0, static_cast<int>(right - left));

            if (left <= l.begin() + i && l.begin() + i < right) {
                --tmp;
            }
            if (left <= l.begin() + j && l.begin() + j < right) {
                --tmp;
            }

            ans += tmp;
        }
    }

    std::cout << ans / 3 << std::endl;

    return 0;
}

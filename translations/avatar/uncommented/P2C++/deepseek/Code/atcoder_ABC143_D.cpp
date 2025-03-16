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
            int right = std::lower_bound(l.begin(), l.end(), a + b) - l.begin();
            int left = std::upper_bound(l.begin(), l.end(), std::max(a - b, b - a)) - l.begin();
            int tmp = std::max(0, right - left);
            if (left <= i && i < right) {
                tmp -= 1;
            }
            if (left <= j && j < right) {
                tmp -= 1;
            }
            ans += tmp;
        }
    }
    std::cout << ans / 3 << std::endl;
    return 0;
}

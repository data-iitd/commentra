#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> b(n, 0);
    for (int i = 0; i < n; ++i) {
        b[a[i] - 1] = i;
    }
    int res = 0;
    for (int i = 1; i < n; ++i) {
        res += std::abs(b[i] - b[i - 1]);
    }
    std::cout << res << std::endl;
    return 0;
}


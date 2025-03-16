#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> b(n);
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> c[i];
    }
    int x = 0, y = 0, z = 0;
    for (int i : a) {
        x += i;
    }
    for (int i : b) {
        y += i;
    }
    for (int i : c) {
        z += i;
    }
    std::cout << std::abs(x - y) << std::endl;
    std::cout << std::abs(y - z) << std::endl;
    return 0;
}


#include <iostream>
#include <vector>
#include <cmath> // for abs function

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

    for (int i = 0; i < n; ++i) {
        x += a[i];
    }
    for (int i = 0; i < n; ++i) {
        y += b[i];
    }
    for (int i = 0; i < n; ++i) {
        z += c[i];
    }

    std::cout << std::abs(x - y) << std::endl;
    std::cout << std::abs(y - z) << std::endl;

    return 0;
}


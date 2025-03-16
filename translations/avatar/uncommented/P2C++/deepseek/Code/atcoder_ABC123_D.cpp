#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int x, y, z, k;
    std::cin >> x >> y >> z >> k;
    std::vector<int> a(x);
    std::vector<int> b(y);
    std::vector<int> c(z);
    for (int i = 0; i < x; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < y; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < z; ++i) {
        std::cin >> c[i];
    }

    std::vector<int> ab;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            ab.push_back(a[i] + b[j]);
        }
    }
    std::sort(ab.begin(), ab.end(), std::greater<int>());

    std::vector<int> abc;
    for (int i = 0; i < std::min(k, static_cast<int>(ab.size())); ++i) {
        for (int j = 0; j < z; ++j) {
            abc.push_back(ab[i] + c[j]);
        }
    }
    std::sort(abc.begin(), abc.end(), std::greater<int>());

    for (int i = 0; i < k; ++i) {
        std::cout << abc[i] << std::endl;
    }

    return 0;
}

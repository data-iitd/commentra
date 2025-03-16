#include <iostream>
#include <vector>
#include <cmath>
#include <list>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::list<std::string> r;
    int m = 0;
    for (int i = 1; i < n; ++i) {
        if (std::abs(a[m]) < std::abs(a[i])) {
            m = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[m] >= 0 ^ a[i] >= 0) {
            r.push_back(std::to_string(m + 1) + " " + std::to_string(i + 1));
        }
    }
    if (a[m] >= 0) {
        for (int i = 1; i < n; ++i) {
            r.push_back(std::to_string(i) + " " + std::to_string(i + 1));
        }
    } else {
        for (int i = n; i > 1; --i) {
            r.push_back(std::to_string(i) + " " + std::to_string(i - 1));
        }
    }
    std::cout << r.size() << std::endl;
    for (const auto& s : r) {
        std::cout << s << std::endl;
    }
    return 0;
}

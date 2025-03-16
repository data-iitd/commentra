#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> b;
    for (int v : a) {
        auto it = std::lower_bound(b.begin(), b.end(), v);
        if (it == b.end()) {
            b.push_back(v);
        } else {
            *it = v;
        }
    }

    std::cout << b.size() << std::endl;


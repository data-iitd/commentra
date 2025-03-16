#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i];
    }

    std::sort(l.begin(), l.end());

    for (int i = 0; i < n; ++i) {
        if (std::find(l.begin(), l.end(), l[i] + 1) != l.end() && std::find(l.begin(), l.end(), l[i] + 2) != l.end()) {
            std::cout << "YES" << std::endl;
            return 0;
        }
    }

    std::cout << "NO" << std::endl;
    return 0;
}


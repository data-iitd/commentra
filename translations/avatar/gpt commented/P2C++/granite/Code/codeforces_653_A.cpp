
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> l(n);
    for (int i = 0; i < n; i++) {
        std::cin >> l[i];
    }

    std::sort(l.begin(), l.end());

    for (int i = 0; i < n; i++) {
        if (std::binary_search(l.begin(), l.end(), l[i] + 1) && std::binary_search(l.begin(), l.end(), l[i] + 2)) {
            std::cout << "YES" << std::endl;
            return 0;
        }
    }

    std::cout << "NO" << std::endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> l1(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> l1[i];
    }

    std::sort(l1.begin(), l1.end());

    int a = l1.back();
    int b = l1.front();

    if (a == b) {
        std::cout << a - b << " " << n * (n - 1) / 2 << std::endl;
    } else {
        int ac = std::count(l1.begin(), l1.end(), a);
        int bc = std::count(l1.begin(), l1.end(), b);
        std::cout << a - b << " " << ac * bc << std::endl;
    }

    return 0;
}


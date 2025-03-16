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

    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (l[i] > c) {
            ++c;
        }
    }

    std::cout << c + 1 << std::endl;

    return 0;
}


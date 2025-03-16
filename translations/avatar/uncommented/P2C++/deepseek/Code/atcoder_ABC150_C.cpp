#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> range(n);
    for (int i = 0; i < n; ++i) {
        range[i] = i + 1;
    }
    std::vector<std::vector<int>> orig;
    std::sort(range.begin(), range.end());
    do {
        orig.push_back(range);
    } while (std::next_permutation(range.begin(), range.end()));

    std::vector<int> p(n);
    std::vector<int> q(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> q[i];
    }

    int pn = -1, qn = -1;
    for (int i = 0; i < orig.size(); ++i) {
        if (orig[i] == p) {
            pn = i;
        }
        if (orig[i] == q) {
            qn = i;
        }
    }

    std::cout << std::abs(pn - qn) << std::endl;
    return 0;
}

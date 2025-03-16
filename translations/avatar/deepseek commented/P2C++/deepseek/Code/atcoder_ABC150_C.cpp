#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums;
    for (int i = 1; i <= n; ++i) {
        nums.push_back(i);
    }
    std::vector<std::vector<int>> orig;
    std::sort(nums.begin(), nums.end());
    do {
        orig.push_back(nums);
    } while (std::next_permutation(nums.begin(), nums.end()));

    std::vector<int> p(n), q(n);
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


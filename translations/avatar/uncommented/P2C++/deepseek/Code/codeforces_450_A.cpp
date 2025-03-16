#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i];
    }
    std::vector<int> l2;
    for (int i : l) {
        if (i % m == 0) {
            l2.push_back(i / m);
        } else {
            l2.push_back(i / m + 1);
        }
    }
    int mx = *std::max_element(l2.begin(), l2.end());
    int ind = 0;
    for (int i = 0; i < n; ++i) {
        if (l2[i] == mx) {
            ind = i;
            break;
        }
    }
    std::cout << ind + 1 << std::endl;
    return 0;
}


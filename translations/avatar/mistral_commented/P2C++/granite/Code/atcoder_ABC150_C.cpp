
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> orig(n);
    for (int i = 0; i < n; i++) {
        orig[i].resize(n);
        for (int j = 0; j < n; j++) {
            orig[i][j] = j + 1;
        }
    }

    std::vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> q[i];
    }

    std::vector<std::vector<int>> temp(orig);
    std::sort(temp.begin(), temp.end());

    int pn = std::distance(temp.begin(), std::find(temp.begin(), temp.end(), p));
    int qn = std::distance(temp.begin(), std::find(temp.begin(), temp.end(), q));

    std::cout << std::abs(pn - qn) << std::endl;

    return 0;
}


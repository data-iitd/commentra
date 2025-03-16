
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
            orig[i][j] = i * n + j + 1;
        }
    }

    std::vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> q[i];
    }

    int pn = 0, qn = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (orig[i] == p) {
                pn = i * n + j;
            }
            if (orig[i] == q) {
                qn = i * n + j;
            }
        }
    }

    std::cout << std::abs(pn - qn) << std::endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 100;

int check(int n, const std::vector<int>& x, const std::vector<int>& y, const std::vector<int>& h, int cx, int cy) {
    int ch = -1;

    for (int i = 0; i < n; ++i) {
        if (h[i] > 0) {
            ch = std::abs(x[i] - cx) + std::abs(y[i] - cy) + h[i];
            break;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (h[i] != std::max(ch - std::abs(x[i] - cx) - std::abs(y[i] - cy), 0)) {
            return -1;
        }
    }

    return ch;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> x(n), y(n), h(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i] >> h[i];
    }

    for (int i = 0; i <= MAX; ++i) {
        for (int j = 0; j <= MAX; ++j) {
            int ch = check(n, x, y, h, i, j);
            if (ch > 0) {
                std::cout << i << " " << j << " " << ch << std::endl;
            }
        }
    }

    return 0;
}


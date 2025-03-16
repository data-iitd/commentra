#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int max_level;
    std::cin >> max_level;

    std::vector<int> x(max_level + 1, 0); // +1 to accommodate 1-based indexing
    std::vector<int> y(max_level + 1, 0); // +1 to accommodate 1-based indexing

    int n, m;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int level;
        std::cin >> level;
        x[level] = 1;
    }

    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int level;
        std::cin >> level;
        y[level] = 1;
    }

    for (int i = 1; i <= max_level; ++i) {
        if (x[i] == 0 && y[i] == 0) {
            std::cout << "Oh, my keyboard!" << std::endl;
            return 0;
        }
    }

    std::cout << "I become the guy." << std::endl;
    return 0;
}

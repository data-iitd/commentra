#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int max_level;
    std::cin >> max_level;

    std::vector<int> x, y;
    int count_x, count_y;

    std::cin >> count_x;
    for (int i = 0; i < count_x; ++i) {
        int level;
        std::cin >> level;
        x.push_back(level);
    }

    std::cin >> count_y;
    for (int i = 0; i < count_y; ++i) {
        int level;
        std::cin >> level;
        y.push_back(level);
    }

    std::set<int> x_set(x.begin(), x.end());
    std::set<int> y_set(y.begin(), y.end());

    if (x_set.find(0) != x_set.end()) {
        x_set.erase(0);
    } else if (y_set.find(0) != y_set.end()) {
        y_set.erase(0);
    }

    std::set<int> z = x_set;
    z.insert(y_set.begin(), y_set.end());

    if (z.size() != max_level) {
        std::cout << "Oh, my keyboard!" << std::endl;
    } else {
        std::cout << "I become the guy." << std::endl;
    }

    return 0;
}

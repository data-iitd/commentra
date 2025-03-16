
#include <iostream>
#include <vector>
#include <set>

int main() {
    int max_level;
    std::cin >> max_level;

    std::vector<int> x(max_level - 1);
    std::vector<int> y(max_level - 1);

    for (int i = 0; i < max_level - 1; i++) {
        std::cin >> x[i];
    }
    for (int i = 0; i < max_level - 1; i++) {
        std::cin >> y[i];
    }

    std::set<int> x_set(x.begin(), x.end());
    std::set<int> y_set(y.begin(), y.end());

    if (x_set.count(0)) {
        x_set.erase(0);
    }
    if (y_set.count(0)) {
        y_set.erase(0);
    }

    std::set<int> z;
    std::set_union(x_set.begin(), x_set.end(), y_set.begin(), y_set.end(), std::inserter(z, z.begin()));

    if (z.size()!= max_level) {
        std::cout << "Oh, my keyboard!" << std::endl;
    } else {
        std::cout << "I become the guy." << std::endl;
    }

    return 0;
}

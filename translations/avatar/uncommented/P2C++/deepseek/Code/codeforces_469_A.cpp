#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int max_level;
    std::cin >> max_level;
    std::vector<int> x, y;
    int temp;

    // Read the first line and populate x
    for (int i = 0; i < 2; ++i) {
        std::cin >> temp;
        for (int j = 0; j < temp; ++j) {
            std::cin >> temp;
            if (i == 0) {
                x.push_back(temp);
            } else {
                y.push_back(temp);
            }
        }
    }

    // Remove the first element which is not needed
    x.erase(x.begin());
    y.erase(y.begin());

    // Convert vectors to sets
    std::set<int> set_x(x.begin(), x.end());
    std::set<int> set_y(y.begin(), y.end());

    // Remove 0 if present in either set
    set_x.erase(0);
    set_y.erase(0);

    // Union of both sets
    std::set<int> z;
    std::set_union(set_x.begin(), set_x.end(), set_y.begin(), set_y.end(), std::inserter(z, z.begin()));

    // Check if the union has the correct number of elements
    if (z.size() != max_level) {
        std::cout << "Oh, my keyboard!" << std::endl;
    } else {
        std::cout << "I become the guy." << std::endl;
    }

    return 0;
}

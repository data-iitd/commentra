#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() {
    int max_level;
    std::cin >> max_level;

    int n;
    std::cin >> n; // Read the number of levels for player 1
    std::set<int> x;
    for (int i = 0; i < n; ++i) {
        int level;
        std::cin >> level;
        x.insert(level);
    }

    int m;
    std::cin >> m; // Read the number of levels for player 2
    std::set<int> y;
    for (int i = 0; i < m; ++i) {
        int level;
        std::cin >> level;
        y.insert(level);
    }

    // Remove 0 if it exists in either set
    x.erase(0);
    y.erase(0);

    // Union of both sets
    std::set<int> z;
    z.insert(x.begin(), x.end());
    z.insert(y.begin(), y.end());

    if (z.size() != max_level) {
        std::cout << "Oh, my keyboard!" << std::endl;
    } else {
        std::cout << "I become the guy." << std::endl;
    }

    return 0;
}

// <END-OF-CODE>

#include <iostream>
#include <vector>

int main() {
    int x, y, a, b;
    std::cin >> x >> y >> a >> b;

    std::vector<std::pair<int, int>> games;

    for (int i = a; i <= x; ++i) {
        if (i <= b) continue;
        for (int j = b; j <= y; ++j) {
            if (i > j) {
                games.push_back(std::make_pair(i, j));
            }
        }
    }

    std::cout << games.size() << std::endl;
    for (const auto& game : games) {
        std::cout << game.first << " " << game.second << std::endl;
    }

    return 0;
}

// <END-OF-CODE>

#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int x, y, a, b;
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    iss >> x >> y >> a >> b;

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

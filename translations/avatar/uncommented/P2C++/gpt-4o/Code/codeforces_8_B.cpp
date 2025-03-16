#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>

int main() {
    std::string record_of_movements;
    std::cin >> record_of_movements;

    int x = 0, y = 0;
    std::unordered_map<char, std::pair<int, int>> d_movement = {
        {'L', {0, -1}},
        {'R', {0, 1}},
        {'U', {1, 0}},
        {'D', {-1, 0}}
    };
    std::unordered_map<std::pair<int, int>, std::string, std::hash<std::pair<int, int>>> d;
    d[{x, y}] = "";
    bool bug = false;

    for (char move : record_of_movements) {
        std::pair<int, int> temp = {x, y};
        x += d_movement[move].first;
        y += d_movement[move].second;

        if (d.find({x, y}) == d.end()) {
            for (const auto& step : d_movement) {
                auto next_pos = std::make_pair(x + step.second.first, y + step.second.second);
                if (next_pos != temp && d.find(next_pos) != d.end()) {
                    bug = true;
                    break;
                }
            }
        } else {
            bug = true;
        }

        if (bug) {
            break;
        }
        d[{x, y}] = "";
    }

    if (bug) {
        std::cout << "BUG" << std::endl;
    } else {
        std::cout << "OK" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>

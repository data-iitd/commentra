#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>

int main() {
    // Initialize an empty dictionary to store the visited positions
    std::string record_of_movements;
    std::cin >> record_of_movements;

    int x = 0, y = 0; // Initialize the starting position of the bug
    // Define a map to store the direction of movement
    std::unordered_map<char, std::pair<int, int>> d_movement = {
        {'L', {0, -1}},
        {'R', {0, 1}},
        {'U', {1, 0}},
        {'D', {-1, 0}}
    };

    // Initialize an empty map to store the visited positions
    std::unordered_map<std::pair<int, int>, std::string, std::hash<std::pair<int, int>>> d;
    d[{x, y}] = ""; // Mark the starting position as visited

    bool bug = false; // Initialize a boolean variable to check if the bug is trapped

    // Iterate through each movement in the record
    for (char move : record_of_movements) {
        // Save the current position of the bug
        std::pair<int, int> temp = {x, y};

        // Move the bug based on the given direction
        x += d_movement[move].first;
        y += d_movement[move].second;

        // Check if the new position is already visited
        if (d.find({x, y}) == d.end()) {
            // If yes, check if there is a loop in the path
            for (const auto& step : d_movement) {
                int new_x = x + step.second.first;
                int new_y = y + step.second.second;
                if (std::make_pair(new_x, new_y) != temp && d.find({new_x, new_y}) != d.end()) {
                    // If a loop is found, set the bug is trapped flag
                    bug = true;
                    break;
                }
            }
        }

        // If the new position is not visited, set it as visited
        d[{x, y}] = "";
    }

    // Check if the bug is trapped
    if (bug) {
        std::cout << "BUG" << std::endl;
    } else {
        std::cout << "OK" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>

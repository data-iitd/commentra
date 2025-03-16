#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>

int main() {
    std::string record_of_movements;
    std::cin >> record_of_movements;  // Take input for the movements of a character

    int x = 0, y = 0;  // Initialize the starting position (x, y) to (0, 0)
    std::unordered_map<char, std::pair<int, int>> d_movement = {
        {'L', {0, -1}}, {'R', {0, 1}}, {'U', {1, 0}}, {'D', {-1, 0}}  // Define a map that maps each direction to its coordinate changes
    };
    std::unordered_map<std::pair<int, int>, std::string, std::hash<std::pair<int, int>>> d;  // Initialize a map to keep track of visited positions
    bool bug = false;  // Set a flag bug to false

    for (char move : record_of_movements) {  // Iterate over each movement in the input
        std::pair<int, int> temp = {x, y};  // Store the current position in a temporary variable
        x += d_movement[move].first;  // Update the x-coordinate based on the direction
        y += d_movement[move].second;  // Update the y-coordinate based on the direction

        if (d.find({x, y}) == d.end()) {  // Check if the new position has been visited before
            for (const auto& step : d_movement) {  // Check the surrounding positions
                if (std::make_pair(x + step.second.first, y + step.second.second) != temp && 
                    d.find({x + step.second.first, y + step.second.second}) != d.end()) {
                    bug = true;  // Set the bug flag to true if a bug is detected
                    break;  // Break out of the loop if a bug is detected
                }
            }
        } else {
            bug = true;  // Set the bug flag to true if the new position has been visited before
        }

        if (bug) {  // Check if a bug was detected
            break;  // Break out of the loop if a bug was detected
        }

        d[{x, y}] = "";  // Add the new position to the map d
    }

    if (bug) {  // Check if a bug was detected
        std::cout << "BUG" << std::endl;  // Print 'BUG' if a bug was detected
    } else {
        std::cout << "OK" << std::endl;  // Print 'OK' if no bug was detected
    }

    return 0;
}

// <END-OF-CODE>



#include <iostream>
#include <string>
#include <map>

int main() {
    std::string record_of_movements;
    std::cin >> record_of_movements;  // Take input for the movements of a character
    int x = 0, y = 0;  // Initialize the starting position (x, y) to (0, 0)
    std::map<std::pair<int, int>, std::string> d;  // Initialize a map to keep track of visited positions
    d[{x, y}] = "";  // Add the starting position to the map d
    bool bug = false;  // Set a flag bug to False

    for (char move : record_of_movements) {  // Iterate over each movement in the input
        std::pair<int, int> temp = {x, y};  // Store the current position in a temporary variable
        if (move == 'L') {
            x--;  // Update the x-coordinate to the left
        } else if (move == 'R') {
            x++;  // Update the x-coordinate to the right
        } else if (move == 'U') {
            y++;  // Update the y-coordinate upwards
        } else if (move == 'D') {
            y--;  // Update the y-coordinate downwards
        }

        if (d.find({x, y}) == d.end()) {  // Check if the new position has been visited before
            for (char step : {'L', 'R', 'U', 'D'}) {  // Check the surrounding positions
                if (step!= move && d.find({x + (step == 'L'? -1 : step == 'R'? 1 : 0), y + (step == 'U'? 1 : step == 'D'? -1 : 0)})!= d.end()) {
                    bug = true;  // Set the bug flag to True if a bug is detected
                    break;  // Break out of the loop if a bug is detected
                }
            }
        } else {
            bug = true;  // Set the bug flag to True if the new position has been visited before
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

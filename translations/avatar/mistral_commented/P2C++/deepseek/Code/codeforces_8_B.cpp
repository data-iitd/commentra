#include <iostream>
#include <unordered_map>
#include <utility>
#include <string>

using namespace std;

int main() {
    string record_of_movements;
    cin >> record_of_movements;

    // Initialize the starting position of the bug
    int x = 0, y = 0;

    // Define a map to store the direction of movement
    unordered_map<char, pair<int, int>> d_movement = {
        {'L', {0, -1}},
        {'R', {0, 1}},
        {'U', {1, 0}},
        {'D', {-1, 0}}
    };

    // Initialize a map to store the visited positions
    unordered_map<pair<int, int>, string> d;
    d[{x, y}] = "";

    // Initialize a boolean variable to check if the bug is trapped
    bool bug = false;

    // Iterate through each movement in the record
    for (char move : record_of_movements) {
        // Save the current position of the bug
        pair<int, int> temp = {x, y};

        // Move the bug based on the given direction
        x += d_movement[move].first;
        y += d_movement[move].second;

        // Check if the new position is already visited
        if (d.find({x, y}) == d.end()) {
            // If yes, check if there is a loop in the path
            for (auto& step : d_movement) {
                if ((x + step.second.first != temp.first || y + step.second.second != temp.second) && d.find({x + step.second.first, y + step.second.second}) != d.end()) {
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
        cout << "BUG" << endl;
    } else {
        cout << "OK" << endl;
    }

    return 0;
}

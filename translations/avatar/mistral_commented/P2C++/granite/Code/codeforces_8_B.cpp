
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string record_of_movements;
    cin >> record_of_movements;
    int x = 0, y = 0; // Initialize the starting position of the bug
    map<pair<int, int>, string> d_movement = { // Define a map to store the direction of movement
        {'L', {0, -1}},
        {'R', {0, 1}},
        {'U', {1, 0}},
        {'D', {-1, 0}}
    };
    map<pair<int, int>, string> d; // Initialize an empty map to store the visited positions
    bool bug = false; // Initialize a boolean variable to check if the bug is trapped

    // Iterate through each movement in the record
    for (char move : record_of_movements) {
        // Save the current position of the bug
        pair<int, int> temp = {x, y};

        // Move the bug based on the given direction
        x += d_movement[move][0];
        y += d_movement[move][1];

        // Check if the new position is already visited
        if (d.find({x, y}) == d.end()) {
            // If yes, check if there is a loop in the path
            for (auto step : d_movement) {
                if (make_pair(x + step.second[0], y + step.second[1])!= temp && d.find(make_pair(x + step.second[0], y + step.second[1]))!= d.end()) {
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

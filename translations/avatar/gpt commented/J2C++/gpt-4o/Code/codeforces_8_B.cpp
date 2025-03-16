#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    // Initialize variables for coordinates and control flags
    int x = 0, y = 0, k = 0, dx, dy;
    bool flag = true;

    // Declare a string for input
    string s;

    // Create a vector to store coordinates
    vector<vector<int>> co(2, vector<int>(101));

    // Read the input string from the user
    cin >> s;

    // Store the initial coordinates (0, 0) in the coordinates array
    co[0][k] = x;
    co[1][k] = y;
    ++k; // Increment the index for the next coordinate

    // Process each character in the input string to update coordinates
    for (char move : s) {
        switch (move) {
            case 'L': // Move left
                --x;
                break;
            case 'R': // Move right
                ++x;
                break;
            case 'U': // Move up
                ++y;
                break;
            case 'D': // Move down
                --y;
                break;
        }
        // Store the updated coordinates in the array
        co[0][k] = x;
        co[1][k] = y;
        ++k; // Increment the index for the next coordinate
    }

    // Check for any bugs in the movement path
    for (int i = 0; i < k - 3; ++i) {
        for (int j = i + 3; j < k; ++j) {
            // Calculate the differences in x and y coordinates
            dx = abs(co[0][i] - co[0][j]);
            dy = abs(co[1][i] - co[1][j]);

            // Check if the two points are too close to each other
            if ((dx <= 1 && dy == 0) || (dy <= 1 && dx == 0)) {
                flag = false; // Set flag to false if a bug is found
                break; // Exit the inner loop
            }
        }
        if (!flag) break; // Exit the outer loop if a bug is found
    }

    // Output the result based on the flag status
    if (flag) 
        cout << "OK" << endl; // No bugs found
    else 
        cout << "BUG" << endl; // Bugs found in the movement path

    return 0;
}

// <END-OF-CODE>

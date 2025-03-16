#include <iostream> // Including iostream for input and output
#include <vector>   // Including vector for dynamic array
#include <string>   // Including string for string manipulation
#include <cmath>    // Including cmath for abs function

using namespace std;

int main() {
    int x = 0, y = 0, k = 0, dx, dy; // Initializing variables for coordinates and loop counters
    bool flag = true; // Flag to check for "BUG" pattern
    string s; // Variable to store the input string
    vector<int> coX(101, 0); // Vector to store x-coordinates
    vector<int> coY(101, 0); // Vector to store y-coordinates

    cin >> s; // Reading the input string
    coX[k] = x; // Storing the initial x-coordinate
    coY[k] = y; // Storing the initial y-coordinate
    ++k; // Incrementing the counter for storing coordinates

    // Updating the positions based on the direction commands
    for (char direction : s) {
        switch (direction) {
            case 'L': --x; break; // Moving left
            case 'R': ++x; break; // Moving right
            case 'U': ++y; break; // Moving up
            case 'D': --y; break; // Moving down
        }
        coX[k] = x; // Storing the updated x-coordinate
        coY[k] = y; // Storing the updated y-coordinate
        ++k; // Incrementing the counter for storing coordinates
    }

    // Checking for "BUG" pattern
    for (int i = 0; i < k - 3; ++i) {
        for (int j = i + 3; j < k; ++j) {
            dx = abs(coX[i] - coX[j]); // Calculating the absolute difference in x-coordinates
            dy = abs(coY[i] - coY[j]); // Calculating the absolute difference in y-coordinates
            if ((dx <= 1 && dy == 0) || (dy <= 1 && dx == 0)) { // Checking if the movement forms a "bug" pattern
                flag = false; // Setting the flag to false if a "bug" pattern is found
                break; // Breaking out of the inner loop
            }
        }
        if (!flag) break; // Breaking out of the outer loop if a "bug" pattern is found
    }

    // Outputting the result
    if (flag) cout << "OK" << endl; // Printing "OK" if no "bug" pattern is found
    else cout << "BUG" << endl; // Printing "BUG" if a "bug" pattern is found

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int Black = 35; // Define a constant for the black color

// Function to count the number of black cells in the grid.
int countBlack(int h, int w, const vector<vector<int>>& m) {
    int count = 0; // Initialize count
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (m[i][j] == Black) {
                count++; // Increment count if the cell is black
            }
        }
    }
    return count; // Return the count of black cells
}

// Function to calculate the number of ways to paint the grid to achieve the target count of black cells.
int solve(int h, int w, int a, const vector<vector<int>>& m) {
    int result = 0; // Initialize result
    for (int i = 0; i < (1 << h); i++) { // Iterate over all possible row paint combinations
        for (int k = 0; k < (1 << w); k++) { // Iterate over all possible column paint combinations
            vector<vector<int>> tmp(h, vector<int>(w)); // Create a temporary grid to simulate painting
            for (int j = 0; j < h; j++) {
                tmp[j] = m[j]; // Copy original grid to temporary grid
            }
            // Paint rows based on the current combination
            for (int j = 0; j < h; j++) {
                if (i & (1 << j)) { // Check if the current row is painted
                    for (int l = 0; l < w; l++) {
                        tmp[j][l] = 1; // Paint the entire row
                    }
                }
            }
            // Paint columns based on the current combination
            for (int j = 0; j < w; j++) {
                if (k & (1 << j)) { // Check if the current column is painted
                    for (int l = 0; l < h; l++) {
                        tmp[l][j] = 1; // Paint the entire column
                    }
                }
            }
            if (countBlack(h, w, tmp) == a) { // Check if the count of black cells matches the target
                result++; // Increment result if it matches
            }
        }
    }
    return result; // Return the total number of valid combinations
}

// Main function to execute the program logic
int main() {
    int h, w, k; // Declare height, width, and target count
    cin >> h >> w >> k; // Read height, width, and target count
    vector<vector<int>> m(h, vector<int>(w)); // Create a 2D vector for the grid
    for (int i = 0; i < h; i++) {
        string s; // String to hold the row input
        cin >> s; // Read the row as a string
        for (int j = 0; j < w; j++) {
            m[i][j] = (int)s[j]; // Convert each character to int and store
        }
    }

    int answer = solve(h, w, k, m); // Solve the problem and get the answer
    cout << answer << endl; // Print the answer
    return 0; // Return success
}

// <END-OF-CODE>

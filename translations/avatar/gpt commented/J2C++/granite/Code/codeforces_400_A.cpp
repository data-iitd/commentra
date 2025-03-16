
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Method to check if a given string can form a solution for a specific column count
bool isSolution(int columnsCount, string x) {
    // Create an array to track if all positions for each column are 'X'
    vector<bool> allXs(columnsCount, true); // Initialize all positions as true (all 'X's)

    // Check each character in the string
    for (int i = 0; i < 12; i++) {
        // If the character is not 'X', mark the corresponding column as false
        if (x[i]!= 'X')
            allXs[i % columnsCount] = false;
    }

    // Check if any column has all 'X's
    for (int i = 0; i < columnsCount; i++)
        if (allXs[i])
            return true; // Return true if a valid solution is found

    return false; // Return false if no valid solution is found
}

int main() {
    // Initialize variables to store the number of possible solutions and the solutions themselves
    int possibleSolutions = 0;
    string solutions = "";

    // Read the number of test cases
    int t;
    cin >> t;

    // Process each test case
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s; // Read the input string

        // Check for various column configurations and append valid solutions
        if (isSolution(12, s)) {
            solutions += " 1x12";
            possibleSolutions++;
        }
        if (isSolution(6, s)) {
            solutions += " 2x6";
            possibleSolutions++;
        }
        if (isSolution(4, s)) {
            solutions += " 3x4";
            possibleSolutions++;
        }
        if (isSolution(3, s)) {
            solutions += " 4x3";
            possibleSolutions++;
        }
        if (isSolution(2, s)) {
            solutions += " 6x2";
            possibleSolutions++;
        }
        if (isSolution(1, s)) {
            solutions += " 12x1";
            possibleSolutions++;
        }
    }

    // Output the number of possible solutions and the solutions themselves
    cout << possibleSolutions << endl;
    cout << solutions << endl;

    return 0;
}


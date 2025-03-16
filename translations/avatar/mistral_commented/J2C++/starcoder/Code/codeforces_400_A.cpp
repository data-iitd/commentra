
#include <bits/stdc++.h>

using namespace std;

// Method to check if a given string represents a valid solution
bool isSolution(int columnsCount, string x) {
    bool allXs[columnsCount]; // Initialize an array to keep track of the presence of 'X' in each column
    fill_n(allXs, columnsCount, true); // Set all columns to have 'X' initially

    // Iterate through the given string and mark the corresponding columns as not having 'X'
    for (int i = 0; i < 12; i++) {
        if (x[i]!= 'X') {
            allXs[i % columnsCount] = false; // Update the corresponding column
        }
    }

    // Check if there is any column having 'X'
    for (int i = 0; i < columnsCount; i++) {
        if (allXs[i]) { // If 'X' is present in this column
            return true; // Return true as this is a valid solution
        }
    }

    return false; // If no column has 'X', then this is not a valid solution
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) { // Iterate through each test case
        int possibleSolutions = 0; // Initialize the counter for the number of valid solutions
        string solutions = ""; // Initialize a string builder to store the valid solutions

        string s;
        cin >> s; // Read the given string

        // Check if the given string represents a valid solution
        if (isSolution(12, s)) {
            solutions += " 1x12"; // Add the solution to the string builder
            possibleSolutions++; // Increment the counter
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

        // Write the output
        cout << possibleSolutions << " "; // Write the number of valid solutions
        cout << solutions << endl; // Write the valid solutions
    }

    return 0;
}


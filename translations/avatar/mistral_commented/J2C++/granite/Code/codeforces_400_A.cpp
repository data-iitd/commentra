

#include <iostream> // Input/output stream objects
#include <string> // String class
#include <vector> // Vector container adaptor
#include <algorithm> // Algorithms

using namespace std;

// Method to check if a given string represents a valid solution
bool isSolution(int columnsCount, string x) {
    vector<bool> allXs(columnsCount, true); // Initialize an array to keep track of the presence of 'X' in each column
    fill(allXs.begin(), allXs.end(), true); // Set all columns to have 'X' initially

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
    int t; // Number of test cases
    cin >> t; // Read the number of test cases

    for (int i = 0; i < t; i++) { // Iterate through each test case
        int possibleSolutions = 0; // Initialize the counter for the number of valid solutions
        string solutions = ""; // Initialize a string to store the valid solutions

        string s; // Given string
        cin >> s;

        // Check if the given string represents a valid solution
        if (isSolution(12, s)) {
            solutions += " 1x12"; // Add the solution to the string
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
        cout << possibleSolutions << " " << solutions << endl; // Write the number of valid solutions and the valid solutions
    }

    return 0; // Return 0 to indicate successful execution
}

These comments should provide a clear understanding of the code logic for each block.
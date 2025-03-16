
#include <iostream> 
#include <string> 
#include <cstring> 

using namespace std; 

// Method to check if a given string can form a solution for a specific column count
bool isSolution(int columnsCount, string x) { 
    // Create an array to track if all positions for each column are 'X'
    bool allXs[columnsCount]; 
    memset(allXs, true, sizeof(allXs)); // Initialize all positions as true (all 'X's)

    // Check each character in the string
    for (int i = 0; i < 12; i++) { 
        // If the character is not 'X', mark the corresponding column as false
        if (x[i] != 'X') 
            allXs[i % columnsCount] = false; 
    }

    // Check if any column has all 'X's
    for (int i = 0; i < columnsCount; i++) 
        if (allXs[i]) 
            return true; // Return true if a valid solution is found

    return false; // Return false if no valid solution is found
} 

int main() { 
    int t; // Number of test cases
    cin >> t; // Read the number of test cases

    // Process each test case
    for (int i = 0; i < t; i++) { 
        int possibleSolutions = 0; // Counter for possible solutions
        string solutions; // To store the solutions
        string s; // Read the input string
        cin >> s; 

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

        // Output the number of possible solutions and the solutions themselves
        cout << possibleSolutions << endl << solutions << endl; 
    } 

    return 0; 
} 


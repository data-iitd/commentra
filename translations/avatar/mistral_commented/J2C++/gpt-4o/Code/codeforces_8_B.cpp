#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for dynamic arrays
#include <string>   // Including the string library for string manipulation
#include <cmath>    // Including the cmath library for mathematical functions

using namespace std; // Using the standard namespace

int main() { // Defining the main function
    int i, j, x = 0, y = 0, k = 0, dx, dy; // Declaring and initializing variables
    bool flag = true; // Declaring and initializing a boolean variable
    string s; // Declaring a string variable
    vector<vector<int>> co(2, vector<int>(101)); // Declaring a 2D vector of size 2 x 101

    cin >> s; // Reading the input string from the console
    co[0][k] = x; co[1][k] = y; // Initializing the first element of the array with x and y values
    ++k; // Incrementing the size of the array

    for (i = 0; i < s.length(); ++i) { // Loop to iterate through each character in the string
        switch (s[i]) { // Switch statement to handle each character based on its value
            case 'L': --x; // Move x to the left
                break;
            case 'R': ++x; // Move x to the right
                break;
            case 'U': ++y; // Move y up
                break;
            case 'D': --y; // Move y down
                break;
        }
        co[0][k] = x; co[1][k] = y; // Updating the current position in the array
        ++k; // Incrementing the size of the array
    }

    for (i = 0; i < k - 3; ++i) { // Outer loop to iterate through all elements except the last three
        for (j = i + 3; j < k; ++j) { // Inner loop to compare the current element with the next three elements
            dx = co[0][i] - co[0][j]; // Calculate the difference in x-coordinates
            dy = co[1][i] - co[1][j]; // Calculate the difference in y-coordinates
            dx = abs(dx); // Making dx positive
            dy = abs(dy); // Making dy positive
            if ((dx <= 1 && dy == 0) || (dy <= 1 && dx == 0)) { // Checking if the difference is within 1 unit in either x or y direction
                flag = false; // Setting the flag to false if a difference of 1 unit is found
                break; // Exiting the inner loop if a difference of 1 unit is found
            }
        }
        if (!flag) break; // Exiting the outer loop if a difference of 1 unit is found in any of the inner loops
    }

    if (flag) cout << "OK" << endl; // Printing "OK" if no difference of 1 unit is found
    else cout << "BUG" << endl; // Printing "BUG" if a difference of 1 unit is found

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>

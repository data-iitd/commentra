
#include <iostream> // Include the necessary header file for input/output operations
#include <string> // Include the necessary header file for string operations

using namespace std; // Using the standard namespace for input/output operations

int main() { // Define the main function
    string s; // Declare a string variable to store the input string
    char ch[100]; // Declare a character array of size 100 to store the characters of the input string
    int co[2][101] = {}; // Declare a 2D integer array of size 2 x 101 to store the coordinates
    int x = 0, y = 0, k = 0, dx, dy; // Declare and initialize variables
    bool flag = true; // Declare and initialize a boolean variable

    getline(cin, s); // Read the input string from the console
    strcpy(ch, s.c_str()); // Copy the input string to the character array

    co[0][k] = x; co[1][k] = y; // Initialize the first element of the array with x and y values
    k++; // Increment the size of the array

    for (int i = 0; i < s.length(); i++) { // Loop to iterate through each character in the string
        switch (ch[i]) { // Switch statement to handle each character based on its value
            case 'L':
                x--; // Move x to the left
                break;
            case 'R':
                x++; // Move x to the right
                break;
            case 'U':
                y++; // Move y up
                break;
            case 'D':
                y--; // Move y down
                break;
        }
        co[0][k] = x; co[1][k] = y; // Update the current position in the array
        k++; // Increment the size of the array
    }

    for (int i = 0; i < k - 3; i++) { // Outer loop to iterate through all elements except the last three
        for (int j = i + 3; j < k; j++) { // Inner loop to compare the current element with the next three elements
            dx = co[0][i] - co[0][j]; // Calculate the difference in x-coordinates
            dy = co[1][i] - co[1][j]; // Calculate the difference in y-coordinates
            if (dx < 0) dx *= (-1); // Making dx positive if it's negative
            if (dy < 0) dy *= (-1); // Making dy positive if it's negative
            if ((dx <= 1 && dy == 0) || (dy <= 1 && dx == 0)) { // Checking if the difference is within 1 unit in either x or y direction
                flag = false; // Setting the flag to false if a difference of 1 unit is found
                break; // Exit the inner loop if a difference of 1 unit is found
            }
        }
        if (!flag) break; // Exit the outer loop if a difference of 1 unit is found in any of the inner loops
    }

    if (flag) cout << "OK" << endl; // Print "OK" if no difference of 1 unit is found
    else cout << "BUG" << endl; // Print "BUG" if a difference of 1 unit is found

    return 0; // Return 0 to indicate successful execution of the program
}


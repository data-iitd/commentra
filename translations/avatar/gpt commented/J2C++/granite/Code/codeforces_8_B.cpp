
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Create a string variable to store the input string
    string s;
    
    // Read the input string from the user
    cin >> s;
    
    // Initialize variables for coordinates and control flags
    int i, j, x = 0, y = 0, k = 0, dx, dy;
    bool flag = true;
    
    // Declare variables for character array
    char ch[100];
    
    // Convert the input string to a character array
    for (i = 0; i < s.length(); ++i) {
        ch[i] = s[i];
    }
    
    // Store the initial coordinates (0, 0) in the coordinates array
    int co[2][101] = {{x}, {y}};
    ++k; // Increment the index for the next coordinate
    
    // Process each character in the input string to update coordinates
    for (i = 0; i < s.length(); ++i) {
        switch (ch[i]) {
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
    for (i = 0; i < k - 3; ++i) {
        for (j = i + 3; j < k; ++j) {
            // Calculate the differences in x and y coordinates
            dx = co[0][i] - co[0][j];
            dy = co[1][i] - co[1][j];
            
            // Make differences positive
            if (dx < 0) dx *= (-1);
            if (dy < 0) dy *= (-1);
            
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

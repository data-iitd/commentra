#include <iostream> 
#include <cmath> 
using namespace std; 

int main() { 
    // Declare variables for input and output
    int H, W, A, B; 
    char grid[100][100]; 
    
    // Read the dimensions of the grid and the parameters A and B
    cin >> H >> W >> A >> B; 
    
    // Check if the grid can accommodate the required number of 0s and 1s
    if (W < 2 * A || H < 2 * B) { 
        cout << -1 << endl; // Print -1 if the grid is too small
        return 0; // Exit the program
    } 
    
    // Generate the grid based on the parameters A and B
    for (int i = 0; i < H; i++) { // Iterate over each row
        for (int j = 0; j < W; j++) { // Iterate over each column
            // Determine whether to write '0' or '1' based on the current position
            if ((i < B && j < A) || (i >= B && j >= A)) 
                grid[i][j] = '0'; // Write '0' for specified conditions
            else 
                grid[i][j] = '1'; // Write '1' otherwise
        } 
    } 
    
    // Print the grid
    for (int i = 0; i < H; i++) { // Iterate over each row
        for (int j = 0; j < W; j++) { // Iterate over each column
            cout << grid[i][j]; // Print the current character
        } 
        cout << endl; // Move to the next line after finishing a row
    } 
    
    return 0; 
} 


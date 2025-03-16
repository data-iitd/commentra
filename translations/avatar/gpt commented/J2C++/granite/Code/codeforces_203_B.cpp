
#include <iostream> // Include the necessary libraries for input/output

using namespace std; // Use the standard namespace for convenience

int main() {
    int N, M; // Declare variables to store the dimensions of the grid and the number of moves
    
    // Read the dimensions of the grid (N) and the number of moves (M)
    cin >> N >> M;
    
    // Initialize a 2D array to keep track of the black cells, with padding to avoid boundary checks
    int black[N + 2][N + 2] = {};
    
    // Loop through each move
    for (int m = 1; m <= M; m++) {
        int x, y; // Declare variables to store the coordinates of the current move
        
        // Read the coordinates of the current move
        cin >> x >> y;
        
        // Increment the count of black cells in the surrounding 3x3 area
        for (int xx = x - 1; xx <= x + 1; xx++) {
            for (int yy = y - 1; yy <= y + 1; yy++) {
                // Increment the count for the current cell
                if (++black[xx][yy] == 9) { // Check if the count reaches 9
                    cout << m << endl; // Print the move number where the condition is met
                    return 0; // Exit the program
                }
            }
        }
    }
    
    // If no cell reached the count of 9 after all moves, print -1
    cout << -1 << endl;
    
    return 0; // Return 0 to indicate successful execution
}

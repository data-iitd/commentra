

#include <iostream> // Include the necessary libraries

using namespace std;

int main() {
    int N, M, x, y; // Declare the necessary variables
    cin >> N >> M; // Read the first two integers input, which are the size of the grid and the number of operations

    // Initialize a 2D array 'black' with dimensions (N+2) x (N+2)
    int black[N + 2][N + 2] = {};

    // Loop through M operations
    for (int m = 1; m <= M; m++) {
        cin >> x >> y; // Read the x-coordinate and y-coordinate of the current operation

        // Increment the elements in the 'black' array within the 3x3 neighborhood of (x, y)
        for (int xx = x - 1; xx <= x + 1; xx++) {
            for (int yy = y - 1; yy <= y + 1; yy++) {
                if (++black[xx][yy] == 9) { // Increment the element and check if it reaches 9
                    cout << m << endl; // Print the current operation number
                    return 0; // Exit the program
                }
            }
        }
    }

    // If no element reaches 9 after all operations, print -1
    cout << "-1" << endl;

    return 0; // End the program
}

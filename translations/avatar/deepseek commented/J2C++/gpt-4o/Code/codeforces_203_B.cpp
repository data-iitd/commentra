#include <iostream> // Include the iostream library for input and output
#include <vector>   // Include the vector library for using vectors

using namespace std;

int main() {
    int N, M;
    cin >> N >> M; // Read the first integer input, which is the size of the grid and the number of operations

    // Initialize a 2D vector 'black' with dimensions (N+2) x (N+2)
    vector<vector<int>> black(N + 2, vector<int>(N + 2, 0));

    // Loop through M operations
    for (int m = 1; m <= M; m++) {
        int x, y;
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

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>

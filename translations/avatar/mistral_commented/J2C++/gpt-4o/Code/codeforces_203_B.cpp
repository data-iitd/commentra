#include <iostream>  // Include the iostream library for input and output
#include <vector>   // Include the vector library for dynamic arrays

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;  // Read the size of the grid and the number of stones

    vector<vector<int>> black(N + 2, vector<int>(N + 2, 0));  // Create a 2D vector of size (N+2) x (N+2) initialized to 0

    for (int m = 1; m <= M; m++) {  // Iterate M times for each stone
        int x, y;
        cin >> x >> y;  // Read the coordinates of the stone

        for (int xx = x - 1; xx <= x + 1; xx++) {  // Iterate over neighboring cells in the x-direction
            for (int yy = y - 1; yy <= y + 1; yy++) {  // Iterate over neighboring cells in the y-direction
                if (++black[xx][yy] == 9) {  // Check if the number of black cells around this cell becomes 9
                    cout << m << endl;  // Print the index of the stone that caused this condition
                    return 0;  // Exit the program
                }
            }
        }
    }

    cout << "-1" << endl;  // If no stone caused 9 black neighbors, print -1
    return 0;  // Exit the program
}

// <END-OF-CODE>

#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the number of unique paths in a grid
void kansu(int a, int b);

int main() {
    int a, b; // Declare variables a and b to store user input

    cout << "Enter the dimensions of the grid (width and height): ";
    cin >> a >> b; // Read user input for grid dimensions

    // Loop until user enters valid dimensions (non-zero)
    while (a != 0 && b != 0) {
        kansu(a, b); // Call function kansu to calculate unique paths
        cout << "Enter the dimensions of the next grid (width and height): ";
        cin >> a >> b; // Read user input for next grid dimensions
    }

    return 0;
}

void kansu(int a, int b) {
    int x, y, n; // Declare variables x, y, and n
    vector<vector<int>> suu(a + 1, vector<int>(b + 1, 0)); // 2D vector to store unique paths
    vector<vector<int>> kouji(a + 1, vector<int>(b + 1, 0)); // 2D vector to mark visited cells

    cout << "Enter the number of obstacles in the grid: ";
    cin >> n; // Read user input for number of obstacles

    // Read user input for obstacle positions and mark them in kouji
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        kouji[x][y] = 1;
    }

    // Initialize first row and column of suu with ones
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (kouji[i][j] == 1) {
                suu[i][j] = 0; // Set suu[i][j] to zero if cell is an obstacle
            } else {
                if (i == 1 && j == 1) {
                    suu[i][j] = 1; // Set suu[i][j] to one if it's the starting cell
                } else {
                    if (i == 1) {
                        suu[i][j] = suu[i][j - 1]; // Set suu[i][j] to the value of suu[i][j-1]
                    } else if (j == 1) {
                        suu[i][j] = suu[i - 1][j]; // Set suu[i][j] to the value of suu[i-1][j]
                    } else {
                        suu[i][j] = suu[i][j - 1] + suu[i - 1][j]; // Set suu[i][j] to the sum of suu[i][j-1] and suu[i-1][j]
                    }
                }
            }
        }
    }

    // Print the result (unique paths)
    cout << "The number of unique paths in the grid is: " << suu[a][b] << endl;
}

// <END-OF-CODE>

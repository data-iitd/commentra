#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // Read the height (H) and width (W) of the grid
    int H, W;
    cin >> H >> W;

    // Initialize a 2D character vector to store the grid
    vector<vector<char>> A(H, vector<char>(W));

    // Initialize a queue to perform BFS (Breadth-First Search)
    queue<tuple<int, int, int>> q;

    // Read the grid input and populate the character vector
    for (int i = 0; i < H; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < W; j++) {
            A[i][j] = row[j];

            // If the current cell is a wall ('#'), add its position to the queue
            if (A[i][j] == '#') {
                q.push(make_tuple(i, j, 0)); // Store the position and initial depth
            }
        }
    }

    // Initialize a flag vector to track visited cells
    vector<vector<int>> flag(H, vector<int>(W, 0));

    // Variable to store the maximum depth reached
    int ans = 0;

    // Direction vectors for moving up, down, left, and right
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    // Perform BFS until the queue is empty
    while (!q.empty()) {
        auto [y, x, depth] = q.front(); // Remove the front element from the queue
        q.pop(); // Pop the front element

        // Explore all four possible directions
        for (int i = 0; i < 4; i++) {
            // Calculate new coordinates
            int newY = y + dy[i];
            int newX = x + dx[i];

            // Check if the new coordinates are within bounds
            if (0 <= newY && newY < H && 0 <= newX && newX < W) {
                // Check if the cell has not been visited and is an empty space ('.')
                if (flag[newY][newX] == 0 && A[newY][newX] == '.') {
                    flag[newY][newX] = 1; // Mark the cell as visited
                    q.push(make_tuple(newY, newX, depth + 1)); // Add the new position to the queue
                    ans = depth + 1; // Update the maximum depth reached
                }
            }
        }
    }

    // Output the maximum depth reached
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>

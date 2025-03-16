#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W; // Step 1: Reading the height and width of the grid
    
    vector<vector<char>> A(H, vector<char>(W)); // Step 2: Initialize the grid A
    queue<tuple<int, int, int>> q; // Initialize the queue for BFS
    
    // Step 3: Read the grid row by row and initialize the queue with positions of '#' characters
    for (int i = 0; i < H; i++) {
        string row;
        cin >> row; // Reading the next line which represents a row in the grid
        for (int j = 0; j < W; j++) {
            A[i][j] = row[j]; // Storing the character in the grid
            if (A[i][j] == '#') { // If the character is '#'
                q.push(make_tuple(i, j, 0)); // Add the starting point to the queue
            }
        }
    }
    
    // Step 4: Initialize a flag array to keep track of visited cells
    vector<vector<int>> flag(H, vector<int>(W, 0));
    int ans = 0; // Variable to store the maximum distance
    
    // Directions for moving in the grid (right, left, down, up)
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    // Step 5: Perform BFS to find the maximum distance from any '#' to a '.'
    while (!q.empty()) {
        auto [y, x, depth] = q.front(); // Remove the first element from the queue
        q.pop(); // Pop the front element
        
        // Check all four possible directions
        for (int i = 0; i < 4; i++) {
            int newY = y + dy[i];
            int newX = x + dx[i];
            if (0 <= newY && newY < H && 0 <= newX && newX < W) {
                if (flag[newY][newX] == 0 && A[newY][newX] == '.') {
                    flag[newY][newX] = 1; // Mark the cell as visited
                    q.push(make_tuple(newY, newX, depth + 1)); // Add the new position to the queue
                    ans = depth + 1; // Update the maximum distance
                }
            }
        }
    }
    
    // Step 6: Output the maximum distance found
    cout << ans << endl;
    
    return 0;
}

// <END-OF-CODE>

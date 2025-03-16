#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read the height (H) and width (W) of the grid
    int H, W;
    cin >> H >> W;
    
    // Initialize a 2D character array to store the grid
    char A[H][W];
    
    // Read the grid input and populate the character array
    for (int i = 0; i < H; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < W; j++) {
            A[i][j] = row[j];
        }
    }
    
    // Initialize a queue to perform BFS (Breadth-First Search)
    queue<int> queue;
    
    // Initialize a flag array to track visited cells
    int flag[H][W];
    
    // Variable to store the maximum depth reached
    int ans = 0;
    
    // Direction vectors for moving up, down, left, and right
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    // Perform BFS until the queue is empty
    while (!queue.empty()) {
        int y = queue.front() / W;
        int x = queue.front() % W;
        queue.pop();
        
        // Explore all four possible directions
        for (int i = 0; i < 4; i++) {
            // Calculate new coordinates
            int newY = y + dy[i];
            int newX = x + dx[i];
            
            // Check if the new coordinates are within bounds
            if (0 <= newY && newY <= H - 1 && 0 <= newX && newX <= W - 1) {
                // Check if the cell has not been visited and is an empty space ('.')
                if (flag[newY][newX] == 0 && A[newY][newX] == '.') {
                    flag[newY][newX] = 1; // Mark the cell as visited
                    queue.push(newY * W + newX); // Add the new position to the queue
                    ans = max(ans, flag[newY][newX]); // Update the maximum depth reached
                }
            }
        }
    }
    
    // Output the maximum depth reached
    cout << ans << endl;
}


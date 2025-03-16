#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    int H, W; // Height and width of the grid
    cin >> H >> W; // Reading the height and width of the grid
    
    char A[H][W]; // Initializing the grid A
    queue<int[]> queue; // Initializing the queue for BFS
    
    // Reading the grid row by row and initializing the queue with positions of '#' characters
    for (int i = 0; i < H; i++) {
        string row; // Reading the next line which represents a row in the grid
        cin >> row;
        for (int j = 0; j < W; j++) {
            A[i][j] = row[j]; // Storing the character in the grid
            if (A[i][j] == '#') { // If the character is '#'
                int[] start = {i, j, 0}; // Create a starting point array
                queue.push(start); // Add the starting point to the queue
            }
        }
    }
    
    // Initializing a flag array to keep track of visited cells
    int flag[H][W];
    int ans = 0; // Variable to store the maximum distance
    
    // Directions for moving in the grid (right, left, down, up)
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    // Perform BFS to find the maximum distance from any '#' to a '.'
    while (!queue.empty()) {
        int temp[] = queue.front(); // Remove the first element from the queue
        queue.pop();
        int y = temp[0]; // Current y-coordinate
        int x = temp[1]; // Current x-coordinate
        int depth = temp[2]; // Current depth of the BFS
        
        // Check all four possible directions
        for (int i = 0; i < 4; i++) {
            if (0 <= y + dy[i] && y + dy[i] <= H - 1 && 0 <= x + dx[i] && x + dx[i] <= W - 1) {
                if (flag[y + dy[i]][x + dx[i]] == 0 && A[y + dy[i]][x + dx[i]] == '.') {
                    flag[y + dy[i]][x + dx[i]] = 1; // Mark the cell as visited
                    int queue_add[] = {y + dy[i], x + dx[i], depth + 1}; // Create a new position to add to the queue
                    queue.push(queue_add); // Add the new position to the queue
                    ans = depth + 1; // Update the maximum distance
                }
            }
        }
    }
    
    // Output the maximum distance found
    cout << ans << endl;
    
    return 0;
}


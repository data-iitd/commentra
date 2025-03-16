
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 1000

int main() {
    int H, W;
    scanf("%d %d", &H, &W); // Step 1: Read the height and width of the grid
    
    char A[MAX_SIZE][MAX_SIZE]; // Step 2: Initialize the grid A
    int queue[MAX_SIZE * MAX_SIZE][3]; // Initialize the queue for BFS
    int front = 0, rear = 0; // Variables to keep track of the front and rear of the queue
    
    // Step 3: Read the grid row by row and initialize the queue with positions of '#' characters
    for (int i = 0; i < H; i++) {
        scanf("%s", A[i]); // Read the next line which represents a row in the grid
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#') { // If the character is '#'
                queue[rear][0] = i; // Create a starting point array
                queue[rear][1] = j;
                queue[rear][2] = 0;
                rear++; // Increment the rear of the queue
            }
        }
    }
    
    // Step 4: Initialize a flag array to keep track of visited cells
    bool flag[MAX_SIZE][MAX_SIZE];
    memset(flag, false, sizeof(flag));
    int ans = 0; // Variable to store the maximum distance
    
    // Directions for moving in the grid (right, left, down, up)
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    // Step 5: Perform BFS to find the maximum distance from any '#' to a '.'
    while (front < rear) {
        int y = queue[front][0]; // Current y-coordinate
        int x = queue[front][1]; // Current x-coordinate
        int depth = queue[front][2]; // Current depth of the BFS
        
        // Check all four possible directions
        for (int i = 0; i < 4; i++) {
            if (0 <= y + dy[i] && y + dy[i] < H && 0 <= x + dx[i] && x + dx[i] < W) {
                if (!flag[y + dy[i]][x + dx[i]] && A[y + dy[i]][x + dx[i]] == '.') {
                    flag[y + dy[i]][x + dx[i]] = true; // Mark the cell as visited
                    queue[rear][0] = y + dy[i]; // Create a new position to add to the queue
                    queue[rear][1] = x + dx[i];
                    queue[rear][2] = depth + 1; // Update the depth
                    rear++; // Increment the rear of the queue
                    ans = depth + 1; // Update the maximum distance
                }
            }
        }
        front++; // Increment the front of the queue
    }
    
    // Step 6: Output the maximum distance found
    printf("%d\n", ans);
    
    return 0;
}

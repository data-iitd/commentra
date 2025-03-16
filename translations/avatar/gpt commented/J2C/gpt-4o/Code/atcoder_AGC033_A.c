#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int y;
    int x;
    int depth;
} Node;

int main() {
    // Read the height (H) and width (W) of the grid
    int H, W;
    scanf("%d %d", &H, &W);
    
    // Initialize a 2D character array to store the grid
    char A[MAX_SIZE][MAX_SIZE];
    
    // Initialize a queue for BFS
    Node queue[MAX_SIZE * MAX_SIZE];
    int front = 0, rear = 0;
    
    // Read the grid input and populate the character array
    for (int i = 0; i < H; i++) {
        scanf("%s", A[i]);
        for (int j = 0; j < W; j++) {
            // If the current cell is a wall ('#'), add its position to the queue
            if (A[i][j] == '#') {
                Node start = {i, j, 0}; // Store the position and initial depth
                queue[rear++] = start; // Add the starting position to the queue
            }
        }
    }
    
    // Initialize a flag array to track visited cells
    int flag[MAX_SIZE][MAX_SIZE] = {0};
    
    // Variable to store the maximum depth reached
    int ans = 0;
    
    // Direction vectors for moving up, down, left, and right
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    // Perform BFS until the queue is empty
    while (front < rear) {
        Node temp = queue[front++]; // Remove the front element from the queue
        int y = temp.y; // Current y-coordinate
        int x = temp.x; // Current x-coordinate
        int depth = temp.depth; // Current depth
        
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
                    Node queue_add = {newY, newX, depth + 1}; // Prepare the new position and updated depth
                    queue[rear++] = queue_add; // Add the new position to the queue
                    ans = depth + 1; // Update the maximum depth reached
                }
            }
        }
    }
    
    // Output the maximum depth reached
    printf("%d\n", ans);
    
    return 0;
}

// <END-OF-CODE>

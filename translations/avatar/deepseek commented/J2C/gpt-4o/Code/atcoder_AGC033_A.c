#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 // Define a maximum size for the grid

typedef struct {
    int y, x, depth;
} Node; // Structure to hold the position and depth for BFS

int main() {
    int H, W;
    scanf("%d %d", &H, &W); // Reading the height and width of the grid

    char A[MAX_SIZE][MAX_SIZE]; // Initialize the grid A
    Node queue[MAX_SIZE * MAX_SIZE]; // Queue for BFS
    int front = 0, rear = 0; // Queue pointers
    int flag[MAX_SIZE][MAX_SIZE] = {0}; // Flag array to keep track of visited cells
    int ans = 0; // Variable to store the maximum distance

    // Step 3: Read the grid row by row and initialize the queue with positions of '#' characters
    for (int i = 0; i < H; i++) {
        scanf("%s", A[i]); // Reading the next line which represents a row in the grid
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#') { // If the character is '#'
                Node start = {i, j, 0}; // Create a starting point
                queue[rear++] = start; // Add the starting point to the queue
            }
        }
    }

    // Directions for moving in the grid (right, left, down, up)
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    // Step 5: Perform BFS to find the maximum distance from any '#' to a '.'
    while (front < rear) {
        Node temp = queue[front++]; // Remove the first element from the queue
        int y = temp.y; // Current y-coordinate
        int x = temp.x; // Current x-coordinate
        int depth = temp.depth; // Current depth of the BFS

        // Check all four possible directions
        for (int i = 0; i < 4; i++) {
            int newY = y + dy[i];
            int newX = x + dx[i];
            if (newY >= 0 && newY < H && newX >= 0 && newX < W) {
                if (flag[newY][newX] == 0 && A[newY][newX] == '.') {
                    flag[newY][newX] = 1; // Mark the cell as visited
                    Node queue_add = {newY, newX, depth + 1}; // Create a new position to add to the queue
                    queue[rear++] = queue_add; // Add the new position to the queue
                    ans = depth + 1; // Update the maximum distance
                }
            }
        }
    }

    // Step 6: Output the maximum distance found
    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 // Define a maximum size for the grid

// Define a structure for the queue
typedef struct {
    int y;
    int x;
    int depth;
} QueueNode;

// Function to create a new queue node
QueueNode createNode(int y, int x, int depth) {
    QueueNode node;
    node.y = y;
    node.x = x;
    node.depth = depth;
    return node;
}

// Function to check if the position is within the grid bounds
int isValid(int y, int x, int H, int W) {
    return (y >= 0 && y < H && x >= 0 && x < W);
}

int main() {
    int H, W;
    scanf("%d %d", &H, &W);

    char A[MAX_SIZE][MAX_SIZE]; // 2D array to store the grid
    int flag[MAX_SIZE][MAX_SIZE] = {0}; // 2D array to mark visited cells
    QueueNode queue[MAX_SIZE * MAX_SIZE]; // Queue for BFS
    int front = 0, rear = 0; // Queue pointers

    // Read the grid and initialize the queue with the starting points of '#'
    for (int i = 0; i < H; i++) {
        scanf("%s", A[i]);
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#') {
                queue[rear++] = createNode(i, j, 0); // Add starting point to the queue
            }
        }
    }

    // Initialize variables for the answer and the directions
    int ans = 0;
    int dx[] = {1, -1, 0, 0}; // Direction arrays for x
    int dy[] = {0, 0, 1, -1}; // Direction arrays for y

    // Process the queue and find the answer
    while (front < rear) {
        QueueNode temp = queue[front++]; // Dequeue the front element
        int y = temp.y;
        int x = temp.x;
        int depth = temp.depth;

        // Process the neighboring cells
        for (int i = 0; i < 4; i++) {
            int newY = y + dy[i];
            int newX = x + dx[i];

            // If the cell is within the grid and hasn't been visited yet,
            // and contains a '.', mark it as visited and add it to the queue
            if (isValid(newY, newX, H, W) && flag[newY][newX] == 0 && A[newY][newX] == '.') {
                flag[newY][newX] = 1; // Mark as visited
                queue[rear++] = createNode(newY, newX, depth + 1); // Enqueue the new cell
                ans = (depth + 1 > ans) ? (depth + 1) : ans; // Update the answer
            }
        }
    }

    // Print the answer
    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>

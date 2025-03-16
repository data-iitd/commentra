#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_H 1000
#define MAX_W 1000

int main() {
    int H, W; // Height and width of the grid
    char A[MAX_H][MAX_W]; // Grid A
    int flag[MAX_H][MAX_W]; // Flag array to keep track of visited cells
    int ans = 0; // Variable to store the maximum distance
    
    // Directions for moving in the grid (right, left, down, up)
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    // Step 1: Initialize the Scanner object to read input
    scanf("%d %d", &H, &W);
    
    // Step 2: Read the grid row by row and initialize the queue with positions of '#' characters
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf(" %c", &A[i][j]);
            if (A[i][j] == '#') {
                int queue_add[] = {i, j, 0};
                queue.add(queue_add);
            }
        }
    }
    
    // Step 3: Initialize the queue for BFS
    Queue<int[]> queue = new ArrayDeque<>();
    
    // Step 4: Perform BFS to find the maximum distance from any '#' to a '.'
    while (!queue.isEmpty()) {
        int[] temp = queue.remove();
        int y = temp[0];
        int x = temp[1];
        int depth = temp[2];
        
        // Check all four possible directions
        for (int i = 0; i < 4; i++) {
            if (0 <= y + dy[i] && y + dy[i] <= H - 1 && 0 <= x + dx[i] && x + dx[i] <= W - 1) {
                if (flag[y + dy[i]][x + dx[i]] == 0 && A[y + dy[i]][x + dx[i]] == '.') {
                    flag[y + dy[i]][x + dx[i]] = 1;
                    int queue_add[] = {y + dy[i], x + dx[i], depth + 1};
                    queue.add(queue_add);
                    ans = depth + 1;
                }
            }
        }
    }
    
    // Step 5: Output the maximum distance found
    printf("%d\n", ans);
    
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
<<<<<<< HEAD
#include <stdbool.h>
#include <limits.h>

#define ll long long
#define INF 1e9
=======
#include <limits.h>

#define ll long long
#define INF 1000000000
>>>>>>> 98c87cb78a (data updated)
#define MAX_H 19
#define MAX_W 15

// Global variables for the problem
int ans = INF; // Variable to store the minimum number of moves
<<<<<<< HEAD
int h = MAX_H, w = MAX_W; // Dimensions of the grid
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}; // Direction vectors for x-axis
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1}; // Direction vectors for y-axis
char s[MAX_H][MAX_W + 1]; // 2D grid representation (with +1 for null terminator)
=======
int h = 19, w = 15; // Dimensions of the grid
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}; // Direction vectors for x-axis
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1}; // Direction vectors for y-axis
char s[MAX_H][MAX_W + 1]; // 2D grid representation
>>>>>>> 98c87cb78a (data updated)

// Function to compute the Greatest Common Divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0) return a; // Base case: if b is 0, return a
    return gcd(b, a % b); // Recursive call to find GCD
}

// Function to compute the Least Common Multiple (LCM) of two numbers
int lcm(int a, int b) {
    return a / gcd(a, b) * b; // LCM formula using GCD
}

// Depth-First Search (DFS) function to explore the grid
void dfs(int x, int y, int cnt) {
    // Base case: if the count exceeds 20, stop the search
    if (cnt > 20) return;

    // Check if the bottom row is reached
    if (x == h - 1) {
<<<<<<< HEAD
        ans = (cnt < ans) ? cnt : ans; // Update the answer with the minimum moves
=======
        if (cnt < ans) ans = cnt; // Update the answer with the minimum moves
>>>>>>> 98c87cb78a (data updated)
        return;
    }

    // Explore all 8 possible directions
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i]; // New x-coordinate
        int ny = y + dy[i]; // New y-coordinate
        // Check if the new coordinates are within bounds
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        // Check if the current cell is not blocked
        if (s[nx][ny] != 'X') continue;

<<<<<<< HEAD
        bool c = true; // Flag to control the loop
=======
        int c = 1; // Flag to control the loop
>>>>>>> 98c87cb78a (data updated)
        // Move in the current direction while possible
        while (c && s[nx][ny] == 'X') {
            s[nx][ny] = '.'; // Mark the cell as visited
            nx += dx[i]; // Move to the next cell in the direction
            ny += dy[i];
            // Check if the new coordinates are out of bounds
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
<<<<<<< HEAD
                ans = (cnt + 1 < ans) ? (cnt + 1) : ans; // Update answer if out of bounds
                c = false; // Stop the loop
=======
                if (nx >= h) ans = (cnt + 1 < ans) ? cnt + 1 : ans; // Update answer if out of bounds
                c = 0; // Stop the loop
>>>>>>> 98c87cb78a (data updated)
            }
        }
        // Recursive DFS call for the new position
        if (c) dfs(nx, ny, cnt + 1);
        // Backtrack: restore the grid to its previous state
        while (nx != x || ny != y) {
            nx -= dx[i];
            ny -= dy[i];
            s[nx][ny] = 'X'; // Restore the cell
        }
        s[x][y] = '.'; // Mark the original cell as visited
    }
}

// Main function
int main(void) {
    // Input the grid
    for (int i = 0; i < h; i++) {
        scanf("%s", s[i]);
    }
    int sx, sy; // Starting coordinates
    // Find the starting position 'O' and mark it as visited
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == 'O') {
                sx = i, sy = j; // Store the starting position
                s[i][j] = '.'; // Mark the starting position as visited
            }
        }
    }
    // Start DFS from the initial position
    dfs(sx, sy, 0);
    // Output the result: minimum moves or -1 if not reachable
    if (ans == INF) printf("-1\n");
<<<<<<< HEAD
    else printf("%d\n", ans);

=======
    else printf("%lld\n", ans);
    
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>

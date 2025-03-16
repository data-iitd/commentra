#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ll long long
#define INF 1e9

// Global variables
int ans = INF;
int h = 19, w = 15;
char s[19][15]; // 2D array to store the grid
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

// Function to find the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function to find the least common multiple of two numbers
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

// Function to perform a depth-first search from a given position
// with a given number of steps
void dfs(int x, int y, int cnt) {
    // Base case: if the number of steps is greater than 20, return
    if (cnt > 20) return;

    // Check if the current position is the last row of the grid
    if (x == h - 1) {
        // Update the answer if the current number of steps is less than the previous answer
        ans = (cnt < ans) ? cnt : ans;
        return;
    }

    // Iterate through all the possible directions
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // Check if the next position is out of the grid
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

        // Check if the next position contains an 'X'
        if (s[nx][ny] != 'X') continue;

        // Perform a depth-first search from the next position with one more step
        bool c = true;
        while (c && s[nx][ny] == 'X') {
            s[nx][ny] = '.';
            nx += dx[i];
            ny += dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                if (nx >= h) ans = (cnt + 1 < ans) ? cnt + 1 : ans;
                c = false;
            }
        }

        // If the loop did not exit due to an out-of-grid position, perform the depth-first search
        if (c) dfs(nx, ny, cnt + 1);

        // Backtrack by restoring the previous state of the grid
        while (nx != x || ny != y) {
            nx -= dx[i];
            ny -= dy[i];
            s[nx][ny] = 'X';
        }

        // Restore the current position of the 'O'
        s[x][y] = '.';
    }
}

// Main function
int main(void) {
    // Initialize the 2D array to store the grid
    for (int i = 0; i < h; i++) {
        scanf("%s", s[i]);
    }

    // Find the position of the 'O'
    int sx, sy;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == 'O') {
                sx = i;
                sy = j;
                s[i][j] = '.';
            }
        }
    }

    // Perform a depth-first search from the position of the 'O' with 0 steps
    dfs(sx, sy, 0);

    // Print the answer if it is not equal to INF
    if (ans == INF) printf("-1\n");
    else printf("%lld\n", ans);

    return 0;
}

// <END-OF-CODE>

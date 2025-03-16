#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

typedef long long ll;

// Define the matrix and DP arrays
int mat[3000][3000];
ll dp[3000][3000][4];
ll dpl[3000];

int main(int argc, char **argv)
{
    int rr, cc, k;

    // Read input values for rows, columns, and number of non-zero elements
    scanf("%d %d %d", &rr, &cc, &k);

    // Read each non-zero element's row, column, and value, and store in the matrix
    for (int i = 1; i <= k; i++) {
        int r, c, v;
        scanf("%d %d %d", &r, &c, &v);
        mat[r - 1][c - 1] = v;
    }

    // Initialize the DP table for the starting cell
    dp[0][0][1] = mat[0][0];

    // Fill the DP table
    for (int y = 0; y < rr; y++) {
        for (int x = 0; x < cc; x++) {
            for (int c = 0; c < 4; c++) {
                int v = mat[y][x];
                ll q;
                // Update the DP table based on the current cell's value and previous values
                if (c == 0 || v == 0) {
                    q = (x == 0)? dpl[x] : std::max(dpl[x], dp[y][x - 1][c]);
                } else {
                    q = (x == 0)? dpl[x] + v : std::max(dpl[x] + v, std::max(dp[y][x - 1][c], dp[y][x - 1][c - 1] + v));
                }
                dp[y][x][c] = q;
            }
        }
        // Update the maximum values for each column after processing the current row
        for (int x = 0; x < cc; x++) {
            dpl[x] = std::max(std::max(dp[y][x][0], dp[y][x][1]), std::max(dp[y][x][2], dp[y][x][3]));
        }
    }

    // Output the maximum value in the last column of the last row
    printf("%lld\n", dpl[cc - 1]);
    return 0;
}


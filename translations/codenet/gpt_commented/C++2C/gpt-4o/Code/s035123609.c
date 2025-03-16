#include <stdio.h>

typedef long long ll;

// Declare a matrix to store values
int mat[3000][3000];

// Declare a 3D dynamic programming array
ll dp[3000][3000][4];
// Declare a 1D array to store maximum values for each column
ll dpl[3000];

int main(int argc, char **argv)
{
    int rr, cc, k;

    // Read the number of rows (rr), columns (cc), and the number of values (k)
    scanf("%d %d %d", &rr, &cc, &k);

    // Input the values into the matrix
    for (int i = 1; i <= k; i++) {
        int r, c, v;
        scanf("%d %d %d", &r, &c, &v);
        // Store the value in the matrix (adjusting for 0-based indexing)
        mat[r - 1][c - 1] = v;
    }

    // Initialize the dynamic programming array with the value at the starting position
    dp[0][0][1] = mat[0][0];

    // Iterate through each cell in the matrix
    for (int y = 0; y < rr; y++) {
        for (int x = 0; x < cc; x++) {
            // Iterate through the four possible states (c)
            for (int c = 0; c < 4; c++) {
                int v = mat[y][x]; // Get the current cell value
                ll q; // Variable to store the computed maximum value

                // Check if we are at the first column or if the current value is zero
                if (c == 0 || v == 0) {
                    // If at the first column, take the value from dpl, else take the maximum from previous states
                    q = (x == 0) ? dpl[x] : (dpl[x] > dp[y][x - 1][c] ? dpl[x] : dp[y][x - 1][c]);
                } else {
                    // If not at the first column, calculate the maximum considering the current value
                    q = (x == 0) ? dpl[x] + v : (dpl[x] + v > dp[y][x - 1][c] ? (dpl[x] + v > dp[y][x - 1][c - 1] + v ? dpl[x] + v : dp[y][x - 1][c - 1] + v) : (dp[y][x - 1][c] > dp[y][x - 1][c - 1] + v ? dp[y][x - 1][c] : dp[y][x - 1][c - 1] + v));
                }
                // Store the computed maximum value in the dp array
                dp[y][x][c] = q;
            }
        }
        // Update the dpl array with the maximum values from the current row
        for (int x = 0; x < cc; x++) {
            dpl[x] = dp[y][x][0];
            if (dp[y][x][1] > dpl[x]) dpl[x] = dp[y][x][1];
            if (dp[y][x][2] > dpl[x]) dpl[x] = dp[y][x][2];
            if (dp[y][x][3] > dpl[x]) dpl[x] = dp[y][x][3];
        }
    }

    // Output the maximum value found in the last column
    printf("%lld\n", dpl[cc - 1]);

    return 0;
}

// <END-OF-CODE>

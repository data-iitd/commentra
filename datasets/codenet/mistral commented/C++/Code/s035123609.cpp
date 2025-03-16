
#include <iostream>

typedef long long ll;

int mat[3000][3000]; // 2D matrix to store the given grid data

ll dp[3000][3000][4]; // 3D dp array to store the maximum sum of submatrices with different conditions
ll dpl[3000]; // 1D array to store the maximum sum of submatrices ending at the current column

int main(int argc, char **argv)
{
    int rr, cc, k; // rr: number of rows, cc: number of columns, k: number of given values

    std::cin >> rr >> cc >> k; // reading input dimensions and number of given values

    for (int i = 1; i <= k; i++) { // reading given values and updating the matrix
        int r, c, v;
        std::cin >> r >> c >> v;
        mat[r - 1][c - 1] = v;
    }

    dp[0][0][1] = mat[0][0]; // base case for a 1x1 submatrix

    for (int y = 0; y < rr; y++) { // iterating through each row
        for (int x = 0; x < cc; x++) { // iterating through each column
            for (int c = 0; c < 4; c++) { // iterating through all conditions (top, left, diagonal, and bottom-left)
                int v = mat[y][x]; // current cell value
                ll q;
                if (c == 0 || v == 0) { // if the current condition is top or the cell value is zero
                    q = (x == 0) ? dpl[x] : std::max(dpl[x], dp[y][x - 1][c]); // the maximum sum of submatrices ending at the current column or the maximum sum of submatrices ending at the previous column with the same condition
                } else { // if the current condition is left, diagonal, or bottom-left
                    q = (x == 0) ? dpl[x] + v : std::max(dpl[x] + v, std::max(dp[y][x - 1][c], dp[y][x - 1][c - 1] + v)); // the maximum sum of submatrices ending at the current column or the maximum sum of submatrices with the same conditions at the previous cell and the current cell
                }
                dp[y][x][c] = q; // updating the dp array with the maximum sum of submatrices with the current condition
            }
        }
        for (int x = 0; x < cc; x++) { // updating the dpl array with the maximum sum of submatrices ending at the current column
            dpl[x] = std::max(std::max(dp[y][x][0], dp[y][x][1]), std::max(dp[y][x][2], dp[y][x][3]));
        }
    }

    std::cout << dpl[cc - 1] << std::endl; // printing the maximum sum of submatrix ending at the last column
    return 0;
}
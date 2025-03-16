
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int rr = sc.nextInt(); // number of rows
        int cc = sc.nextInt(); // number of columns
        int k = sc.nextInt(); // number of given values
        int[][] mat = new int[rr][cc]; // 2D matrix to store the given grid data
        long[][][] dp = new long[rr][cc][4]; // 3D dp array to store the maximum sum of submatrices with different conditions
        long[] dpl = new long[cc]; // 1D array to store the maximum sum of submatrices ending at the current column
        for (int i = 0; i < k; i++) { // reading given values and updating the matrix
            int r = sc.nextInt();
            int c = sc.nextInt();
            int v = sc.nextInt();
            mat[r - 1][c - 1] = v;
        }
        dp[0][0][1] = mat[0][0]; // base case for a 1x1 submatrix
        for (int y = 0; y < rr; y++) { // iterating through each row
            for (int x = 0; x < cc; x++) { // iterating through each column
                for (int c = 0; c < 4; c++) { // iterating through all conditions (top, left, diagonal, and bottom-left)
                    int v = mat[y][x]; // current cell value
                    long q;
                    if (c == 0 || v == 0) { // if the current condition is top or the cell value is zero
                        q = (x == 0) ? dpl[x] : Math.max(dpl[x], dp[y][x - 1][c]); // the maximum sum of submatrices ending at the current column or the maximum sum of submatrices ending at the previous column with the same condition
                    } else { // if the current condition is left, diagonal, or bottom-left
                        q = (x == 0) ? dpl[x] + v : Math.max(dpl[x] + v, Math.max(dp[y][x - 1][c], dp[y][x - 1][c - 1] + v)); // the maximum sum of submatrices ending at the current column or the maximum sum of submatrices with the same conditions at the previous cell and the current cell
                    }
                    dp[y][x][c] = q; // updating the dp array with the maximum sum of submatrices with the current condition
                }
            }
            for (int x = 0; x < cc; x++) { // updating the dpl array with the maximum sum of submatrices ending at the current column
                dpl[x] = Math.max(Math.max(dp[y][x][0], dp[y][x][1]), Math.max(dp[y][x][2], dp[y][x][3]));
            }
        }
        System.out.println(dpl[cc - 1]); // printing the maximum sum of submatrix ending at the last column
    }
}


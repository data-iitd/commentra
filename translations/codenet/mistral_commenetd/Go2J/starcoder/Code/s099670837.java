
package main;

import java.util.Scanner;

public class Main {

    // Global variables
    static int n, ans;
    static int[][] a = new int[2][101];

    // Recursive function to find the maximum sum of a sub-matrix
    static void findAns(int i, int j, int sum) {
        // Base case: if we have reached the last cell and the sum is greater than the current answer, update the answer
        if (i == 1 && j == n - 1) {
            ans = sum + a[i][j];
            return;
        }
        // Base case: if we have reached the first row, recursively call the function for the next cell and add the current cell value to the sum
        if (i == 0) {
            findAns(i + 1, j, sum + a[i][j]);
            return;
        }
        // Recursively call the function for the next cell and add the current cell value to the sum
        if (j + 1 < n) {
            findAns(i, j + 1, sum + a[i][j]);
            return;
        }
    }

    // Main function
    public static void main(String[] args) {
        // Read the number of rows and columns from the standard input
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        // Read the elements of the matrix from the standard input
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = sc.nextInt();
            }
        }

        // Call the recursive function to find the maximum sum of a sub-matrix
        findAns(0, 0, 0);

        // Print the maximum sum of a sub-matrix
        System.out.println(ans);
    }

}


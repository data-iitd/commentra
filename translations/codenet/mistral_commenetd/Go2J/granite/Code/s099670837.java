

import java.util.Scanner;

public class s099670837{

    // Variables declaration
    static int n, ans;
    static final int arraySize = 101;

    // 2D array declaration and initialization
    static int[][] a = new int[arraySize][arraySize];

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

    // s099670837 function
    public static void main(String[] args) {
        // Create a Scanner object to read input from the standard input
        Scanner scanner = new Scanner(System.in);

        // Read the number of rows and columns from the standard input
        n = scanner.nextInt();

        // Read the elements of the matrix from the standard input
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = scanner.nextInt();
            }
        }

        // Call the recursive function to find the maximum sum of a sub-matrix
        findAns(0, 0, 0);

        // Print the maximum sum of a sub-matrix
        System.out.println(ans);

        // Close the Scanner object
        scanner.close();
    }
}

// End of the code
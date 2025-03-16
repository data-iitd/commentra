
import java.util.Scanner;

public class Main {
    // Method to rotate a square matrix by a given number of positions clockwise
    public static void rotate(int[][] matrix, int r) {
        int left = 0; // Initialize left index
        int up = 0; // Initialize top index
        int m = matrix.length; // Number of rows in the matrix
        int n = matrix[0].length; // Number of columns in the matrix

        // Rotate the matrix as long as both dimensions are greater than zero
        while (m >= 1 && n >= 1) {
            int count = 2 * (m + n) - 4; // Calculate the total number of elements to be shifted

            int[] tmp = new int[count]; // Create a temporary array to store the elements
            int curr = 0; // Initialize index to store the temporary array

            // Copy the first row to the temporary array
            for (int i = 0; i < n; i++) {
                tmp[curr] = matrix[up][left + i];
                curr++;
            }

            // Copy the last column to the temporary array
            for (int i = 1; i < m - 1; i++) {
                tmp[curr] = matrix[up + i][left + n - 1];
                curr++;
            }

            // Copy the last row to the temporary array, except the last element
            for (int i = n - 1; i >= 0; i--) {
                tmp[curr] = matrix[up + m - 1][left + i];
                curr++;
            }

            // Copy the first column to the temporary array, except the first element
            for (int i = m - 2; i >= 1; i--) {
                tmp[curr] = matrix[up + i][left];
                curr++;
            }

            // Update the matrix using the temporary array
            curr = r % count; // Calculate the index to start updating the matrix
            if (curr < 0) {
                curr += count; // Handle negative index
            }
            for (int i = 0; i < n; i++) {
                matrix[up][left + i] = tmp[curr]; // Update the first row
                curr++;
                if (curr >= count) {
                    curr -= count; // Handle index out of bounds
                }
            }
            for (int i = 1; i < m - 1; i++) {
                matrix[up + i][left + n - 1] = tmp[curr]; // Update the last column
                curr++;
                if (curr >= count) {
                    curr -= count; // Handle index out of bounds
                }
            }
            for (int i = n - 1; i >= 0; i--) {
                matrix[up + m - 1][left + i] = tmp[curr]; // Update the last row
                curr++;
                if (curr >= count) {
                    curr -= count; // Handle index out of bounds
                }
            }
            for (int i = m - 2; i >= 1; i--) {
                matrix[up + i][left] = tmp[curr]; // Update the first column
                curr++;
                if (curr >= count) {
                    curr -= count; // Handle index out of bounds
                }
            }

            // Decrease the size of the matrix and move to the next position
            m -= 2;
            n -= 2;
            left++;
            up++;
        }
    }

    // Main method to read input and call the rotate method
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int rows = sc.nextInt(); // Read the number of rows
        int cols = sc.nextInt(); // Read the number of columns
        int[][] matrix = new int[rows][cols]; // Create a 2D array to store the matrix elements

        // Read the matrix elements
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }

        int rotations = sc.nextInt(); // Read the number of rotations
        rotate(matrix, rotations); // Call the rotate method to rotate the matrix

        // Print the rotated matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }

        sc.close(); // Close the scanner
    }
}


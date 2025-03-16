
import java.util.Scanner;
public class Main {
    public static void rotate(int[][] matrix, int r) {
        // Initialize the starting indices for the current layer
        int left = 0;
        int up = 0;
        // Get the number of rows and columns in the matrix
        int m = matrix.length;
        int n = matrix[0].length;
        // Continue rotating layers until the matrix is fully rotated
        while (m >= 1 && n >= 1) {
            // Calculate the number of elements in the current layer
            int count = 2 * (m + n) - 4;
            // Create a temporary array to store the elements of the current layer
            int[] tmp = new int[count];
            // Initialize the current index in the temporary array
            int curr = 0;
            // Store the elements of the top row in the temporary array
            for (int i = 0; i < n; i++) {
                tmp[curr] = matrix[up][left + i];
                curr++;
            }
            // Store the elements of the right column in the temporary array
            for (int i = 1; i < m - 1; i++) {
                tmp[curr] = matrix[up + i][left + n - 1];
                curr++;
            }
            // Store the elements of the bottom row in the temporary array
            for (int i = n - 1; i >= 0; i--) {
                tmp[curr] = matrix[up + m - 1][left + i];
                curr++;
            }
            // Store the elements of the left column in the temporary array
            for (int i = m - 2; i >= 1; i--) {
                tmp[curr] = matrix[up + i][left];
                curr++;
            }
            // Calculate the effective number of rotations for the current layer
            curr = r % count;
            if (curr < 0) {
                curr += count;
            }
            // Rotate the elements in the current layer by shifting them to the right
            for (int i = 0; i < n; i++) {
                matrix[up][left + i] = tmp[curr];
                curr++;
                if (curr >= count) {
                    curr -= count;
                }
            }
            for (int i = 1; i < m - 1; i++) {
                matrix[up + i][left + n - 1] = tmp[curr];
                curr++;
                if (curr >= count) {
                    curr -= count;
                }
            }
            for (int i = n - 1; i >= 0; i--) {
                matrix[up + m - 1][left + i] = tmp[curr];
                curr++;
                if (curr >= count) {
                    curr -= count;
                }
            }
            for (int i = m - 2; i >= 1; i--) {
                matrix[up + i][left] = tmp[curr];
                curr++;
                if (curr >= count) {
                    curr -= count;
                }
            }
            // Update the indices to move to the next inner layer
            m -= 2;
            n -= 2;
            left++;
            up++;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Read the number of rows and columns in the matrix
        int rows = sc.nextInt();
        int cols = sc.nextInt();
        // Create the matrix and read its elements
        int[][] matrix = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }
        // Read the number of rotations
        int rotations = sc.nextInt();
        // Rotate the matrix and print the result
        rotate(matrix, rotations);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}
import java.util.Scanner;

public class Main {
    // Method to rotate the matrix in layers
    public static void rotate(int[][] matrix, int r) {
        // Initialize boundaries for the current layer
        int left = 0;
        int up = 0;
        int m = matrix.length; // Number of rows
        int n = matrix[0].length; // Number of columns

        // Continue processing while there are layers left to rotate
        while (m >= 1 && n >= 1) {
            // Calculate the number of elements in the current layer
            int count = 2 * (m + n) - 4;
            int[] tmp = new int[count]; // Temporary array to hold the layer elements
            int curr = 0;

            // Extract the top row of the current layer
            for (int i = 0; i < n; i++) {
                tmp[curr] = matrix[up][left + i];
                curr++;
            }
            // Extract the right column of the current layer
            for (int i = 1; i < m - 1; i++) {
                tmp[curr] = matrix[up + i][left + n - 1];
                curr++;
            }
            // Extract the bottom row of the current layer
            for (int i = n - 1; i >= 0; i--) {
                tmp[curr] = matrix[up + m - 1][left + i];
                curr++;
            }
            // Extract the left column of the current layer
            for (int i = m - 2; i >= 1; i--) {
                tmp[curr] = matrix[up + i][left];
                curr++;
            }

            // Calculate the effective number of rotations needed
            curr = r % count;
            if (curr < 0) {
                curr += count; // Adjust for negative rotations
            }

            // Place the rotated elements back into the top row
            for (int i = 0; i < n; i++) {
                matrix[up][left + i] = tmp[curr];
                curr++;
                if (curr >= count) {
                    curr -= count; // Wrap around if needed
                }
            }
            // Place the rotated elements back into the right column
            for (int i = 1; i < m - 1; i++) {
                matrix[up + i][left + n - 1] = tmp[curr];
                curr++;
                if (curr >= count) {
                    curr -= count; // Wrap around if needed
                }
            }
            // Place the rotated elements back into the bottom row
            for (int i = n - 1; i >= 0; i--) {
                matrix[up + m - 1][left + i] = tmp[curr];
                curr++;
                if (curr >= count) {
                    curr -= count; // Wrap around if needed
                }
            }
            // Place the rotated elements back into the left column
            for (int i = m - 2; i >= 1; i--) {
                matrix[up + i][left] = tmp[curr];
                curr++;
                if (curr >= count) {
                    curr -= count; // Wrap around if needed
                }
            }

            // Move to the next inner layer
            m -= 2; // Decrease the number of rows for the next layer
            n -= 2; // Decrease the number of columns for the next layer
            left++; // Move the left boundary inward
            up++; // Move the upper boundary inward
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the dimensions of the matrix
        int rows = sc.nextInt();
        int cols = sc.nextInt();
        int[][] matrix = new int[rows][cols];

        // Read the matrix elements from input
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }

        // Read the number of rotations to perform
        int rotations = sc.nextInt();
        
        // Call the rotate method to perform the rotations
        rotate(matrix, rotations);
        
        // Print the rotated matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println(); // New line after each row
        }
        
        // Close the scanner to prevent resource leaks
        sc.close();
    }
}


import java.util.Scanner;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Create a Scanner object to read input from the user

        int n = scanner.nextInt();
        // Read the size of the matrix from the user

        double[][] matrix = new double[n][n];
        // Create a double 2D array of size n x n to store the matrix elements

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = scanner.nextDouble();
                // Read the elements of the matrix from the user
            }
        }
        // Fill the matrix with the input values

        double[][] inverse = invert(matrix);
        // Call the invert method to find the inverse of the matrix

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.printf("%.6f ", inverse[i][j]);
                // Print the elements of the inverse matrix with 6 decimal places
            }
            System.out.println();
            // Move to the next row and print a newline after each row
        }
        scanner.close();
        // Close the Scanner object to free up system resources
    }

    public static double[][] invert(double[][] a) {
        int n = a.length;
        // Get the size of the matrix from its 2D array representation

        double[][] x = new double[n][n];
        // Create a double 2D array of size n x n to store the inverse matrix elements

        double[][] b = new double[n][n];
        // Create a double 2D array of size n x n to store the intermediate values

        int[] index = new int[n];
        // Create an integer array to store the row indices for swapping rows during the Gauss-Jordan elimination process

        for (int i = 0; i < n; ++i) {
            b[i][i] = 1;
            // Set the diagonal elements of the b matrix to 1
        }

        gaussian(a, index);
        // Call the gaussian method to perform the Gauss-Jordan elimination process

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    b[index[j]][k] -= a[index[j]][i] * b[index[i]][k];
                    // Eliminate the elements below the diagonal by subtracting the product of the corresponding elements above the diagonal and the elements in the same column from the elements below the diagonal
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            x[n - 1][i] = b[index[n - 1]][i] / a[index[n - 1]][n - 1];
            // Find the last column of the inverse matrix by dividing the last row of the b matrix by the determinant of the last column of the a matrix

            for (int j = n - 2; j >= 0; --j) {
                x[j][i] = b[index[j]][i];
                // Find the other elements of the inverse matrix by copying the elements from the b matrix

                for (int k = j + 1; k < n; ++k) {
                    x[j][i] -= a[index[j]][k] * x[k][i];
                    // Eliminate the elements above the diagonal by subtracting the product of the corresponding elements above the diagonal and the elements in the same column from the elements above the diagonal
                }

                x[j][i] /= a[index[j]][j];
                // Divide the elements above the diagonal by the corresponding diagonal elements to find the inverse matrix elements
            }
        }

        return x;
        // Return the inverse matrix as a 2D array
    }

    private static void gaussian(double[][] a, int[] index) {
        int n = index.length;
        // Get the size of the matrix from its 2D array representation and the number of rows

        double[] c = new double[n];
        // Create an array to store the absolute values of the diagonal elements for row swapping

        for (int i = 0; i < n; ++i) {
            index[i] = i;
            // Initialize the row indices for swapping
        }

        for (int i = 0; i < n; ++i) {
            double c1 = 0;
            for (int j = 0; j < n; ++j) {
                double c0 = Math.abs(a[i][j]);
                if (c0 > c1) {
                    c1 = c0;
                    // Find the maximum absolute value of the diagonal elements and store its index
                }
            }
            c[i] = c1;
            // Store the maximum absolute value of the diagonal elements
        }

        for (int j = 0; j < n - 1; ++j) {
            double pi1 = 0;
            int k = j;
            for (int i = j; i < n; ++i) {
                double pi0 = Math.abs(a[index[i]][j]) / c[index[i]];
                if (pi0 > pi1) {
                    pi1 = pi0;
                    k = i;
                    // Find the row with the maximum absolute value of the diagonal element and swap its index with the current index
                }
            }
            int temp = index[j];
            index[j] = index[k];
            index[k] = temp;
            // Swap the rows

            for (int i = j + 1; i < n; ++i) {
                double pj = a[index[i]][j] / a[index[j]][j];
                a[index[i]][j] = pj;
                // Divide the elements below the diagonal by the corresponding diagonal elements to eliminate the elements below the diagonal

                for (int l = j + 1; l < n; ++l) {
                    a[index[i]][l] -= pj * a[index[j]][l];
                    // Eliminate the elements below the diagonal by subtracting the product of the corresponding elements above the diagonal and the elements in the same column from the elements below the diagonal
                }
            }
        }
    }
}
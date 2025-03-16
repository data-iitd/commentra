import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read the size of the matrix (n x n)
        int n = scanner.nextInt();
        
        // Initialize a 2D array to hold the matrix values
        double[][] matrix = new double[n][n];
        
        // Read the matrix values from user input
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = scanner.nextDouble();
            }
        }
        
        // Compute the inverse of the matrix
        double[][] inverse = invert(matrix);
        
        // Print the inverse matrix with six decimal places
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.printf("%.6f ", inverse[i][j]);
            }
            System.out.println();
        }
        
        // Close the scanner to free resources
        scanner.close();
    }

    // Method to compute the inverse of a matrix using Gaussian elimination
    public static double[][] invert(double[][] a) {
        int n = a.length; // Get the size of the matrix
        double[][] x = new double[n][n]; // Initialize the result matrix
        double[][] b = new double[n][n]; // Matrix to hold intermediate results
        int[] index = new int[n]; // Array to hold the pivot indices
        
        // Initialize the identity matrix in b
        for (int i = 0; i < n; ++i) {
            b[i][i] = 1;
        }
        
        // Perform Gaussian elimination to transform the matrix
        gaussian(a, index);
        
        // Back substitution to find the inverse matrix
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    b[index[j]][k] -= a[index[j]][i] * b[index[i]][k];
                }
            }
        }
        
        // Calculate the values of the inverse matrix
        for (int i = 0; i < n; ++i) {
            x[n - 1][i] = b[index[n - 1]][i] / a[index[n - 1]][n - 1];
            for (int j = n - 2; j >= 0; --j) {
                x[j][i] = b[index[j]][i];
                for (int k = j + 1; k < n; ++k) {
                    x[j][i] -= a[index[j]][k] * x[k][i];
                }
                x[j][i] /= a[index[j]][j];
            }
        }
        
        // Return the computed inverse matrix
        return x;
    }

    // Method to perform Gaussian elimination with partial pivoting
    private static void gaussian(double[][] a, int[] index) {
        int n = index.length; // Get the size of the matrix
        double[] c = new double[n]; // Array to hold the scaling factors
        
        // Initialize the index array
        for (int i = 0; i < n; ++i) {
            index[i] = i;
        }
        
        // Compute the scaling factors for each row
        for (int i = 0; i < n; ++i) {
            double c1 = 0;
            for (int j = 0; j < n; ++j) {
                double c0 = Math.abs(a[i][j]);
                if (c0 > c1) {
                    c1 = c0; // Update the maximum value for scaling
                }
            }
            c[i] = c1; // Store the scaling factor
        }
        
        // Perform the Gaussian elimination process
        for (int j = 0; j < n - 1; ++j) {
            double pi1 = 0;
            int k = j;
            for (int i = j; i < n; ++i) {
                double pi0 = Math.abs(a[index[i]][j]) / c[index[i]];
                if (pi0 > pi1) {
                    pi1 = pi0; // Update the pivot row
                    k = i;
                }
            }
            // Swap the pivot row with the current row
            int temp = index[j];
            index[j] = index[k];
            index[k] = temp;
            
            // Eliminate the entries below the pivot
            for (int i = j + 1; i < n; ++i) {
                double pj = a[index[i]][j] / a[index[j]][j];
                a[index[i]][j] = pj;
                for (int l = j + 1; l < n; ++l) {
                    a[index[i]][l] -= pj * a[index[j]][l];
                }
            }
        }
    }
}

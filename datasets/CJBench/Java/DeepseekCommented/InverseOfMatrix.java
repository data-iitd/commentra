import java.util.Scanner; // Import the Scanner class for reading input

public final class Main {
    private Main() {
    } // Private constructor to prevent instantiation

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
        int n = scanner.nextInt(); // Read the size of the matrix
        double[][] matrix = new double[n][n]; // Initialize a matrix of size n x n

        // Read the elements of the matrix from the user
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = scanner.nextDouble();
            }
        }

        // Invert the matrix and print the result
        double[][] inverse = invert(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.printf("%.6f ", inverse[i][j]);
            }
            System.out.println();
        }
        scanner.close(); // Close the Scanner object
    }

    // Method to invert the given matrix using Gaussian elimination
    public static double[][] invert(double[][] a) {
        int n = a.length;
        double[][] x = new double[n][n]; // Matrix to store the inverse
        double[][] b = new double[n][n]; // Matrix to store the intermediate results during Gaussian elimination
        int[] index = new int[n]; // Array to store the row indices

        // Initialize the matrix b to the identity matrix
        for (int i = 0; i < n; ++i) {
            b[i][i] = 1;
        }

        // Perform Gaussian elimination and update b
        gaussian(a, index);

        // Perform back substitution to find the inverse
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
        return x;
    }

    // Helper method to perform Gaussian elimination
    private static void gaussian(double[][] a, int[] index) {
        int n = index.length;
        double[] c = new double[n]; // Array to store the scaling factors

        // Initialize the index array
        for (int i = 0; i < n; ++i) {
            index[i] = i;
        }

        // Compute the scaling factors
        for (int i = 0; i < n; ++i) {
            double c1 = 0;
            for (int j = 0; j < n; ++j) {
                double c0 = Math.abs(a[i][j]);
                if (c0 > c1) {
                    c1 = c0;
                }
            }
            c[i] = c1;
        }

        // Perform Gaussian elimination
        for (int j = 0; j < n - 1; ++j) {
            double pi1 = 0;
            int k = j;
            for (int i = j; i < n; ++i) {
                double pi0 = Math.abs(a[index[i]][j]) / c[index[i]];
                if (pi0 > pi1) {
                    pi1 = pi0;
                    k = i;
                }
            }
            int temp = index[j];
            index[j] = index[k];
            index[k] = temp;
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

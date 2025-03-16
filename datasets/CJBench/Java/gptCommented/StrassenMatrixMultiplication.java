import java.util.Scanner;

public class Main {
    // Method to multiply two matrices using Strassen's algorithm
    public int[][] multiply(int[][] a, int[][] b) {
        int n = a.length; // Get the size of the matrices (assuming square matrices)
        int[][] mat = new int[n][n]; // Initialize the resultant matrix

        // Base case for recursion: if the matrix size is 1
        if (n == 1) {
            mat[0][0] = a[0][0] * b[0][0]; // Multiply the single elements
        } else {
            // Create submatrices for a and b
            int[][] a11 = new int[n / 2][n / 2];
            int[][] a12 = new int[n / 2][n / 2];
            int[][] a21 = new int[n / 2][n / 2];
            int[][] a22 = new int[n / 2][n / 2];
            int[][] b11 = new int[n / 2][n / 2];
            int[][] b12 = new int[n / 2][n / 2];
            int[][] b21 = new int[n / 2][n / 2];
            int[][] b22 = new int[n / 2][n / 2];

            // Split matrices a and b into submatrices
            split(a, a11, 0, 0);
            split(a, a12, 0, n / 2);
            split(a, a21, n / 2, 0);
            split(a, a22, n / 2, n / 2);
            split(b, b11, 0, 0);
            split(b, b12, 0, n / 2);
            split(b, b21, n / 2, 0);
            split(b, b22, n / 2, n / 2);

            // Calculate the 7 products using Strassen's formulas
            int[][] m1 = multiply(add(a11, a22), add(b11, b22));
            int[][] m2 = multiply(add(a21, a22), b11);
            int[][] m3 = multiply(a11, sub(b12, b22));
            int[][] m4 = multiply(a22, sub(b21, b11));
            int[][] m5 = multiply(add(a11, a12), b22);
            int[][] m6 = multiply(sub(a21, a11), add(b11, b12));
            int[][] m7 = multiply(sub(a12, a22), add(b21, b22));

            // Combine the results into the resultant matrix
            int[][] c11 = add(sub(add(m1, m4), m5), m7);
            int[][] c12 = add(m3, m5);
            int[][] c21 = add(m2, m4);
            int[][] c22 = add(sub(add(m1, m3), m2), m6);

            // Join the submatrices into the final result matrix
            join(c11, mat, 0, 0);
            join(c12, mat, 0, n / 2);
            join(c21, mat, n / 2, 0);
            join(c22, mat, n / 2, n / 2);
        }
        return mat; // Return the resultant matrix
    }

    // Method to subtract two matrices
    public int[][] sub(int[][] a, int[][] b) {
        int n = a.length; // Get the size of the matrices
        int[][] c = new int[n][n]; // Initialize the resultant matrix for subtraction
        // Perform element-wise subtraction
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = a[i][j] - b[i][j];
            }
        }
        return c; // Return the resultant matrix
    }

    // Method to add two matrices
    public int[][] add(int[][] a, int[][] b) {
        int n = a.length; // Get the size of the matrices
        int[][] c = new int[n][n]; // Initialize the resultant matrix for addition
        // Perform element-wise addition
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        return c; // Return the resultant matrix
    }

    // Method to split a matrix into a submatrix
    public void split(int[][] p, int[][] c, int iB, int jB) {
        // Copy elements from matrix p to submatrix c
        for (int i1 = 0, i2 = iB; i1 < c.length; i1++, i2++) {
            for (int j1 = 0, j2 = jB; j1 < c.length; j1++, j2++) {
                c[i1][j1] = p[i2][j2];
            }
        }
    }

    // Method to join a submatrix into a larger matrix
    public void join(int[][] c, int[][] p, int iB, int jB) {
        // Copy elements from submatrix c to matrix p
        for (int i1 = 0, i2 = iB; i1 < c.length; i1++, i2++) {
            for (int j1 = 0, j2 = jB; j1 < c.length; j1++, j2++) {
                p[i2][j2] = c[i1][j1];
            }
        }
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        int n = scanner.nextInt(); // Read the size of the matrices
        int[][] a = new int[n][n]; // Initialize the first matrix
        int[][] b = new int[n][n]; // Initialize the second matrix

        // Read elements for the first matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = scanner.nextInt();
            }
        }

        // Read elements for the second matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                b[i][j] = scanner.nextInt();
            }
        }

        // Create an instance of Main to use the multiply method
        Main strassen = new Main();
        int[][] result = strassen.multiply(a, b); // Multiply the two matrices

        // Print the resultant matrix
        System.out.println("Resultant Matrix:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(result[i][j] + " "); // Print each element
            }
            System.out.println(); // Move to the next line after each row
        }
        scanner.close(); // Close the scanner
    }
}

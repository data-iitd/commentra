import java.util.Scanner;

// Class definition for the Main class
public class Main {

    // Method definition for matrix multiplication
    public int[][] multiply(int[][] a, int[][] b) {
        int n = a.length; // Get the size of the matrices
        int[][] mat = new int[n][n]; // Initialize a new matrix to store the result

        // Base case: when the size of the matrix is 1x1
        if (n == 1) {
            mat[0][0] = a[0][0] * b[0][0]; // Multiply the elements and store the result in the matrix
        } else { // Recursive case: when the size of the matrix is greater than 1x1
            int[][] a11, a12, a21, a22, b11, b12, b21, b22; // Initialize 8 sub-matrices

            // Split the given matrices into 4 sub-matrices
            split(a, a11, 0, 0);
            split(a, a12, 0, n / 2);
            split(a, a21, n / 2, 0);
            split(a, a22, n / 2, n / 2);
            split(b, b11, 0, 0);
            split(b, b12, 0, n / 2);
            split(b, b21, n / 2, 0);
            split(b, b22, n / 2, n / 2);

            // Multiply the sub-matrices recursively and store the results in new matrices
            int[][] m1 = multiply(add(a11, a22), add(b11, b22));
            int[][] m2 = multiply(add(a21, a22), b11);
            int[][] m3 = multiply(a11, sub(b12, b22));
            int[][] m4 = multiply(a22, sub(b21, b11));
            int[][] m5 = multiply(add(a11, a12), b22);
            int[][] m6 = multiply(sub(a21, a11), add(b11, b12));
            int[][] m7 = multiply(sub(a12, a22), add(b21, b22));

            // Combine the results from the sub-matrices to form the final result
            int[][] c11 = add(sub(add(m1, m4), m5), m7);
            int[][] c12 = add(m3, m5);
            int[][] c21 = add(m2, m4);
            int[][] c22 = add(sub(add(m1, m3), m2), m6);

            // Join the sub-matrices to form the final result matrix
            join(c11, mat, 0, 0);
            join(c12, mat, 0, n / 2);
            join(c21, mat, n / 2, 0);
            join(c22, mat, n / 2, n / 2);
        }
        return mat; // Return the final result matrix
    }

    // Method definition for matrix subtraction
    public int[][] sub(int[][] a, int[][] b) {
        int n = a.length; // Get the size of the matrices
        int[][] c = new int[n][n]; // Initialize a new matrix to store the result

        // Subtract the corresponding elements and store the result in the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = a[i][j] - b[i][j];
            }
        }
        return c; // Return the result matrix
    }

    // Method definition for matrix addition
    public int[][] add(int[][] a, int[][] b) {
        int n = a.length; // Get the size of the matrices
        int[][] c = new int[n][n]; // Initialize a new matrix to store the result

        // Add the corresponding elements and store the result in the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        return c; // Return the result matrix
    }

    // Method definition for splitting a matrix into sub-matrices
    public void split(int[][] p, int[][] c, int iB, int jB) {
        for (int i1 = 0, i2 = iB; i1 < c.length; i1++, i2++) {
            for (int j1 = 0, j2 = jB; j1 < c.length; j1++, j2++) {
                c[i1][j1] = p[i2][j2]; // Copy the elements from the given matrix to the sub-matrix
            }
        }
    }

    // Method definition for joining two matrices
    public void join(int[][] c, int[][] p, int iB, int jB) {
        for (int i1 = 0, i2 = iB; i1 < c.length; i1++, i2++) {
            for (int j1 = 0, j2 = jB; j1 < c.length; j1++, j2++) {
                p[i2][j2] = c[i1][j1]; // Copy the elements from the sub-matrix to the given matrix
            }
        }
    }

    // Main method to read input matrices and call the multiply method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a Scanner object to read input

        int n = scanner.nextInt(); // Read the size of the matrices from the user
        int[][] a = new int[n][n]; // Initialize a new matrix to store the first matrix
        int[][] b = new int[n][n]; // Initialize a new matrix to store the second matrix

        // Read the elements of the matrices from the user
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = scanner.nextInt();
                b[i][j] = scanner.nextInt();
            }
        }

        Main strassen = new Main(); // Create an instance of the Main class
        int[][] result = strassen.multiply(a, b); // Call the multiply method to compute the result

        System.out.println("Resultant Matrix:"); // Print the header for the result matrix
        for (int i = 0; i < n; i++) { // Print each row of the result matrix
            for (int j = 0; j < n; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }

        scanner.close(); // Close the Scanner object
    }
}

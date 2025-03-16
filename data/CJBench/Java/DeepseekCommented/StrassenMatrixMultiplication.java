import java.util.Scanner; // Importing Scanner class for reading input

public class Main {
    // Method to multiply two matrices using Strassen's algorithm
    public int[][] multiply(int[][] a, int[][] b) {
        int n = a.length; // Get the size of the matrix
        int[][] mat = new int[n][n]; // Initialize the result matrix
        if (n == 1) {
            mat[0][0] = a[0][0] * b[0][0]; // Base case: single element multiplication
        } else {
            // Divide the matrix into four quadrants
            int[][] a11 = new int[n / 2][n / 2];
            int[][] a12 = new int[n / 2][n / 2];
            int[][] a21 = new int[n / 2][n / 2];
            int[][] a22 = new int[n / 2][n / 2];
            int[][] b11 = new int[n / 2][n / 2];
            int[][] b12 = new int[n / 2][n / 2];
            int[][] b21 = new int[n / 2][n / 2];
            int[][] b22 = new int[n / 2][n / 2];
            // Split the matrices into submatrices
            split(a, a11, 0, 0);
            split(a, a12, 0, n / 2);
            split(a, a21, n / 2, 0);
            split(a, a22, n / 2, n / 2);
            split(b, b11, 0, 0);
            split(b, b12, 0, n / 2);
            split(b, b21, n / 2, 0);
            split(b, b22, n / 2, n / 2);
            // Recursively compute the seven products
            int[][] m1 = multiply(add(a11, a22), add(b11, b22));
            int[][] m2 = multiply(add(a21, a22), b11);
            int[][] m3 = multiply(a11, sub(b12, b22));
            int[][] m4 = multiply(a22, sub(b21, b11));
            int[][] m5 = multiply(add(a11, a12), b22);
            int[][] m6 = multiply(sub(a21, a11), add(b11, b12));
            int[][] m7 = multiply(sub(a12, a22), add(b21, b22));
            // Compute the four quadrants of the resulting matrix
            int[][] c11 = add(sub(add(m1, m4), m5), m7);
            int[][] c12 = add(m3, m5);
            int[][] c21 = add(m2, m4);
            int[][] c22 = add(sub(add(m1, m3), m2), m6);
            // Join the quadrants back into the result matrix
            join(c11, mat, 0, 0);
            join(c12, mat, 0, n / 2);
            join(c21, mat, n / 2, 0);
            join(c22, mat, n / 2, n / 2);
        }
        return mat; // Return the resultant matrix
    }

    // Method to perform element-wise subtraction of two matrices
    public int[][] sub(int[][] a, int[][] b) {
        int n = a.length; // Get the size of the matrix
        int[][] c = new int[n][n]; // Initialize the result matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = a[i][j] - b[i][j]; // Subtract corresponding elements
            }
        }
        return c; // Return the resultant matrix
    }

    // Method to perform element-wise addition of two matrices
    public int[][] add(int[][] a, int[][] b) {
        int n = a.length; // Get the size of the matrix
        int[][] c = new int[n][n]; // Initialize the result matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = a[i][j] + b[i][j]; // Add corresponding elements
            }
        }
        return c; // Return the resultant matrix
    }

    // Method to split a matrix into four submatrices
    public void split(int[][] p, int[][] c, int iB, int jB) {
        for (int i1 = 0, i2 = iB; i1 < c.length; i1++, i2++) {
            for (int j1 = 0, j2 = jB; j1 < c.length; j1++, j2++) {
                c[i1][j1] = p[i2][j2]; // Copy elements to submatrices
            }
        }
    }

    // Method to join four submatrices back into a single matrix
    public void join(int[][] c, int[][] p, int iB, int jB) {
        for (int i1 = 0, i2 = iB; i1 < c.length; i1++, i2++) {
            for (int j1 = 0, j2 = jB; j1 < c.length; j1++, j2++) {
                p[i2][j2] = c[i1][j1]; // Copy elements from submatrices
            }
        }
    }

    // Main method to read input, call the multiply method, and print the result
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object
        int n = scanner.nextInt(); // Read the size of the matrix
        int[][] a = new int[n][n]; // Initialize the first matrix
        int[][] b = new int[n][n]; // Initialize the second matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = scanner.nextInt(); // Read elements of the first matrix
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                b[i][j] = scanner.nextInt(); // Read elements of the second matrix
            }
        }
        Main strassen = new Main(); // Create an instance of the Main class
        int[][] result = strassen.multiply(a, b); // Call the multiply method
        System.out.println("Resultant Matrix:"); // Print the result
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(result[i][j] + " "); // Print elements of the resultant matrix
            }
            System.out.println(); // Move to the next line
        }
        scanner.close(); // Close the Scanner object
    }
}

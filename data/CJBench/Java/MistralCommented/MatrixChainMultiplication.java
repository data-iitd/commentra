import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

// Class definition for the Main class, which contains the main logic for calculating the matrix chain order
public final class Main {
    private Main() {
    }

    // Declare and initialize 2D arrays m and s, and 1D array p for storing intermediate results and lengths of matrices
    private static int[][] m;
    private static int[][] s;
    private static int[] p;

    // Static method for calculating the matrix chain order using dynamic programming
    public static Result calculateMatrixChainOrder(ArrayList<Matrix> matrices) {
        int size = matrices.size(); // Get the size of the list of matrices

        // Initialize the m, s, and p arrays with default values
        m = new int[size + 1][size + 1];
        s = new int[size + 1][size + 1];
        p = new int[size + 1];

        // Initialize all elements of m and s with maximum values and -1 for s, respectively
        for (int i = 0; i < size + 1; i++) {
            Arrays.fill(m[i], Integer.MAX_VALUE);
            Arrays.fill(s[i], -1);
        }

        // Initialize the p array with the number of columns of each matrix
        for (int i = 0; i < size + 1; i++) {
            p[i] = matrices.get(i - 1) == null ? 0 : matrices.get(i - 1).col();
        }

        // Call the matrixChainOrder method to calculate the minimum number of multiplications
        matrixChainOrder(size);

        // Return a Result object containing the m and s arrays
        return new Result(m, s);
    }

    // Recursive method for calculating the matrix chain order using dynamic programming
    private static void matrixChainOrder(int size) {
        // Initialize the first diagonal elements of the m array with 0
        for (int i = 1; i <= size; i++) {
            m[i][i] = 0;
        }

        // Iterate through all possible submatrices of size l <= size
        for (int l = 2; l <= size; l++) {
            // Iterate through all possible starting indices i and ending indices j of submatrices of size l
            for (int i = 1; i <= size - l + 1; i++) {
                int j = i + l - 1;

                // Initialize the minimum cost for the current submatrix with a large value
                m[i][j] = Integer.MAX_VALUE;

                // Iterate through all possible splitting indices k of the submatrix
                for (int k = i; k < j; k++) {
                    int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    // Update the minimum cost if a better solution is found
                    if (q < m[i][j]) {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }
    }

    // Class definition for the Result class, which stores the m and s arrays as fields
    public static class Result {
        private final int[][] m;
        private final int[][] s;

        // Constructor for the Result class
        public Result(int[][] m, int[][] s) {
            this.m = m;
            this.s = s;
        }

        // Getter methods for the m and s arrays
        public int[][] getM() {
            return m;
        }

        public int[][] getS() {
            return s;
        }
    }

    // Class definition for the Matrix class, which represents a single matrix with its number, columns, and rows
    public static class Matrix {
        private final int count;
        private final int col;
        private final int row;

        // Constructor for the Matrix class
        public Matrix(int count, int col, int row) {
            this.count = count;
            this.col = col;
            this.row = row;
        }

        // Getter methods for the number of matrices, columns, and rows
        public int count() {
            return count;
        }

        public int col() {
            return col;
        }

        public int row() {
            return row;
        }
    }

    // Main method for reading input and calling the calculateMatrixChainOrder method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for reading input

        int n = scanner.nextInt(); // Read the number of matrices from the input

        ArrayList<Matrix> matrices = new ArrayList<>(); // Create an empty ArrayList for storing the matrices

        for (int i = 1; i <= n; i++) { // Iterate through all matrices and add them to the ArrayList
            int rows = scanner.nextInt();
            int cols = scanner.nextInt();
            matrices.add(new Matrix(i, cols, rows));
        }

        Result result = calculateMatrixChainOrder(matrices); // Call the calculateMatrixChainOrder method and store the result in a Result object

        System.out.println("Minimum number of multiplications: " + result.getM()[1][n]); // Print the minimum number of multiplications to the output

        scanner.close(); // Close the Scanner object
    }
}

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    // Matrices to hold the minimum multiplication costs and split points
    private static int[][] m;
    private static int[][] s;
    private static int[] p;

    // Method to calculate the optimal order of matrix multiplication
    public static Result calculateMatrixChainOrder(ArrayList<Matrix> matrices) {
        int size = matrices.size();
        
        // Initialize the matrices for storing minimum costs and split points
        m = new int[size + 1][size + 1];
        s = new int[size + 1][size + 1];
        p = new int[size + 1];

        // Fill the matrices with initial values
        for (int i = 0; i < size + 1; i++) {
            Arrays.fill(m[i], Integer.MAX_VALUE); // Set to max value for comparison
            Arrays.fill(s[i], -1); // Initialize split points to -1
        }

        // Set the dimensions of the matrices in the array p
        p[0] = matrices.get(0).row();
        for (int i = 1; i <= size; i++) {
            p[i] = matrices.get(i - 1).col();
        }

        // Calculate the matrix chain order
        matrixChainOrder(size);
        return new Result(m, s); // Return the result containing m and s matrices
    }

    // Method to compute the matrix chain order using dynamic programming
    private static void matrixChainOrder(int size) {
        // Initialize the diagonal of m to 0 (cost of multiplying one matrix)
        for (int i = 1; i <= size; i++) {
            m[i][i] = 0;
        }

        // l is the chain length
        for (int l = 2; l <= size; l++) {
            // i is the starting index of the chain
            for (int i = 1; i <= size - l + 1; i++) {
                int j = i + l - 1; // j is the ending index of the chain
                m[i][j] = Integer.MAX_VALUE; // Initialize to max value

                // Try different split points to find the minimum cost
                for (int k = i; k < j; k++) {
                    int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    // Update m[i][j] and s[i][j] if a lower cost is found
                    if (q < m[i][j]) {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }
    }

    // Class to hold the result of the matrix chain multiplication calculation
    public static class Result {
        private final int[][] m; // Matrix of minimum multiplication costs
        private final int[][] s; // Matrix of split points

        // Constructor to initialize the result
        public Result(int[][] m, int[][] s) {
            this.m = m;
            this.s = s;
        }

        // Getter for the cost matrix
        public int[][] getM() {
            return m;
        }

        // Getter for the split points matrix
        public int[][] getS() {
            return s;
        }
    }

    // Class to represent a matrix with its dimensions
    public static class Matrix {
        private final int count; // Identifier for the matrix
        private final int col; // Number of columns
        private final int row; // Number of rows

        // Constructor to initialize the matrix dimensions
        public Matrix(int count, int col, int row) {
            this.count = count;
            this.col = col;
            this.row = row;
        }

        // Getter for the count
        public int count() {
            return count;
        }

        // Getter for the number of columns
        public int col() {
            return col;
        }

        // Getter for the number of rows
        public int row() {
            return row;
        }
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of matrices
        int n = scanner.nextInt();
        ArrayList<Matrix> matrices = new ArrayList<>();

        // Read the dimensions of each matrix and store them
        for (int i = 1; i <= n; i++) {
            int rows = scanner.nextInt();
            int cols = scanner.nextInt();
            matrices.add(new Matrix(i, cols, rows));
        }

        // Calculate the optimal matrix chain order
        Result result = calculateMatrixChainOrder(matrices);
        
        // Output the minimum number of multiplications required
        System.out.println("Minimum number of multiplications: " + result.getM()[1][n]);
        
        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}

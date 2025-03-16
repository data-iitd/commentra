import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
public final class Main {
    private Main() {
    }
    // Private static arrays to store the results and intermediate values
    private static int[][] m;
    private static int[][] s;
    private static int[] p;

    // Method to calculate the minimum number of multiplications required to multiply the matrices
    public static Result calculateMatrixChainOrder(ArrayList<Matrix> matrices) {
        int size = matrices.size();
        // Initialize the arrays m and s with maximum integer values and -1 respectively
        m = new int[size + 1][size + 1];
        s = new int[size + 1][size + 1];
        p = new int[size + 1];
        for (int i = 0; i < size + 1; i++) {
            Arrays.fill(m[i], Integer.MAX_VALUE);
            Arrays.fill(s[i], -1);
        }
        // Fill the p array with the dimensions of the matrices
        p[0] = matrices.get(0).row();
        for (int i = 1; i <= size; i++) {
            p[i] = matrices.get(i - 1).col();
        }
        // Perform the dynamic programming approach to find the optimal parenthesization
        matrixChainOrder(size);
        return new Result(m, s);
    }

    // Method to perform the dynamic programming approach to find the optimal parenthesization
    private static void matrixChainOrder(int size) {
        for (int i = 1; i <= size; i++) {
            m[i][i] = 0; // No multiplication cost for single matrix
        }
        for (int l = 2; l <= size; l++) { // Iterate over the chain length
            for (int i = 1; i <= size - l + 1; i++) {
                int j = i + l - 1;
                m[i][j] = Integer.MAX_VALUE;
                for (int k = i; k < j; k++) {
                    int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (q < m[i][j]) {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }
    }

    // Class to encapsulate the results of the matrix chain multiplication
    public static class Result {
        private final int[][] m;
        private final int[][] s;
        public Result(int[][] m, int[][] s) {
            this.m = m;
            this.s = s;
        }
        public int[][] getM() {
            return m;
        }
        public int[][] getS() {
            return s;
        }
    }

    // Class to represent a matrix with a count, number of columns, and number of rows
    public static class Matrix {
        private final int count;
        private final int col;
        private final int row;
        public Matrix(int count, int col, int row) {
            this.count = count;
            this.col = col;
            this.row = row;
        }
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

    // Main method to read the number of matrices and their dimensions from the input
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ArrayList<Matrix> matrices = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            int rows = scanner.nextInt();
            int cols = scanner.nextInt();
            matrices.add(new Matrix(i, cols, rows));
        }
        Result result = calculateMatrixChainOrder(matrices);
        System.out.println("Minimum number of multiplications: " + result.getM()[1][n]);
        scanner.close();
    }
}

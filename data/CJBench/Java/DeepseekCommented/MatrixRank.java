import java.util.Scanner;
public final class Main {
    private Main() {
    }
    private static final double EPSILON = 1e-10; // Constant for floating-point precision

    // Main method to read matrix from input and compute its rank
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int rows = sc.nextInt(); // Read number of rows
        int cols = sc.nextInt(); // Read number of columns
        double[][] matrix = new double[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = sc.nextDouble(); // Read matrix elements
            }
        }
        int rank = computeRank(matrix); // Compute the rank of the matrix
        System.out.println("The rank of the matrix is: " + rank); // Print the rank
        sc.close(); // Close the scanner
    }

    // Method to compute the rank of a matrix
    public static int computeRank(double[][] matrix) {
        validateInputMatrix(matrix); // Validate the input matrix
        int numRows = matrix.length;
        int numColumns = matrix[0].length;
        int rank = 0;
        boolean[] rowMarked = new boolean[numRows];
        double[][] matrixCopy = deepCopy(matrix);
        for (int colIndex = 0; colIndex < numColumns; ++colIndex) {
            int pivotRow = findPivotRow(matrixCopy, rowMarked, colIndex);
            if (pivotRow != numRows) {
                ++rank;
                rowMarked[pivotRow] = true;
                normalizePivotRow(matrixCopy, pivotRow, colIndex);
                eliminateRows(matrixCopy, pivotRow, colIndex);
            }
        }
        return rank;
    }

    // Check if a value is effectively zero
    private static boolean isZero(double value) {
        return Math.abs(value) < EPSILON;
    }

    // Create a deep copy of the matrix
    private static double[][] deepCopy(double[][] matrix) {
        int numRows = matrix.length;
        int numColumns = matrix[0].length;
        double[][] matrixCopy = new double[numRows][numColumns];
        for (int rowIndex = 0; rowIndex < numRows; ++rowIndex) {
            System.arraycopy(matrix[rowIndex], 0, matrixCopy[rowIndex], 0, numColumns);
        }
        return matrixCopy;
    }

    // Validate the input matrix to ensure it is not null or empty and has valid rows
    private static void validateInputMatrix(double[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            throw new IllegalArgumentException("The input matrix cannot be null or empty");
        }
        if (!hasValidRows(matrix)) {
            throw new IllegalArgumentException("The input matrix cannot have null or empty rows");
        }
    }

    // Check if all rows in the matrix are non-null and non-empty
    private static boolean hasValidRows(double[][] matrix) {
        for (double[] row : matrix) {
            if (row == null || row.length == 0) {
                return false;
            }
        }
        return true;
    }

    // Find the first non-zero entry in the current column
    private static int findPivotRow(double[][] matrix, boolean[] rowMarked, int colIndex) {
        int numRows = matrix.length;
        for (int pivotRow = 0; pivotRow < numRows; ++pivotRow) {
            if (!rowMarked[pivotRow] && !isZero(matrix[pivotRow][colIndex])) {
                return pivotRow;
            }
        }
        return numRows;
    }

    // Normalize the pivot row by dividing all elements by the pivot element
    private static void normalizePivotRow(double[][] matrix, int pivotRow, int colIndex) {
        int numColumns = matrix[0].length;
        for (int nextCol = colIndex + 1; nextCol < numColumns; ++nextCol) {
            matrix[pivotRow][nextCol] /= matrix[pivotRow][colIndex];
        }
    }

    // Eliminate other rows by subtracting a multiple of the pivot row
    private static void eliminateRows(double[][] matrix, int pivotRow, int colIndex) {
        int numRows = matrix.length;
        int numColumns = matrix[0].length;
        for (int otherRow = 0; otherRow < numRows; ++otherRow) {
            if (otherRow != pivotRow && !isZero(matrix[otherRow][colIndex])) {
                for (int col2 = colIndex + 1; col2 < numColumns; ++col2) {
                    matrix[otherRow][col2] -= matrix[pivotRow][col2] * matrix[otherRow][colIndex];
                }
            }
        }
    }
}

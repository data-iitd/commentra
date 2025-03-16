import java.util.Scanner;
public final class MatrixRank {
    private MatrixRank() {
    }
    private static final double EPSILON = 1e-10;
    public static int computeRank(double[][] matrix) {
        validateInputMatrix(matrix);
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
    private static boolean isZero(double value) {
        return Math.abs(value) < EPSILON;
    }
    private static double[][] deepCopy(double[][] matrix) {
        int numRows = matrix.length;
        int numColumns = matrix[0].length;
        double[][] matrixCopy = new double[numRows][numColumns];
        for (int rowIndex = 0; rowIndex < numRows; ++rowIndex) {
            System.arraycopy(matrix[rowIndex], 0, matrixCopy[rowIndex], 0, numColumns);
        }
        return matrixCopy;
    }
    private static void validateInputMatrix(double[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            throw new IllegalArgumentException("The input matrix cannot be null or empty");
        }
        if (!hasValidRows(matrix)) {
            throw new IllegalArgumentException("The input matrix cannot have null or empty rows");
        }
    }
    private static boolean hasValidRows(double[][] matrix) {
        for (double[] row : matrix) {
            if (row == null || row.length == 0) {
                return false;
            }
        }
        return true;
    }
    private static int findPivotRow(double[][] matrix, boolean[] rowMarked, int colIndex) {
        int numRows = matrix.length;
        for (int pivotRow = 0; pivotRow < numRows; ++pivotRow) {
            if (!rowMarked[pivotRow] && !isZero(matrix[pivotRow][colIndex])) {
                return pivotRow;
            }
        }
        return numRows;
    }
    private static void normalizePivotRow(double[][] matrix, int pivotRow, int colIndex) {
        int numColumns = matrix[0].length;
        for (int nextCol = colIndex + 1; nextCol < numColumns; ++nextCol) {
            matrix[pivotRow][nextCol] /= matrix[pivotRow][colIndex];
        }
    }
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
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int rows = sc.nextInt();
        int cols = sc.nextInt();
        double[][] matrix = new double[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = sc.nextDouble();
            }
        }
        int rank = computeRank(matrix);
        System.out.println("The rank of the matrix is: " + rank);
        sc.close();
    }
}

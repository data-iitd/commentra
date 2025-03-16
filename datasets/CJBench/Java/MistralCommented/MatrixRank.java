
import java.util.Scanner;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class
    }

    private static final double EPSILON = 1e-10;
    // Define a constant EPSILON for small value comparison

    public static int computeRank(double[][] matrix) {
        validateInputMatrix(matrix); // Validate the input matrix
        int numRows = matrix.length; // Get the number of rows in the matrix
        int numColumns = matrix[0].length; // Get the number of columns in the matrix
        int rank = 0; // Initialize the rank to zero

        boolean[] rowMarked = new boolean[numRows]; // Create a boolean array to mark the rows that have been processed
        double[][] matrixCopy = deepCopy(matrix); // Create a copy of the input matrix for row elimination

        for (int colIndex = 0; colIndex < numColumns; ++colIndex) {
            int pivotRow = findPivotRow(matrixCopy, rowMarked, colIndex); // Find the pivot row for the current column
            if (pivotRow != numRows) { // If a pivot row is found
                ++rank; // Increment the rank
                rowMarked[pivotRow] = true; // Mark the pivot row as processed
                normalizePivotRow(matrixCopy, pivotRow, colIndex); // Normalize the pivot row
                eliminateRows(matrixCopy, pivotRow, colIndex); // Eliminate the rows below the pivot row
            }
        }

        return rank; // Return the rank of the matrix
    }

    private static boolean isZero(double value) {
        // Helper method to check if a value is zero
        return Math.abs(value) < EPSILON;
    }

    private static double[][] deepCopy(double[][] matrix) {
        int numRows = matrix.length; // Get the number of rows in the matrix
        int numColumns = matrix[0].length; // Get the number of columns in the matrix
        double[][] matrixCopy = new double[numRows][numColumns]; // Create a new matrix for the copy

        for (int rowIndex = 0; rowIndex < numRows; ++rowIndex) {
            System.arraycopy(matrix[rowIndex], 0, matrixCopy[rowIndex], 0, numColumns); // Copy each row to the new matrix
        }

        return matrixCopy; // Return the copied matrix
    }

    private static void validateInputMatrix(double[][] matrix) {
        if (matrix == null || matrix.length == 0) { // Check if the input matrix is null or empty
            throw new IllegalArgumentException("The input matrix cannot be null or empty");
        }
        if (!hasValidRows(matrix)) { // Check if the input matrix has any null or empty rows
            throw new IllegalArgumentException("The input matrix cannot have null or empty rows");
        }
    }

    private static boolean hasValidRows(double[][] matrix) {
        for (double[] row : matrix) { // Iterate through each row in the matrix
            if (row == null || row.length == 0) { // Check if the row is null or empty
                return false;
            }
        }
        return true; // Return true if all rows are valid
    }

    private static int findPivotRow(double[][] matrix, boolean[] rowMarked, int colIndex) {
        int numRows = matrix.length; // Get the number of rows in the matrix

        for (int pivotRow = 0; pivotRow < numRows; ++pivotRow) { // Iterate through each row to find the pivot row
            if (!rowMarked[pivotRow] && !isZero(matrix[pivotRow][colIndex])) { // Check if the row is not marked and the pivot element is not zero
                return pivotRow; // Return the pivot row index
            }
        }

        return numRows; // Return the number of rows if no pivot row is found
    }

    private static void normalizePivotRow(double[][] matrix, int pivotRow, int colIndex) {
        int numColumns = matrix[0].length; // Get the number of columns in the matrix

        for (int nextCol = colIndex + 1; nextCol < numColumns; ++nextCol) { // Iterate through the columns to the right of the pivot column
            matrix[pivotRow][nextCol] /= matrix[pivotRow][colIndex]; // Divide the elements in the pivot row by the pivot element
        }
    }

    private static void eliminateRows(double[][] matrix, int pivotRow, int colIndex) {
        int numRows = matrix.length; // Get the number of rows in the matrix
        int numColumns = matrix[0].length; // Get the number of columns in the matrix

        for (int otherRow = 0; otherRow < numRows; ++otherRow) { // Iterate through each row below the pivot row
            if (otherRow != pivotRow && !isZero(matrix[otherRow][colIndex])) { // Check if the row is not the pivot row and the pivot element is not zero in this row
                for (int col2 = colIndex + 1; col2 < numColumns; ++col2) { // Iterate through the columns to the right of the pivot column
                    matrix[otherRow][col2] -= matrix[pivotRow][col2] * matrix[otherRow][colIndex]; // Subtract the product of the pivot row and the current row times the pivot element from the current row
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the console

        int rows = sc.nextInt(); // Read the number of rows from the console
        int cols = sc.nextInt(); // Read the number of columns from the console
        double[][] matrix = new double[rows][cols]; // Create a 2D array to store the input matrix

        for (int i = 0; i < rows; i++) { // Iterate through each row in the matrix
            for (int j = 0; j < cols; j++) { // Iterate through each column in the matrix
                matrix[i][j] = sc.nextDouble(); // Read a double value from the console and store it in the matrix
            }
        }

        int rank = computeRank(matrix); // Compute the rank of the matrix
        System.out.println("The rank of the matrix is: " + rank); // Print the rank of the matrix to the console

        sc.close(); // Close the Scanner object
    }
}
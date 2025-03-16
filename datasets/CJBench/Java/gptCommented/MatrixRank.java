import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of this utility class
    private Main() {
    }

    // A small constant used for floating-point comparison
    private static final double EPSILON = 1e-10;

    // Method to compute the rank of a given matrix
    public static int computeRank(double[][] matrix) {
        // Validate the input matrix to ensure it is not null or empty
        validateInputMatrix(matrix);
        
        int numRows = matrix.length; // Number of rows in the matrix
        int numColumns = matrix[0].length; // Number of columns in the matrix
        int rank = 0; // Initialize rank of the matrix
        boolean[] rowMarked = new boolean[numRows]; // Array to track marked rows
        double[][] matrixCopy = deepCopy(matrix); // Create a deep copy of the matrix for manipulation
        
        // Iterate through each column to find pivot rows and eliminate other rows
        for (int colIndex = 0; colIndex < numColumns; ++colIndex) {
            int pivotRow = findPivotRow(matrixCopy, rowMarked, colIndex); // Find a pivot row for the current column
            if (pivotRow != numRows) { // If a valid pivot row is found
                ++rank; // Increment the rank
                rowMarked[pivotRow] = true; // Mark the pivot row
                normalizePivotRow(matrixCopy, pivotRow, colIndex); // Normalize the pivot row
                eliminateRows(matrixCopy, pivotRow, colIndex); // Eliminate other rows based on the pivot row
            }
        }
        return rank; // Return the computed rank of the matrix
    }

    // Helper method to check if a value is effectively zero
    private static boolean isZero(double value) {
        return Math.abs(value) < EPSILON; // Compare with EPSILON for floating-point precision
    }

    // Method to create a deep copy of the input matrix
    private static double[][] deepCopy(double[][] matrix) {
        int numRows = matrix.length; // Get number of rows
        int numColumns = matrix[0].length; // Get number of columns
        double[][] matrixCopy = new double[numRows][numColumns]; // Initialize a new matrix for the copy
        
        // Copy each row from the original matrix to the new matrix
        for (int rowIndex = 0; rowIndex < numRows; ++rowIndex) {
            System.arraycopy(matrix[rowIndex], 0, matrixCopy[rowIndex], 0, numColumns);
        }
        return matrixCopy; // Return the copied matrix
    }

    // Method to validate the input matrix for null or empty conditions
    private static void validateInputMatrix(double[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            throw new IllegalArgumentException("The input matrix cannot be null or empty");
        }
        if (!hasValidRows(matrix)) {
            throw new IllegalArgumentException("The input matrix cannot have null or empty rows");
        }
    }

    // Helper method to check if all rows in the matrix are valid (non-null and non-empty)
    private static boolean hasValidRows(double[][] matrix) {
        for (double[] row : matrix) {
            if (row == null || row.length == 0) {
                return false; // Return false if any row is null or empty
            }
        }
        return true; // All rows are valid
    }

    // Method to find a pivot row for the given column index
    private static int findPivotRow(double[][] matrix, boolean[] rowMarked, int colIndex) {
        int numRows = matrix.length; // Get number of rows
        for (int pivotRow = 0; pivotRow < numRows; ++pivotRow) {
            // Check if the row is not marked and the value is not zero
            if (!rowMarked[pivotRow] && !isZero(matrix[pivotRow][colIndex])) {
                return pivotRow; // Return the index of the pivot row
            }
        }
        return numRows; // Return numRows if no pivot row is found
    }

    // Method to normalize the pivot row by making the pivot element equal to 1
    private static void normalizePivotRow(double[][] matrix, int pivotRow, int colIndex) {
        int numColumns = matrix[0].length; // Get number of columns
        // Normalize the pivot row by dividing each element by the pivot element
        for (int nextCol = colIndex + 1; nextCol < numColumns; ++nextCol) {
            matrix[pivotRow][nextCol] /= matrix[pivotRow][colIndex];
        }
    }

    // Method to eliminate other rows using the pivot row
    private static void eliminateRows(double[][] matrix, int pivotRow, int colIndex) {
        int numRows = matrix.length; // Get number of rows
        int numColumns = matrix[0].length; // Get number of columns
        // Iterate through all rows to eliminate values in the current column
        for (int otherRow = 0; otherRow < numRows; ++otherRow) {
            if (otherRow != pivotRow && !isZero(matrix[otherRow][colIndex])) {
                // Subtract the appropriate multiple of the pivot row from the other row
                for (int col2 = colIndex + 1; col2 < numColumns; ++col2) {
                    matrix[otherRow][col2] -= matrix[pivotRow][col2] * matrix[otherRow][colIndex];
                }
            }
        }
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a scanner for input
        int rows = sc.nextInt(); // Read number of rows
        int cols = sc.nextInt(); // Read number of columns
        double[][] matrix = new double[rows][cols]; // Initialize the matrix
        
        // Read the matrix values from input
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = sc.nextDouble(); // Fill the matrix with user input
            }
        }
        
        // Compute the rank of the matrix and print the result
        int rank = computeRank(matrix);
        System.out.println("The rank of the matrix is: " + rank);
        sc.close(); // Close the scanner
    }
}

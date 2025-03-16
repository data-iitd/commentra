import numpy as np

class MatrixRankCalculator:
    EPSILON = 1e-10  # Define a constant EPSILON for small value comparison

    @staticmethod
    def compute_rank(matrix):
        MatrixRankCalculator.validate_input_matrix(matrix)  # Validate the input matrix
        num_rows, num_columns = matrix.shape  # Get the number of rows and columns in the matrix
        rank = 0  # Initialize the rank to zero

        row_marked = np.zeros(num_rows, dtype=bool)  # Create a boolean array to mark the rows that have been processed
        matrix_copy = matrix.copy()  # Create a copy of the input matrix for row elimination

        for col_index in range(num_columns):
            pivot_row = MatrixRankCalculator.find_pivot_row(matrix_copy, row_marked, col_index)  # Find the pivot row for the current column
            if pivot_row != num_rows:  # If a pivot row is found
                rank += 1  # Increment the rank
                row_marked[pivot_row] = True  # Mark the pivot row as processed
                MatrixRankCalculator.normalize_pivot_row(matrix_copy, pivot_row, col_index)  # Normalize the pivot row
                MatrixRankCalculator.eliminate_rows(matrix_copy, pivot_row, col_index)  # Eliminate the rows below the pivot row

        return rank  # Return the rank of the matrix

    @staticmethod
    def is_zero(value):
        # Helper method to check if a value is zero
        return abs(value) < MatrixRankCalculator.EPSILON

    @staticmethod
    def validate_input_matrix(matrix):
        if matrix is None or matrix.size == 0:  # Check if the input matrix is null or empty
            raise ValueError("The input matrix cannot be null or empty")
        if not MatrixRankCalculator.has_valid_rows(matrix):  # Check if the input matrix has any null or empty rows
            raise ValueError("The input matrix cannot have null or empty rows")

    @staticmethod
    def has_valid_rows(matrix):
        return not np.any(np.array([row is None or len(row) == 0 for row in matrix]))  # Check if all rows are valid

    @staticmethod
    def find_pivot_row(matrix, row_marked, col_index):
        num_rows = matrix.shape[0]  # Get the number of rows in the matrix

        for pivot_row in range(num_rows):  # Iterate through each row to find the pivot row
            if not row_marked[pivot_row] and not MatrixRankCalculator.is_zero(matrix[pivot_row, col_index]):  # Check if the row is not marked and the pivot element is not zero
                return pivot_row  # Return the pivot row index

        return num_rows  # Return the number of rows if no pivot row is found

    @staticmethod
    def normalize_pivot_row(matrix, pivot_row, col_index):
        num_columns = matrix.shape[1]  # Get the number of columns in the matrix

        for next_col in range(col_index + 1, num_columns):  # Iterate through the columns to the right of the pivot column
            matrix[pivot_row, next_col] /= matrix[pivot_row, col_index]  # Divide the elements in the pivot row by the pivot element

    @staticmethod
    def eliminate_rows(matrix, pivot_row, col_index):
        num_rows = matrix.shape[0]  # Get the number of rows in the matrix
        num_columns = matrix.shape[1]  # Get the number of columns in the matrix

        for other_row in range(num_rows):  # Iterate through each row below the pivot row
            if other_row != pivot_row and not MatrixRankCalculator.is_zero(matrix[other_row, col_index]):  # Check if the row is not the pivot row and the pivot element is not zero in this row
                for col2 in range(col_index + 1, num_columns):  # Iterate through the columns to the right of the pivot column
                    matrix[other_row, col2] -= matrix[pivot_row, col2] * matrix[other_row, col_index]  # Subtract the product of the pivot row and the current row times the pivot element from the current row

if __name__ == "__main__":
    rows = int(input("Enter number of rows: "))  # Read the number of rows from the console
    cols = int(input("Enter number of columns: "))  # Read the number of columns from the console
    matrix = np.zeros((rows, cols))  # Create a 2D array to store the input matrix

    for i in range(rows):  # Iterate through each row in the matrix
        matrix[i] = list(map(float, input(f"Enter row {i + 1} values: ").split()))  # Read a row of double values from the console and store it in the matrix

    rank = MatrixRankCalculator.compute_rank(matrix)  # Compute the rank of the matrix
    print("The rank of the matrix is:", rank)  # Print the rank of the matrix to the console

# <END-OF-CODE>

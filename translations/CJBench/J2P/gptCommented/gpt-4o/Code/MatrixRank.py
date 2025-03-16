import numpy as np

class MatrixRankCalculator:
    # A small constant used for floating-point comparison
    EPSILON = 1e-10

    @staticmethod
    def compute_rank(matrix):
        # Validate the input matrix to ensure it is not None or empty
        MatrixRankCalculator.validate_input_matrix(matrix)

        num_rows = matrix.shape[0]  # Number of rows in the matrix
        num_columns = matrix.shape[1]  # Number of columns in the matrix
        rank = 0  # Initialize rank of the matrix
        row_marked = np.zeros(num_rows, dtype=bool)  # Array to track marked rows
        matrix_copy = matrix.copy()  # Create a deep copy of the matrix for manipulation

        # Iterate through each column to find pivot rows and eliminate other rows
        for col_index in range(num_columns):
            pivot_row = MatrixRankCalculator.find_pivot_row(matrix_copy, row_marked, col_index)  # Find a pivot row for the current column
            if pivot_row != num_rows:  # If a valid pivot row is found
                rank += 1  # Increment the rank
                row_marked[pivot_row] = True  # Mark the pivot row
                MatrixRankCalculator.normalize_pivot_row(matrix_copy, pivot_row, col_index)  # Normalize the pivot row
                MatrixRankCalculator.eliminate_rows(matrix_copy, pivot_row, col_index)  # Eliminate other rows based on the pivot row

        return rank  # Return the computed rank of the matrix

    @staticmethod
    def is_zero(value):
        return abs(value) < MatrixRankCalculator.EPSILON  # Compare with EPSILON for floating-point precision

    @staticmethod
    def validate_input_matrix(matrix):
        if matrix is None or matrix.size == 0:
            raise ValueError("The input matrix cannot be None or empty")
        if not MatrixRankCalculator.has_valid_rows(matrix):
            raise ValueError("The input matrix cannot have None or empty rows")

    @staticmethod
    def has_valid_rows(matrix):
        return all(row.size > 0 for row in matrix)  # Check if all rows are valid (non-None and non-empty)

    @staticmethod
    def find_pivot_row(matrix, row_marked, col_index):
        num_rows = matrix.shape[0]  # Get number of rows
        for pivot_row in range(num_rows):
            # Check if the row is not marked and the value is not zero
            if not row_marked[pivot_row] and not MatrixRankCalculator.is_zero(matrix[pivot_row, col_index]):
                return pivot_row  # Return the index of the pivot row
        return num_rows  # Return num_rows if no pivot row is found

    @staticmethod
    def normalize_pivot_row(matrix, pivot_row, col_index):
        # Normalize the pivot row by dividing each element by the pivot element
        matrix[pivot_row, col_index + 1:] /= matrix[pivot_row, col_index]

    @staticmethod
    def eliminate_rows(matrix, pivot_row, col_index):
        num_rows = matrix.shape[0]  # Get number of rows
        # Iterate through all rows to eliminate values in the current column
        for other_row in range(num_rows):
            if other_row != pivot_row and not MatrixRankCalculator.is_zero(matrix[other_row, col_index]):
                # Subtract the appropriate multiple of the pivot row from the other row
                matrix[other_row, col_index + 1:] -= matrix[pivot_row, col_index + 1:] * matrix[other_row, col_index]

# Main execution
if __name__ == "__main__":
    rows = int(input("Enter number of rows: "))  # Read number of rows
    cols = int(input("Enter number of columns: "))  # Read number of columns
    matrix = np.zeros((rows, cols))  # Initialize the matrix

    # Read the matrix values from input
    for i in range(rows):
        matrix[i] = list(map(float, input(f"Enter row {i + 1} values: ").split()))  # Fill the matrix with user input

    # Compute the rank of the matrix and print the result
    rank = MatrixRankCalculator.compute_rank(matrix)
    print("The rank of the matrix is:", rank)

# <END-OF-CODE>

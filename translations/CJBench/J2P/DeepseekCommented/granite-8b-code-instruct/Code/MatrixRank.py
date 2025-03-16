
import numpy as np

# Main method to read matrix from input and compute its rank
def main():
    rows = int(input("Enter the number of rows: "))
    cols = int(input("Enter the number of columns: "))
    matrix = np.zeros((rows, cols))
    for i in range(rows):
        row = list(map(float, input("Enter the elements of row {} separated by spaces: ".format(i+1)).split()))
        matrix[i] = row
    rank = compute_rank(matrix)
    print("The rank of the matrix is:", rank)

# Method to compute the rank of a matrix
def compute_rank(matrix):
    validate_input_matrix(matrix)
    num_rows, num_cols = matrix.shape
    rank = 0
    row_marked = np.zeros(num_rows, dtype=bool)
    matrix_copy = np.copy(matrix)
    for col_index in range(num_cols):
        pivot_row = find_pivot_row(matrix_copy, row_marked, col_index)
        if pivot_row!= num_rows:
            rank += 1
            row_marked[pivot_row] = True
            normalize_pivot_row(matrix_copy, pivot_row, col_index)
            eliminate_rows(matrix_copy, pivot_row, col_index)
    return rank

# Check if a value is effectively zero
def is_zero(value):
    return abs(value) < 1e-10

# Create a deep copy of the matrix
def deep_copy(matrix):
    return np.copy(matrix)

# Validate the input matrix to ensure it is not null or empty and has valid rows
def validate_input_matrix(matrix):
    if matrix is None or len(matrix) == 0:
        raise ValueError("The input matrix cannot be null or empty")
    if not has_valid_rows(matrix):
        raise ValueError("The input matrix cannot have null or empty rows")

# Check if all rows in the matrix are non-null and non-empty
def has_valid_rows(matrix):
    for row in matrix:
        if row is None or len(row) == 0:
            return False
    return True

# Find the first non-zero entry in the current column
def find_pivot_row(matrix, row_marked, col_index):
    num_rows = matrix.shape[0]
    for pivot_row in range(num_rows):
        if not row_marked[pivot_row] and not is_zero(matrix[pivot_row][col_index]):
            return pivot_row
    return num_rows

# Normalize the pivot row by dividing all elements by the pivot element
def normalize_pivot_row(matrix, pivot_row, col_index):
    num_cols = matrix.shape[1]
    for next_col in range(col_index + 1, num_cols):
        matrix[pivot_row][next_col] /= matrix[pivot_row][col_index]

# Eliminate other rows by subtracting a multiple of the pivot row
def eliminate_rows(matrix, pivot_row, col_index):
    num_rows, num_cols = matrix.shape
    for other_row in range(num_rows):
        if other_row!= pivot_row and not is_zero(matrix[other_row][col_index]):
            for col2 in range(col_index + 1, num_cols):
                matrix[other_row][col2] -= matrix[pivot_row][col2] * matrix[other_row][col_index]

if __name__ == "__main__":
    main()


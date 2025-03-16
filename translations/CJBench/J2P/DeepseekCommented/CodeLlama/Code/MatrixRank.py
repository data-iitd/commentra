import math

def main():
    # Read matrix from input
    rows = int(input())
    cols = int(input())
    matrix = []
    for i in range(rows):
        matrix.append([float(j) for j in input().split()])

    # Compute the rank of the matrix
    rank = compute_rank(matrix)

    # Print the rank
    print("The rank of the matrix is:", rank)

def compute_rank(matrix):
    # Validate the input matrix
    validate_input_matrix(matrix)

    # Initialize variables
    num_rows = len(matrix)
    num_columns = len(matrix[0])
    rank = 0
    row_marked = [False] * num_rows
    matrix_copy = deep_copy(matrix)

    # Iterate over columns
    for col_index in range(num_columns):
        # Find the first non-zero entry in the current column
        pivot_row = find_pivot_row(matrix_copy, row_marked, col_index)

        # If a pivot row is found, normalize it and eliminate other rows
        if pivot_row != num_rows:
            rank += 1
            row_marked[pivot_row] = True
            normalize_pivot_row(matrix_copy, pivot_row, col_index)
            eliminate_rows(matrix_copy, pivot_row, col_index)

    # Return the rank
    return rank

def validate_input_matrix(matrix):
    # Check if the input matrix is not null or empty
    if not matrix:
        raise ValueError("The input matrix cannot be null or empty")

    # Check if all rows in the matrix are non-null and non-empty
    if not all(row for row in matrix):
        raise ValueError("The input matrix cannot have null or empty rows")

def deep_copy(matrix):
    # Create a deep copy of the matrix
    matrix_copy = []
    for row in matrix:
        matrix_copy.append(row[:])
    return matrix_copy

def find_pivot_row(matrix, row_marked, col_index):
    # Find the first non-zero entry in the current column
    for pivot_row in range(len(matrix)):
        if not row_marked[pivot_row] and not is_zero(matrix[pivot_row][col_index]):
            return pivot_row
    return len(matrix)

def normalize_pivot_row(matrix, pivot_row, col_index):
    # Normalize the pivot row by dividing all elements by the pivot element
    for next_col in range(col_index + 1, len(matrix[0])):
        matrix[pivot_row][next_col] /= matrix[pivot_row][col_index]

def eliminate_rows(matrix, pivot_row, col_index):
    # Eliminate other rows by subtracting a multiple of the pivot row
    for other_row in range(len(matrix)):
        if other_row != pivot_row and not is_zero(matrix[other_row][col_index]):
            for col2 in range(col_index + 1, len(matrix[0])):
                matrix[other_row][col2] -= matrix[pivot_row][col2] * matrix[other_row][col_index]

def is_zero(value):
    # Check if a value is effectively zero
    return abs(value) < 1e-10

if __name__ == "__main__":
    main()


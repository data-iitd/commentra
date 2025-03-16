
import numpy as np
def compute_rank(matrix):
    matrix = np.array(matrix)
    num_rows, num_columns = matrix.shape
    rank = 0
    row_marked = np.zeros(num_rows, dtype=bool)
    matrix_copy = np.copy(matrix)
    for col_index in range(num_columns):
        pivot_row = find_pivot_row(matrix_copy, row_marked, col_index)
        if pivot_row!= num_rows:
            rank += 1
            row_marked[pivot_row] = True
            normalize_pivot_row(matrix_copy, pivot_row, col_index)
            eliminate_rows(matrix_copy, pivot_row, col_index)
    return rank
def is_zero(value):
    return abs(value) < 1e-10
def deep_copy(matrix):
    return np.copy(matrix)
def validate_input_matrix(matrix):
    if matrix is None or len(matrix) == 0:
        raise ValueError("The input matrix cannot be null or empty")
    if not has_valid_rows(matrix):
        raise ValueError("The input matrix cannot have null or empty rows")
def has_valid_rows(matrix):
    for row in matrix:
        if row is None or len(row) == 0:
            return False
    return True
def find_pivot_row(matrix, row_marked, col_index):
    num_rows = len(matrix)
    for pivot_row in range(num_rows):
        if not row_marked[pivot_row] and not is_zero(matrix[pivot_row][col_index]):
            return pivot_row
    return num_rows
def normalize_pivot_row(matrix, pivot_row, col_index):
    num_columns = len(matrix[0])
    for next_col in range(col_index + 1, num_columns):
        matrix[pivot_row][next_col] /= matrix[pivot_row][col_index]
def eliminate_rows(matrix, pivot_row, col_index):
    num_rows = len(matrix)
    num_columns = len(matrix[0])
    for other_row in range(num_rows):
        if other_row!= pivot_row and not is_zero(matrix[other_row][col_index]):
            for col2 in range(col_index + 1, num_columns):
                matrix[other_row][col2] -= matrix[pivot_row][col2] * matrix[other_row][col_index]
if __name__ == "__main__":
    rows = int(input("Enter the number of rows: "))
    cols = int(input("Enter the number of columns: "))
    matrix = []
    for i in range(rows):
        row = list(map(float, input("Enter the elements of row {} (separated by spaces): ".format(i+1)).split()))
        matrix.append(row)
    rank = compute_rank(matrix)
    print("The rank of the matrix is: ", rank)



import numpy as np

def compute_rank(matrix):
    matrix = np.array(matrix) # Convert the input matrix to a NumPy array
    num_rows, num_cols = matrix.shape # Get the number of rows and columns in the matrix
    rank = 0 # Initialize the rank to zero

    row_marked = np.zeros(num_rows, dtype=bool) # Create a boolean array to mark the rows that have been processed
    matrix_copy = matrix.copy() # Create a copy of the input matrix for row elimination

    for col_index in range(num_cols):
        pivot_row = find_pivot_row(matrix_copy, row_marked, col_index) # Find the pivot row for the current column
        if pivot_row!= num_rows: # If a pivot row is found
            rank += 1 # Increment the rank
            row_marked[pivot_row] = True # Mark the pivot row as processed
            normalize_pivot_row(matrix_copy, pivot_row, col_index) # Normalize the pivot row
            eliminate_rows(matrix_copy, pivot_row, col_index) # Eliminate the rows below the pivot row

    return rank # Return the rank of the matrix

def is_zero(value):
    # Helper method to check if a value is zero
    return abs(value) < 1e-10

def deep_copy(matrix):
    num_rows, num_cols = matrix.shape # Get the number of rows and columns in the matrix
    matrix_copy = np.empty((num_rows, num_cols)) # Create a new matrix for the copy

    for row_index in range(num_rows):
        matrix_copy[row_index] = matrix[row_index].copy() # Copy each row to the new matrix

    return matrix_copy # Return the copied matrix

def validate_input_matrix(matrix):
    if matrix is None or len(matrix) == 0: # Check if the input matrix is None or empty
        raise ValueError("The input matrix cannot be None or empty")
    if not has_valid_rows(matrix): # Check if the input matrix has any None or empty rows
        raise ValueError("The input matrix cannot have None or empty rows")

def has_valid_rows(matrix):
    for row in matrix: # Iterate through each row in the matrix
        if row is None or len(row) == 0: # Check if the row is None or empty
            return False
    return True # Return True if all rows are valid

def find_pivot_row(matrix, row_marked, col_index):
    num_rows = matrix.shape[0] # Get the number of rows in the matrix

    for pivot_row in range(num_rows): # Iterate through each row to find the pivot row
        if not row_marked[pivot_row] and not is_zero(matrix[pivot_row, col_index]): # Check if the row is not marked and the pivot element is not zero
            return pivot_row # Return the pivot row index
    return num_rows # Return the number of rows if no pivot row is found

def normalize_pivot_row(matrix, pivot_row, col_index):
    num_cols = matrix.shape[1] # Get the number of columns in the matrix

    for next_col in range(col_index + 1, num_cols): # Iterate through the columns to the right of the pivot column
        matrix[pivot_row, next_col] /= matrix[pivot_row, col_index] # Divide the elements in the pivot row by the pivot element

def eliminate_rows(matrix, pivot_row, col_index):
    num_rows, num_cols = matrix.shape # Get the number of rows and columns in the matrix

    for other_row in range(num_rows): # Iterate through each row below the pivot row
        if other_row!= pivot_row and not is_zero(matrix[other_row, col_index]): # Check if the row is not the pivot row and the pivot element is not zero in this row
            for col2 in range(col_index + 1, num_cols): # Iterate through the columns to the right of the pivot column
                matrix[other_row, col2] -= matrix[pivot_row, col2] * matrix[other_row, col_index] # Subtract the product of the pivot row and the current row times the pivot element from the current row

if __name__ == "__main__":
    num_rows = int(input("Enter the number of rows: ")) # Read the number of rows from the console
    num_cols = int(input("Enter the number of columns: ")) # Read the number of columns from the console
    matrix = [] # Create an empty list to store the input matrix

    for i in range(num_rows): # Iterate through each row in the matrix
        row = [float(input("Enter a value: ")) for _ in range(num_cols)] # Read a double value from the console and store it in the matrix
        matrix.append(row)

    rank = compute_rank(matrix) # Compute the rank of the matrix
    print(f"The rank of the matrix is: {rank}") # Print the rank of the matrix to the console


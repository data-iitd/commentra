
import sys

# A small constant used for floating-point comparison
EPSILON = 1e-10

# Method to compute the rank of a given matrix
def compute_rank(matrix):
    # Validate the input matrix to ensure it is not null or empty
    validate_input_matrix(matrix)
    
    num_rows = len(matrix) # Number of rows in the matrix
    num_columns = len(matrix[0]) # Number of columns in the matrix
    rank = 0 # Initialize rank of the matrix
    row_marked = [False] * num_rows # Array to track marked rows
    matrix_copy = deep_copy(matrix) # Create a deep copy of the matrix for manipulation
    
    # Iterate through each column to find pivot rows and eliminate other rows
    for col_index in range(num_columns):
        pivot_row = find_pivot_row(matrix_copy, row_marked, col_index) # Find a pivot row for the current column
        if pivot_row != num_rows: # If a valid pivot row is found
            rank += 1 # Increment the rank
            row_marked[pivot_row] = True # Mark the pivot row
            normalize_pivot_row(matrix_copy, pivot_row, col_index) # Normalize the pivot row
            eliminate_rows(matrix_copy, pivot_row, col_index) # Eliminate other rows based on the pivot row
    return rank # Return the computed rank of the matrix

# Helper method to check if a value is effectively zero
def is_zero(value):
    return abs(value) < EPSILON # Compare with EPSILON for floating-point precision

# Method to create a deep copy of the input matrix
def deep_copy(matrix):
    num_rows = len(matrix) # Get number of rows
    num_columns = len(matrix[0]) # Get number of columns
    matrix_copy = [[0] * num_columns for _ in range(num_rows)] # Initialize a new matrix for the copy
    
    # Copy each row from the original matrix to the new matrix
    for row_index in range(num_rows):
        for col_index in range(num_columns):
            matrix_copy[row_index][col_index] = matrix[row_index][col_index]
    return matrix_copy # Return the copied matrix

# Method to validate the input matrix for null or empty conditions
def validate_input_matrix(matrix):
    if matrix is None or len(matrix) == 0:
        raise ValueError("The input matrix cannot be null or empty")
    if not has_valid_rows(matrix):
        raise ValueError("The input matrix cannot have null or empty rows")

# Helper method to check if all rows in the matrix are valid (non-null and non-empty)
def has_valid_rows(matrix):
    for row in matrix:
        if row is None or len(row) == 0:
            return False # Return false if any row is null or empty
    return True # All rows are valid

# Method to find a pivot row for the given column index
def find_pivot_row(matrix, row_marked, col_index):
    num_rows = len(matrix) # Get number of rows
    for pivot_row in range(num_rows):
        # Check if the row is not marked and the value is not zero
        if not row_marked[pivot_row] and not is_zero(matrix[pivot_row][col_index]):
            return pivot_row # Return the index of the pivot row
    return num_rows # Return numRows if no pivot row is found

# Method to normalize the pivot row by making the pivot element equal to 1
def normalize_pivot_row(matrix, pivot_row, col_index):
    num_columns = len(matrix[0]) # Get number of columns
    # Normalize the pivot row by dividing each element by the pivot element
    for next_col in range(col_index + 1, num_columns):
        matrix[pivot_row][next_col] /= matrix[pivot_row][col_index]

# Method to eliminate other rows using the pivot row
def eliminate_rows(matrix, pivot_row, col_index):
    num_rows = len(matrix) # Get number of rows
    num_columns = len(matrix[0]) # Get number of columns
    # Iterate through all rows to eliminate values in the current column
    for other_row in range(num_rows):
        if other_row != pivot_row and not is_zero(matrix[other_row][col_index]):
            # Subtract the appropriate multiple of the pivot row from the other row
            for col2 in range(col_index + 1, num_columns):
                matrix[other_row][col2] -= matrix[pivot_row][col2] * matrix[other_row][col_index]

# Main method to execute the program
def main():
    rows = int(input()) # Read number of rows
    cols = int(input()) # Read number of columns
    matrix = [[0] * cols for _ in range(rows)] # Initialize the matrix
    
    # Read the matrix values from input
    for i in range(rows):
        for j in range(cols):
            matrix[i][j] = float(input()) # Fill the matrix with user input
    
    # Compute the rank of the matrix and print the result
    rank = compute_rank(matrix)
    print("The rank of the matrix is: " + str(rank))

if __name__ == "__main__":
    main()


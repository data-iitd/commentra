
import sys

# Define a constant EPSILON for small value comparison
EPSILON = 1e-10

def compute_rank(matrix):
    validate_input_matrix(matrix) # Validate the input matrix
    num_rows = len(matrix) # Get the number of rows in the matrix
    num_columns = len(matrix[0]) # Get the number of columns in the matrix
    rank = 0 # Initialize the rank to zero

    row_marked = [False] * num_rows # Create a boolean array to mark the rows that have been processed
    matrix_copy = deep_copy(matrix) # Create a copy of the input matrix for row elimination

    for col_index in range(num_columns):
        pivot_row = find_pivot_row(matrix_copy, row_marked, col_index) # Find the pivot row for the current column
        if pivot_row!= num_rows: # If a pivot row is found
            rank += 1 # Increment the rank
            row_marked[pivot_row] = True # Mark the pivot row as processed
            normalize_pivot_row(matrix_copy, pivot_row, col_index) # Normalize the pivot row
            eliminate_rows(matrix_copy, pivot_row, col_index) # Eliminate the rows below the pivot row

    return rank # Return the rank of the matrix

def is_zero(value):
    # Helper method to check if a value is zero
    return abs(value) < EPSILON

def deep_copy(matrix):
    num_rows = len(matrix) # Get the number of rows in the matrix
    num_columns = len(matrix[0]) # Get the number of columns in the matrix
    matrix_copy = [[0.0] * num_columns for _ in range(num_rows)] # Create a new matrix for the copy

    for row_index in range(num_rows):
        matrix_copy[row_index] = matrix[row_index].copy() # Copy each row to the new matrix

    return matrix_copy # Return the copied matrix

def validate_input_matrix(matrix):
    if matrix == None or len(matrix) == 0: # Check if the input matrix is null or empty
        raise Exception("The input matrix cannot be null or empty")
    if not has_valid_rows(matrix): # Check if the input matrix has any null or empty rows
        raise Exception("The input matrix cannot have null or empty rows")

def has_valid_rows(matrix):
    for row in matrix: # Iterate through each row in the matrix
        if row == None or len(row) == 0: # Check if the row is null or empty
            return False
    return True # Return true if all rows are valid

def find_pivot_row(matrix, row_marked, col_index):
    num_rows = len(matrix) # Get the number of rows in the matrix

    for pivot_row in range(num_rows): # Iterate through each row to find the pivot row
        if not row_marked[pivot_row] and not is_zero(matrix[pivot_row][col_index]): # Check if the row is not marked and the pivot element is not zero
            return pivot_row # Return the pivot row index
    return num_rows # Return the number of rows if no pivot row is found

def normalize_pivot_row(matrix, pivot_row, col_index):
    num_columns = len(matrix[0]) # Get the number of columns in the matrix

    for next_col in range(col_index + 1, num_columns): # Iterate through the columns to the right of the pivot column
        matrix[pivot_row][next_col] /= matrix[pivot_row][col_index] # Divide the elements in the pivot row by the pivot element

def eliminate_rows(matrix, pivot_row, col_index):
    num_rows = len(matrix) # Get the number of rows in the matrix
    num_columns = len(matrix[0]) # Get the number of columns in the matrix

    for other_row in range(num_rows): # Iterate through each row below the pivot row
        if other_row!= pivot_row and not is_zero(matrix[other_row][col_index]): # Check if the row is not the pivot row and the pivot element is not zero in this row
            for col2 in range(col_index + 1, num_columns): # Iterate through the columns to the right of the pivot column
                matrix[other_row][col2] -= matrix[pivot_row][col2] * matrix[other_row][col_index] # Subtract the product of the pivot row and the current row times the pivot element from the current row

def main():
    input_lines = sys.stdin.read().splitlines() # Read all lines from stdin and save them in a list
    num_rows = int(input_lines[0]) # Read the number of rows from the first line of input
    num_columns = int(input_lines[1]) # Read the number of columns from the second line of input
    matrix = [] # Create a 2D array to store the input matrix

    for i in range(2, 2 + num_rows): # Iterate through each row in the matrix
        matrix.append(list(map(float, input_lines[i].split()))) # Read a double value from the console and store it in the matrix

    rank = compute_rank(matrix) # Compute the rank of the matrix
    print("The rank of the matrix is: " + str(rank)) # Print the rank of the matrix to the console

if __name__ == "__main__":
    main()


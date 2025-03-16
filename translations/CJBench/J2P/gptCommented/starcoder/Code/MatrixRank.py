import sys

# A small constant used for floating-point comparison
EPSILON = 1e-10

# Method to compute the rank of a given matrix
def computeRank(matrix):
    # Validate the input matrix to ensure it is not null or empty
    validateInputMatrix(matrix)
    
    numRows = len(matrix) # Number of rows in the matrix
    numColumns = len(matrix[0]) # Number of columns in the matrix
    rank = 0 # Initialize rank of the matrix
    rowMarked = [False] * numRows # Array to track marked rows
    matrixCopy = deepCopy(matrix) # Create a deep copy of the matrix for manipulation
    
    # Iterate through each column to find pivot rows and eliminate other rows
    for colIndex in range(numColumns):
        pivotRow = findPivotRow(matrixCopy, rowMarked, colIndex) # Find a pivot row for the current column
        if pivotRow!= numRows: # If a valid pivot row is found
            rank += 1 # Increment the rank
            rowMarked[pivotRow] = True # Mark the pivot row
            normalizePivotRow(matrixCopy, pivotRow, colIndex) # Normalize the pivot row
            eliminateRows(matrixCopy, pivotRow, colIndex) # Eliminate other rows based on the pivot row
    return rank # Return the computed rank of the matrix

# Helper method to check if a value is effectively zero
def isZero(value):
    return abs(value) < EPSILON # Compare with EPSILON for floating-point precision

# Method to create a deep copy of the input matrix
def deepCopy(matrix):
    numRows = len(matrix) # Get number of rows
    numColumns = len(matrix[0]) # Get number of columns
    matrixCopy = [[0.0] * numColumns for i in range(numRows)] # Initialize a new matrix for the copy
    
    # Copy each row from the original matrix to the new matrix
    for rowIndex in range(numRows):
        matrixCopy[rowIndex] = matrix[rowIndex][:]
    return matrixCopy # Return the copied matrix

# Method to validate the input matrix for null or empty conditions
def validateInputMatrix(matrix):
    if matrix == None or len(matrix) == 0:
        raise Exception("The input matrix cannot be null or empty")
    if not hasValidRows(matrix):
        raise Exception("The input matrix cannot have null or empty rows")

# Helper method to check if all rows in the matrix are valid (non-null and non-empty)
def hasValidRows(matrix):
    for row in matrix:
        if row == None or len(row) == 0:
            return False # Return false if any row is null or empty
    return True # All rows are valid

# Method to find a pivot row for the given column index
def findPivotRow(matrix, rowMarked, colIndex):
    numRows = len(matrix) # Get number of rows
    for pivotRow in range(numRows):
        # Check if the row is not marked and the value is not zero
        if not rowMarked[pivotRow] and not isZero(matrix[pivotRow][colIndex]):
            return pivotRow # Return the index of the pivot row
    return numRows # Return numRows if no pivot row is found

# Method to normalize the pivot row by making the pivot element equal to 1
def normalizePivotRow(matrix, pivotRow, colIndex):
    numColumns = len(matrix[0]) # Get number of columns
    # Normalize the pivot row by dividing each element by the pivot element
    for nextCol in range(colIndex + 1, numColumns):
        matrix[pivotRow][nextCol] /= matrix[pivotRow][colIndex]

# Method to eliminate other rows using the pivot row
def eliminateRows(matrix, pivotRow, colIndex):
    numRows = len(matrix) # Get number of rows
    numColumns = len(matrix[0]) # Get number of columns
    # Iterate through all rows to eliminate values in the current column
    for otherRow in range(numRows):
        if otherRow!= pivotRow and not isZero(matrix[otherRow][colIndex]):
            # Subtract the appropriate multiple of the pivot row from the other row
            for col2 in range(colIndex + 1, numColumns):
                matrix[otherRow][col2] -= matrix[pivotRow][col2] * matrix[otherRow][colIndex]

# Main method to execute the program
def main():
    # Read number of rows and columns from input
    rows = int(input())
    cols = int(input())
    matrix = [] # Initialize the matrix
    
    # Read the matrix values from input
    for i in range(rows):
        matrix.append([float(x) for x in input().split()])
    
    # Compute the rank of the matrix and print the result
    rank = computeRank(matrix)
    print("The rank of the matrix is: " + str(rank))

# Entry point of the program
if __name__ == "__main__":
    main()


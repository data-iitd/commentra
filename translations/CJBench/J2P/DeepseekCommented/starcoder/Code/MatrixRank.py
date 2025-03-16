import sys
import math

# Constant for floating-point precision
EPSILON = 1e-10

# Main method to read matrix from input and compute its rank
def main():
    # Read number of rows
    numRows = int(input())
    # Read number of columns
    numColumns = int(input())
    # Read matrix elements
    matrix = []
    for i in range(numRows):
        matrix.append([float(x) for x in input().split()])
    # Compute the rank of the matrix
    rank = computeRank(matrix)
    # Print the rank
    print("The rank of the matrix is: " + str(rank))

# Method to compute the rank of a matrix
def computeRank(matrix):
    validateInputMatrix(matrix) # Validate the input matrix
    numRows = len(matrix)
    numColumns = len(matrix[0])
    rank = 0
    rowMarked = [False] * numRows
    matrixCopy = deepCopy(matrix)
    for colIndex in range(numColumns):
        pivotRow = findPivotRow(matrixCopy, rowMarked, colIndex)
        if pivotRow!= numRows:
            rank += 1
            rowMarked[pivotRow] = True
            normalizePivotRow(matrixCopy, pivotRow, colIndex)
            eliminateRows(matrixCopy, pivotRow, colIndex)
    return rank

# Check if a value is effectively zero
def isZero(value):
    return abs(value) < EPSILON

# Create a deep copy of the matrix
def deepCopy(matrix):
    numRows = len(matrix)
    numColumns = len(matrix[0])
    matrixCopy = [[0.0] * numColumns for i in range(numRows)]
    for rowIndex in range(numRows):
        for colIndex in range(numColumns):
            matrixCopy[rowIndex][colIndex] = matrix[rowIndex][colIndex]
    return matrixCopy

# Validate the input matrix to ensure it is not null or empty and has valid rows
def validateInputMatrix(matrix):
    if matrix == None or len(matrix) == 0:
        raise Exception("The input matrix cannot be null or empty")
    if not hasValidRows(matrix):
        raise Exception("The input matrix cannot have null or empty rows")

# Check if all rows in the matrix are non-null and non-empty
def hasValidRows(matrix):
    for row in matrix:
        if row == None or len(row) == 0:
            return False
    return True

# Find the first non-zero entry in the current column
def findPivotRow(matrix, rowMarked, colIndex):
    numRows = len(matrix)
    for pivotRow in range(numRows):
        if not rowMarked[pivotRow] and not isZero(matrix[pivotRow][colIndex]):
            return pivotRow
    return numRows

# Normalize the pivot row by dividing all elements by the pivot element
def normalizePivotRow(matrix, pivotRow, colIndex):
    numColumns = len(matrix[0])
    for nextCol in range(colIndex + 1, numColumns):
        matrix[pivotRow][nextCol] /= matrix[pivotRow][colIndex]

# Eliminate other rows by subtracting a multiple of the pivot row
def eliminateRows(matrix, pivotRow, colIndex):
    numRows = len(matrix)
    numColumns = len(matrix[0])
    for otherRow in range(numRows):
        if otherRow!= pivotRow and not isZero(matrix[otherRow][colIndex]):
            for col2 in range(colIndex + 1, numColumns):
                matrix[otherRow][col2] -= matrix[pivotRow][col2] * matrix[otherRow][colIndex]

# Start the execution if it's the main script
if __name__ == "__main__":
    main()

# 
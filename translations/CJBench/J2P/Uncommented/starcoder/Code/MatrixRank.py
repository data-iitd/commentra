import sys
import math

def computeRank(matrix):
    validateInputMatrix(matrix)
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

def isZero(value):
    return math.fabs(value) < 1e-10

def deepCopy(matrix):
    numRows = len(matrix)
    numColumns = len(matrix[0])
    matrixCopy = [[0.0] * numColumns for i in range(numRows)]
    for rowIndex in range(numRows):
        matrixCopy[rowIndex] = matrix[rowIndex][:]
    return matrixCopy

def validateInputMatrix(matrix):
    if matrix == None or len(matrix) == 0:
        raise Exception("The input matrix cannot be null or empty")
    if not hasValidRows(matrix):
        raise Exception("The input matrix cannot have null or empty rows")

def hasValidRows(matrix):
    for row in matrix:
        if row == None or len(row) == 0:
            return False
    return True

def findPivotRow(matrix, rowMarked, colIndex):
    numRows = len(matrix)
    for pivotRow in range(numRows):
        if not rowMarked[pivotRow] and not isZero(matrix[pivotRow][colIndex]):
            return pivotRow
    return numRows

def normalizePivotRow(matrix, pivotRow, colIndex):
    numColumns = len(matrix[0])
    for nextCol in range(colIndex + 1, numColumns):
        matrix[pivotRow][nextCol] /= matrix[pivotRow][colIndex]

def eliminateRows(matrix, pivotRow, colIndex):
    numRows = len(matrix)
    numColumns = len(matrix[0])
    for otherRow in range(numRows):
        if otherRow!= pivotRow and not isZero(matrix[otherRow][colIndex]):
            for col2 in range(colIndex + 1, numColumns):
                matrix[otherRow][col2] -= matrix[pivotRow][col2] * matrix[otherRow][colIndex]

def main():
    matrix = []
    for i in range(int(raw_input())):
        matrix.append(map(float, raw_input().split()))
    rank = computeRank(matrix)
    print "The rank of the matrix is: " + str(rank)

if __name__ == "__main__":
    main()


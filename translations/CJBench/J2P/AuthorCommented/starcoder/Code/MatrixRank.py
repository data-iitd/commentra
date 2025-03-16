import sys

class Main:
    def __init__(self):
        pass

    @staticmethod
    def computeRank(matrix):
        if matrix is None or len(matrix) == 0:
            raise ValueError("The input matrix cannot be null or empty")
        if not Main.hasValidRows(matrix):
            raise ValueError("The input matrix cannot have null or empty rows")

        numRows = len(matrix)
        numColumns = len(matrix[0])
        rank = 0

        rowMarked = [False] * numRows

        matrixCopy = Main.deepCopy(matrix)

        for colIndex in range(numColumns):
            pivotRow = Main.findPivotRow(matrixCopy, rowMarked, colIndex)
            if pivotRow!= numRows:
                rank += 1
                rowMarked[pivotRow] = True
                Main.normalizePivotRow(matrixCopy, pivotRow, colIndex)
                Main.eliminateRows(matrixCopy, pivotRow, colIndex)

        return rank

    @staticmethod
    def isZero(value):
        return abs(value) < 1e-10

    @staticmethod
    def deepCopy(matrix):
        numRows = len(matrix)
        numColumns = len(matrix[0])
        matrixCopy = [[0.0] * numColumns for _ in range(numRows)]
        for rowIndex in range(numRows):
            for colIndex in range(numColumns):
                matrixCopy[rowIndex][colIndex] = matrix[rowIndex][colIndex]
        return matrixCopy

    @staticmethod
    def hasValidRows(matrix):
        for row in matrix:
            if row is None or len(row) == 0:
                return False
        return True

    @staticmethod
    def findPivotRow(matrix, rowMarked, colIndex):
        numRows = len(matrix)
        for pivotRow in range(numRows):
            if not rowMarked[pivotRow] and not Main.isZero(matrix[pivotRow][colIndex]):
                return pivotRow
        return numRows

    @staticmethod
    def normalizePivotRow(matrix, pivotRow, colIndex):
        numColumns = len(matrix[0])
        for nextCol in range(colIndex + 1, numColumns):
            matrix[pivotRow][nextCol] /= matrix[pivotRow][colIndex]

    @staticmethod
    def eliminateRows(matrix, pivotRow, colIndex):
        numRows = len(matrix)
        numColumns = len(matrix[0])
        for otherRow in range(numRows):
            if otherRow!= pivotRow and not Main.isZero(matrix[otherRow][colIndex]):
                for col2 in range(colIndex + 1, numColumns):
                    matrix[otherRow][col2] -= matrix[pivotRow][col2] * matrix[otherRow][colIndex]

    def main(self):
        sc = sys.stdin
        rows = int(sc.readline())
        cols = int(sc.readline())

        matrix = [[0.0] * cols for _ in range(rows)]

        for i in range(rows):
            for j in range(cols):
                matrix[i][j] = float(sc.readline())

        rank = Main.computeRank(matrix)
        print("The rank of the matrix is: " + str(rank))

        sc.close()

# 
import sys

# Private static arrays to store the results and intermediate values
m = []
s = []
p = []

# Method to calculate the minimum number of multiplications required to multiply the matrices
def calculateMatrixChainOrder(matrices):
    size = len(matrices)
    # Initialize the arrays m and s with maximum integer values and -1 respectively
    for i in range(size + 1):
        m.append([])
        s.append([])
        for j in range(size + 1):
            m[i].append(sys.maxsize)
            s[i].append(-1)
    # Fill the p array with the dimensions of the matrices
    p.append(matrices[0].row())
    for i in range(1, size):
        p.append(matrices[i - 1].col())
    # Perform the dynamic programming approach to find the optimal parenthesization
    matrixChainOrder(size)
    return Result(m, s)

# Method to perform the dynamic programming approach to find the optimal parenthesization
def matrixChainOrder(size):
    for i in range(1, size + 1):
        m[i][i] = 0  # No multiplication cost for single matrix
    for l in range(2, size + 1):  # Iterate over the chain length
        for i in range(1, size - l + 2):
            j = i + l - 1
            m[i][j] = sys.maxsize
            for k in range(i, j):
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k

# Class to encapsulate the results of the matrix chain multiplication
class Result:
    def __init__(self, m, s):
        self.m = m
        self.s = s

# Class to represent a matrix with a count, number of columns, and number of rows
class Matrix:
    def __init__(self, count, col, row):
        self.count = count
        self.col = col
        self.row = row

# Main method to read the number of matrices and their dimensions from the input
def main():
    n = int(input())
    matrices = []
    for i in range(1, n + 1):
        rows = int(input())
        cols = int(input())
        matrices.append(Matrix(i, cols, rows))
    result = calculateMatrixChainOrder(matrices)
    print("Minimum number of multiplications: " + str(result.m[1][n]))

if __name__ == "__main__":
    main()


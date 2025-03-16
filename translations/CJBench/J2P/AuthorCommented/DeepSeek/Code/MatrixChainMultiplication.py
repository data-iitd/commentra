import sys
import numpy as np

class Matrix:
    def __init__(self, count, col, row):
        self.count = count
        self.col = col
        self.row = row

class Result:
    def __init__(self, m, s):
        self.m = m
        self.s = s

def calculateMatrixChainOrder(matrices):
    size = len(matrices)
    m = np.full((size + 1, size + 1), float('inf'))
    s = np.full((size + 1, size + 1), -1)
    p = [0] * (size + 1)

    for i in range(size + 1):
        m[i][i] = 0

    p[0] = matrices[0].row
    for i in range(1, size + 1):
        p[i] = matrices[i - 1].col

    matrixChainOrder(size, m, s, p)
    return Result(m, s)

def matrixChainOrder(size, m, s, p):
    for l in range(2, size + 1):
        for i in range(1, size - l + 2):
            j = i + l - 1
            m[i][j] = float('inf')
            for k in range(i, j):
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k

def printOptimalParenthesis(s, i, j):
    if i == j:
        print(f"M{i}", end='')
    else:
        print("(", end='')
        printOptimalParenthesis(s, i, s[i][j])
        printOptimalParenthesis(s, s[i][j] + 1, j)
        print(")", end='')

if __name__ == "__main__":
    n = int(input().strip())
    matrices = []
    for i in range(1, n + 1):
        rows = int(input().strip())
        cols = int(input().strip())
        matrices.append(Matrix(i, cols, rows))

    result = calculateMatrixChainOrder(matrices)
    print("Minimum number of multiplications:", result.m[1][n])
    printOptimalParenthesis(result.s, 1, n)

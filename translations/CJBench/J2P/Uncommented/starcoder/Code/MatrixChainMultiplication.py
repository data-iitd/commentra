
import sys
import math

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
    m = [[sys.maxsize] * (size + 1) for _ in range(size + 1)]
    s = [[-1] * (size + 1) for _ in range(size + 1)]
    p = [0] * (size + 1)
    p[0] = matrices[0].row
    for i in range(1, size + 1):
        p[i] = matrices[i - 1].col
    for i in range(1, size + 1):
        m[i][i] = 0
    for l in range(2, size + 1):
        for i in range(1, size - l + 2):
            j = i + l - 1
            m[i][j] = sys.maxsize
            for k in range(i, j):
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k
    return Result(m, s)

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


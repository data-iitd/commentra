import sys
import numpy as np

class Matrix:
    def __init__(self, count, col, row):
        self.count = count
        self.col = col
        self.row = row

    def count(self):
        return self.count

    def col(self):
        return self.col

    def row(self):
        return self.row

class Result:
    def __init__(self, m, s):
        self.m = m
        self.s = s

    def get_m(self):
        return self.m

    def get_s(self):
        return self.s

def calculate_matrix_chain_order(matrices):
    size = len(matrices)
    m = np.full((size + 1, size + 1), float('inf'))
    s = np.full((size + 1, size + 1), -1)
    p = [0] * (size + 1)
    p[0] = matrices[0].row()
    for i in range(1, size + 1):
        p[i] = matrices[i - 1].col()
    matrix_chain_order(size, m, s, p)
    return Result(m, s)

def matrix_chain_order(size, m, s, p):
    for i in range(1, size + 1):
        m[i][i] = 0
    for l in range(2, size + 1):
        for i in range(1, size - l + 2):
            j = i + l - 1
            m[i][j] = float('inf')
            for k in range(i, j):
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    matrices = []
    for i in range(1, n + 1):
        rows, cols = map(int, sys.stdin.readline().strip().split())
        matrices.append(Matrix(i, cols, rows))
    result = calculate_matrix_chain_order(matrices)
    print("Minimum number of multiplications:", result.get_m()[1][n])

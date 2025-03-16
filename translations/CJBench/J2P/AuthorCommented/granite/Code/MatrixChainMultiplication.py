

import sys

class Matrix:
    def __init__(self, count, col, row):
        self.count = count
        self.col = col
        self.row = row

def calculate_matrix_chain_order(matrices):
    size = len(matrices)
    m = [[sys.maxsize for _ in range(size + 1)] for _ in range(size + 1)]
    s = [[-1 for _ in range(size + 1)] for _ in range(size + 1)]
    p = [0] * (size + 1)

    for i in range(size + 1):
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

    return m, s

def main():
    n = int(input())

    matrices = []
    for i in range(1, n + 1):
        rows, cols = map(int, input().split())
        matrices.append(Matrix(i, cols, rows))

    m, s = calculate_matrix_chain_order(matrices)
    print("Minimum number of multiplications:", m[1][n])

if __name__ == "__main__":
    main()


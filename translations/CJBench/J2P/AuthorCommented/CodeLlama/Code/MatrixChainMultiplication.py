
import sys

# Matrices to store minimum multiplication costs and split points
m = [[0 for _ in range(sys.maxsize)] for _ in range(sys.maxsize)]
s = [[0 for _ in range(sys.maxsize)] for _ in range(sys.maxsize)]
p = [0 for _ in range(sys.maxsize)]

def calculate_matrix_chain_order(matrices):
    size = len(matrices)
    for i in range(size + 1):
        for j in range(size + 1):
            m[i][j] = sys.maxsize
            s[i][j] = -1

    for i in range(size + 1):
        p[i] = matrices[i - 1][0]

    matrix_chain_order(size)
    return m, s

def matrix_chain_order(size):
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

def main():
    n = int(input())

    matrices = []
    for i in range(n):
        rows, cols = map(int, input().split())
        matrices.append([cols, rows])

    m, s = calculate_matrix_chain_order(matrices)
    print("Minimum number of multiplications:", m[1][n])

if __name__ == "__main__":
    main()


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

def calculate_matrix_chain_order(matrices):
    size = len(matrices)
    
    # Initialize the matrices for storing minimum costs and split points
    m = np.full((size + 1, size + 1), float('inf'))
    s = np.full((size + 1, size + 1), -1)
    p = [0] * (size + 1)

    # Set the dimensions of the matrices in the array p
    p[0] = matrices[0].row
    for i in range(1, size + 1):
        p[i] = matrices[i - 1].col

    # Calculate the matrix chain order
    matrix_chain_order(size, m, s, p)
    return Result(m, s)

def matrix_chain_order(size, m, s, p):
    # Initialize the diagonal of m to 0 (cost of multiplying one matrix)
    for i in range(1, size + 1):
        m[i][i] = 0

    # l is the chain length
    for l in range(2, size + 1):
        # i is the starting index of the chain
        for i in range(1, size - l + 2):
            j = i + l - 1  # j is the ending index of the chain
            for k in range(i, j):
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]
                # Update m[i][j] and s[i][j] if a lower cost is found
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k

def main():
    # Read the number of matrices
    n = int(sys.stdin.readline().strip())
    matrices = []

    # Read the dimensions of each matrix and store them
    for i in range(1, n + 1):
        rows, cols = map(int, sys.stdin.readline().strip().split())
        matrices.append(Matrix(i, cols, rows))

    # Calculate the optimal matrix chain order
    result = calculate_matrix_chain_order(matrices)
    
    # Output the minimum number of multiplications required
    print("Minimum number of multiplications:", result.m[1][n])

if __name__ == "__main__":
    main()


import sys

# Class definition for the Matrix class, which represents a single matrix with its number, columns, and rows
class Matrix:
    def __init__(self, count, col, row):
        self.count = count
        self.col = col
        self.row = row

# Static method for calculating the matrix chain order using dynamic programming
def calculate_matrix_chain_order(matrices):
    size = len(matrices) # Get the size of the list of matrices

    # Initialize 2D arrays m and s, and 1D array p for storing intermediate results and lengths of matrices
    m = [[sys.maxsize for _ in range(size + 1)] for _ in range(size + 1)]
    s = [[-1 for _ in range(size + 1)] for _ in range(size + 1)]
    p = [0] * (size + 1)

    # Initialize all elements of m and s with maximum values and -1 for s, respectively
    for i in range(size + 1):
        for j in range(size + 1):
            m[i][j] = sys.maxsize
            s[i][j] = -1

    # Initialize the p array with the number of columns of each matrix
    for i in range(size + 1):
        if matrices[i - 1] is not None:
            p[i] = matrices[i - 1].col

    # Call the matrix_chain_order method to calculate the minimum number of multiplications
    matrix_chain_order(size, m, s, p)

    # Return a Result object containing the m and s arrays
    return Result(m, s)

# Recursive method for calculating the matrix chain order using dynamic programming
def matrix_chain_order(size, m, s, p):
    # Initialize the first diagonal elements of the m array with 0
    for i in range(1, size + 1):
        m[i][i] = 0

    # Iterate through all possible submatrices of size l <= size
    for l in range(2, size + 1):
        # Iterate through all possible starting indices i and ending indices j of submatrices of size l
        for i in range(1, size - l + 2):
            j = i + l - 1

            # Initialize the minimum cost for the current submatrix with a large value
            m[i][j] = sys.maxsize

            # Iterate through all possible splitting indices k of the submatrix
            for k in range(i, j):
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]
                # Update the minimum cost if a better solution is found
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k

# Class definition for the Result class, which stores the m and s arrays as fields
class Result:
    def __init__(self, m, s):
        self.m = m
        self.s = s

# Main method for reading input and calling the calculate_matrix_chain_order method
def main():
    input = sys.stdin.read() # Read the input from the standard input
    data = list(map(int, input.split())) # Split the input into a list of integers

    n = data[0] # Get the number of matrices from the input

    matrices = [] # Create an empty list for storing the matrices

    for i in range(1, n + 1): # Iterate through all matrices and add them to the list
        matrices.append(Matrix(i, data[2 * i - 1], data[2 * i]))

    result = calculate_matrix_chain_order(matrices) # Call the calculate_matrix_chain_order method and store the result in a Result object

    print("Minimum number of multiplications:", result.m[1][n]) # Print the minimum number of multiplications to the standard output

if __name__ == "__main__":
    main()


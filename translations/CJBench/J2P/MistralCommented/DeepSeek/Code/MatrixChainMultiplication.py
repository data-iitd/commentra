import sys

# Class definition for the Matrix class, which represents a single matrix with its number, columns, and rows
class Matrix:
    def __init__(self, count, col, row):
        self.count = count
        self.col = col
        self.row = row

    # Getter methods for the number of matrices, columns, and rows
    def count(self):
        return self.count

    def col(self):
        return self.col

    def row(self):
        return self.row

# Class definition for the Result class, which stores the m and s arrays as fields
class Result:
    def __init__(self, m, s):
        self.m = m
        self.s = s

    # Getter methods for the m and s arrays
    def get_m(self):
        return self.m

    def get_s(self):
        return self.s

# Function for calculating the matrix chain order using dynamic programming
def calculate_matrix_chain_order(matrices):
    size = len(matrices)  # Get the size of the list of matrices

    # Initialize the m, s, and p arrays with default values
    m = [[float('inf') for _ in range(size + 1)] for _ in range(size + 1)]
    s = [[-1 for _ in range(size + 1)] for _ in range(size + 1)]
    p = [0] * (size + 1)

    # Initialize the p array with the number of columns of each matrix
    for i in range(size + 1):
        p[i] = matrices[i - 1].col() if i > 0 else 0

    # Call the matrix_chain_order function to calculate the minimum number of multiplications
    matrix_chain_order(size, m, s, p)

    # Return a Result object containing the m and s arrays
    return Result(m, s)

# Recursive function for calculating the matrix chain order using dynamic programming
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
            m[i][j] = float('inf')

            # Iterate through all possible splitting indices k of the submatrix
            for k in range(i, j):
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]
                # Update the minimum cost if a better solution is found
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k

# Main function for reading input and calling the calculate_matrix_chain_order method
def main():
    # Read the number of matrices from the input
    n = int(sys.stdin.readline().strip())

    # Create an empty list for storing the matrices
    matrices = []

    # Iterate through all matrices and add them to the list
    for i in range(1, n + 1):
        rows, cols = map(int, sys.stdin.readline().strip().split())
        matrices.append(Matrix(i, cols, rows))

    # Call the calculate_matrix_chain_order method and store the result in a Result object
    result = calculate_matrix_chain_order(matrices)

    # Print the minimum number of multiplications to the output
    print("Minimum number of multiplications:", result.get_m()[1][n])

# Call the main function
if __name__ == "__main__":
    main()

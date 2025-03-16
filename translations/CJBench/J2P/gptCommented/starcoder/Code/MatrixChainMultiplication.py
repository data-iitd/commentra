import sys

# Class to hold the result of the matrix chain multiplication calculation
class Result:
    def __init__(self, m, s):
        self.m = m
        self.s = s

    # Getter for the cost matrix
    def getM(self):
        return self.m

    # Getter for the split points matrix
    def getS(self):
        return self.s

# Class to represent a matrix with its dimensions
class Matrix:
    def __init__(self, count, col, row):
        self.count = count
        self.col = col
        self.row = row

    # Getter for the count
    def count(self):
        return self.count

    # Getter for the number of columns
    def col(self):
        return self.col

    # Getter for the number of rows
    def row(self):
        return self.row

# Method to calculate the optimal order of matrix multiplication
def calculateMatrixChainOrder(matrices):
    size = len(matrices)

    # Initialize the matrices for storing minimum costs and split points
    m = [[sys.maxsize] * (size + 1) for _ in range(size + 1)]
    s = [[-1] * (size + 1) for _ in range(size + 1)]
    p = [0] * (size + 1)

    # Fill the matrices with initial values
    for i in range(size + 1):
        m[i][i] = 0
        for j in range(size + 1):
            s[i][j] = -1

    # Set the dimensions of the matrices in the array p
    p[0] = matrices[0].row()
    for i in range(1, size + 1):
        p[i] = matrices[i - 1].col()

    # Calculate the matrix chain order
    matrixChainOrder(size, matrices, m, s, p)
    return Result(m, s) # Return the result containing m and s matrices

# Method to compute the matrix chain order using dynamic programming
def matrixChainOrder(size, matrices, m, s, p):
    # Initialize the diagonal of m to 0 (cost of multiplying one matrix)
    for i in range(1, size + 1):
        m[i][i] = 0

    # l is the chain length
    for l in range(2, size + 1):
        # i is the starting index of the chain
        for i in range(1, size - l + 2):
            j = i + l - 1 # j is the ending index of the chain
            m[i][j] = sys.maxsize # Initialize to max value

            # Try different split points to find the minimum cost
            for k in range(i, j):
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]
                # Update m[i][j] and s[i][j] if a lower cost is found
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k

# Main method to execute the program
def main():
    # Read the number of matrices
    n = int(input())
    matrices = []

    # Read the dimensions of each matrix and store them
    for i in range(1, n + 1):
        rows = int(input())
        cols = int(input())
        matrices.append(Matrix(i, cols, rows))

    # Calculate the optimal matrix chain order
    result = calculateMatrixChainOrder(matrices)
    
    # Output the minimum number of multiplications required
    print("Minimum number of multiplications: " + str(result.getM()[1][n]))

# Entry point of the program
if __name__ == "__main__":
    main()

# 
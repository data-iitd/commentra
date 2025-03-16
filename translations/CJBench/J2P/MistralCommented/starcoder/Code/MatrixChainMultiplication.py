import sys

# Class definition for the Main class, which contains the main logic for calculating the matrix chain order
class Main:
    # Declare and initialize 2D arrays m and s, and 1D array p for storing intermediate results and lengths of matrices
    m = []
    s = []
    p = []

    # Static method for calculating the matrix chain order using dynamic programming
    @staticmethod
    def calculateMatrixChainOrder(matrices):
        size = len(matrices) # Get the size of the list of matrices

        # Initialize the m, s, and p arrays with default values
        for i in range(size + 1):
            Main.m.append([0] * (size + 1))
            Main.s.append([0] * (size + 1))
            Main.p.append(0)

        # Initialize all elements of m and s with maximum values and -1 for s, respectively
        for i in range(size + 1):
            for j in range(size + 1):
                Main.m[i][j] = sys.maxsize
                Main.s[i][j] = -1

        # Initialize the p array with the number of columns of each matrix
        for i in range(size + 1):
            Main.p[i] = matrices[i - 1] == None? 0 : matrices[i - 1].col()

        # Call the matrixChainOrder method to calculate the minimum number of multiplications
        Main.matrixChainOrder(size)

        # Return a Result object containing the m and s arrays
        return Result(Main.m, Main.s)

    # Recursive method for calculating the matrix chain order using dynamic programming
    @staticmethod
    def matrixChainOrder(size):
        # Initialize the first diagonal elements of the m array with 0
        for i in range(1, size + 1):
            Main.m[i][i] = 0

        # Iterate through all possible submatrices of size l <= size
        for l in range(2, size + 1):
            # Iterate through all possible starting indices i and ending indices j of submatrices of size l
            for i in range(1, size - l + 2):
                j = i + l - 1

                # Initialize the minimum cost for the current submatrix with a large value
                Main.m[i][j] = sys.maxsize

                # Iterate through all possible splitting indices k of the submatrix
                for k in range(i, j):
                    q = Main.m[i][k] + Main.m[k + 1][j] + Main.p[i - 1] * Main.p[k] * Main.p[j]
                    # Update the minimum cost if a better solution is found
                    if q < Main.m[i][j]:
                        Main.m[i][j] = q
                        Main.s[i][j] = k

    # Class definition for the Result class, which stores the m and s arrays as fields
    class Result:
        def __init__(self, m, s):
            self.m = m
            self.s = s

        # Getter methods for the m and s arrays
        def getM(self):
            return self.m

        def getS(self):
            return self.s

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

# Main method for reading input and calling the calculateMatrixChainOrder method
if __name__ == "__main__":
    scanner = sys.stdin # Create a Scanner object for reading input

    n = int(scanner.readline()) # Read the number of matrices from the input

    matrices = [] # Create an empty list for storing the matrices

    for i in range(1, n + 1): # Iterate through all matrices and add them to the list
        rows = int(scanner.readline())
        cols = int(scanner.readline())
        matrices.append(Matrix(i, cols, rows))

    result = Main.calculateMatrixChainOrder(matrices) # Call the calculateMatrixChainOrder method and store the result in a Result object

    print("Minimum number of multiplications: " + str(result.getM()[1][n])) # Print the minimum number of multiplications to the output

    scanner.close() # Close the Scanner object


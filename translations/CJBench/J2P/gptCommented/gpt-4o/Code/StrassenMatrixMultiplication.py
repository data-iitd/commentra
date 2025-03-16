class Strassen:
    # Method to multiply two matrices using Strassen's algorithm
    def multiply(self, a, b):
        n = len(a)  # Get the size of the matrices (assuming square matrices)
        mat = [[0] * n for _ in range(n)]  # Initialize the resultant matrix

        # Base case for recursion: if the matrix size is 1
        if n == 1:
            mat[0][0] = a[0][0] * b[0][0]  # Multiply the single elements
        else:
            # Create submatrices for a and b
            mid = n // 2
            a11 = [[0] * mid for _ in range(mid)]
            a12 = [[0] * mid for _ in range(mid)]
            a21 = [[0] * mid for _ in range(mid)]
            a22 = [[0] * mid for _ in range(mid)]
            b11 = [[0] * mid for _ in range(mid)]
            b12 = [[0] * mid for _ in range(mid)]
            b21 = [[0] * mid for _ in range(mid)]
            b22 = [[0] * mid for _ in range(mid)]

            # Split matrices a and b into submatrices
            self.split(a, a11, 0, 0)
            self.split(a, a12, 0, mid)
            self.split(a, a21, mid, 0)
            self.split(a, a22, mid, mid)
            self.split(b, b11, 0, 0)
            self.split(b, b12, 0, mid)
            self.split(b, b21, mid, 0)
            self.split(b, b22, mid, mid)

            # Calculate the 7 products using Strassen's formulas
            m1 = self.multiply(self.add(a11, a22), self.add(b11, b22))
            m2 = self.multiply(self.add(a21, a22), b11)
            m3 = self.multiply(a11, self.sub(b12, b22))
            m4 = self.multiply(a22, self.sub(b21, b11))
            m5 = self.multiply(self.add(a11, a12), b22)
            m6 = self.multiply(self.sub(a21, a11), self.add(b11, b12))
            m7 = self.multiply(self.sub(a12, a22), self.add(b21, b22))

            # Combine the results into the resultant matrix
            c11 = self.add(self.sub(self.add(m1, m4), m5), m7)
            c12 = self.add(m3, m5)
            c21 = self.add(m2, m4)
            c22 = self.add(self.sub(self.add(m1, m3), m2), m6)

            # Join the submatrices into the final result matrix
            self.join(c11, mat, 0, 0)
            self.join(c12, mat, 0, mid)
            self.join(c21, mat, mid, 0)
            self.join(c22, mat, mid, mid)

        return mat  # Return the resultant matrix

    # Method to subtract two matrices
    def sub(self, a, b):
        n = len(a)  # Get the size of the matrices
        c = [[0] * n for _ in range(n)]  # Initialize the resultant matrix for subtraction
        # Perform element-wise subtraction
        for i in range(n):
            for j in range(n):
                c[i][j] = a[i][j] - b[i][j]
        return c  # Return the resultant matrix

    # Method to add two matrices
    def add(self, a, b):
        n = len(a)  # Get the size of the matrices
        c = [[0] * n for _ in range(n)]  # Initialize the resultant matrix for addition
        # Perform element-wise addition
        for i in range(n):
            for j in range(n):
                c[i][j] = a[i][j] + b[i][j]
        return c  # Return the resultant matrix

    # Method to split a matrix into a submatrix
    def split(self, p, c, iB, jB):
        # Copy elements from matrix p to submatrix c
        for i1 in range(len(c)):
            for j1 in range(len(c)):
                c[i1][j1] = p[iB + i1][jB + j1]

    # Method to join a submatrix into a larger matrix
    def join(self, c, p, iB, jB):
        # Copy elements from submatrix c to matrix p
        for i1 in range(len(c)):
            for j1 in range(len(c)):
                p[iB + i1][jB + j1] = c[i1][j1]

# Main method to execute the program
if __name__ == "__main__":
    n = int(input("Enter the size of the matrices: "))  # Read the size of the matrices
    a = [[0] * n for _ in range(n)]  # Initialize the first matrix
    b = [[0] * n for _ in range(n)]  # Initialize the second matrix

    # Read elements for the first matrix
    print("Enter elements for the first matrix:")
    for i in range(n):
        a[i] = list(map(int, input().split()))

    # Read elements for the second matrix
    print("Enter elements for the second matrix:")
    for i in range(n):
        b[i] = list(map(int, input().split()))

    # Create an instance of Strassen to use the multiply method
    strassen = Strassen()
    result = strassen.multiply(a, b)  # Multiply the two matrices

    # Print the resultant matrix
    print("Resultant Matrix:")
    for row in result:
        print(" ".join(map(str, row)))  # Print each row

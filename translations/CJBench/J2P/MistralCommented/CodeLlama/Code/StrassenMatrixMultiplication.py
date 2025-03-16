
# Import the Scanner class from the java.util package
from java.util import Scanner

# Class definition for the Main class
class Main:

    # Method definition for matrix multiplication
    def multiply(self, a, b):
        n = len(a) # Get the size of the matrices
        mat = [[0] * n for _ in range(n)] # Initialize a new matrix to store the result

        # Base case: when the size of the matrix is 1x1
        if n == 1:
            mat[0][0] = a[0][0] * b[0][0] # Multiply the elements and store the result in the matrix
        else: # Recursive case: when the size of the matrix is greater than 1x1
            a11, a12, a21, a22, b11, b12, b21, b22 = [[0] * n for _ in range(n)], [[0] * n for _ in range(n)], [[0] * n for _ in range(n)], [[0] * n for _ in range(n)], [[0] * n for _ in range(n)], [[0] * n for _ in range(n)], [[0] * n for _ in range(n)], [[0] * n for _ in range(n)] # Initialize 8 sub-matrices

            # Split the given matrices into 4 sub-matrices
            self.split(a, a11, 0, 0)
            self.split(a, a12, 0, n // 2)
            self.split(a, a21, n // 2, 0)
            self.split(a, a22, n // 2, n // 2)
            self.split(b, b11, 0, 0)
            self.split(b, b12, 0, n // 2)
            self.split(b, b21, n // 2, 0)
            self.split(b, b22, n // 2, n // 2)

            # Multiply the sub-matrices recursively and store the results in new matrices
            m1 = self.multiply(self.add(a11, a22), self.add(b11, b22))
            m2 = self.multiply(self.add(a21, a22), b11)
            m3 = self.multiply(a11, self.sub(b12, b22))
            m4 = self.multiply(a22, self.sub(b21, b11))
            m5 = self.multiply(self.add(a11, a12), b22)
            m6 = self.multiply(self.sub(a21, a11), self.add(b11, b12))
            m7 = self.multiply(self.sub(a12, a22), self.add(b21, b22))

            # Combine the results from the sub-matrices to form the final result
            c11 = self.add(self.sub(self.add(m1, m4), m5), m7)
            c12 = self.add(m3, m5)
            c21 = self.add(m2, m4)
            c22 = self.add(self.sub(self.add(m1, m3), m2), m6)

            # Join the sub-matrices to form the final result matrix
            self.join(c11, mat, 0, 0)
            self.join(c12, mat, 0, n // 2)
            self.join(c21, mat, n // 2, 0)
            self.join(c22, mat, n // 2, n // 2)
        return mat # Return the final result matrix

    # Method definition for matrix subtraction
    def sub(self, a, b):
        n = len(a) # Get the size of the matrices
        c = [[0] * n for _ in range(n)] # Initialize a new matrix to store the result

        # Subtract the corresponding elements and store the result in the matrix
        for i in range(n):
            for j in range(n):
                c[i][j] = a[i][j] - b[i][j]
        return c # Return the result matrix

    # Method definition for matrix addition
    def add(self, a, b):
        n = len(a) # Get the size of the matrices
        c = [[0] * n for _ in range(n)] # Initialize a new matrix to store the result

        # Add the corresponding elements and store the result in the matrix
        for i in range(n):
            for j in range(n):
                c[i][j] = a[i][j] + b[i][j]
        return c # Return the result matrix

    # Method definition for splitting a matrix into sub-matrices
    def split(self, p, c, iB, jB):
        for i1 in range(len(c)):
            for j1 in range(len(c)):
                c[i1][j1] = p[i1 + iB][j1 + jB] # Copy the elements from the given matrix to the sub-matrix

    # Method definition for joining two matrices
    def join(self, c, p, iB, jB):
        for i1 in range(len(c)):
            for j1 in range(len(c)):
                p[i1 + iB][j1 + jB] = c[i1][j1] # Copy the elements from the sub-matrix to the given matrix

    # Main method to read input matrices and call the multiply method
    def main(self):
        scanner = Scanner(System.in) # Initialize a Scanner object to read input

        n = scanner.nextInt() # Read the size of the matrices from the user
        a = [[0] * n for _ in range(n)] # Initialize a new matrix to store the first matrix
        b = [[0] * n for _ in range(n)] # Initialize a new matrix to store the second matrix

        # Read the elements of the matrices from the user
        for i in range(n):
            for j in range(n):
                a[i][j] = scanner.nextInt()
                b[i][j] = scanner.nextInt()

        result = self.multiply(a, b) # Call the multiply method to compute the result

        print("Resultant Matrix:") # Print the header for the result matrix
        for i in range(n): # Print each row of the result matrix
            for j in range(n):
                print(result[i][j], end=" ")
            print()

        scanner.close() # Close the Scanner object

# Create an instance of the Main class
strassen = Main()

# Call the main method to read input matrices and call the multiply method
strassen.main()

# END-OF-CODE

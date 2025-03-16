import numpy as np

# Class definition for the Main class
class Main:

    # Method definition for matrix multiplication
    def multiply(self, a, b):
        n = len(a)  # Get the size of the matrices
        mat = np.zeros((n, n), dtype=int)  # Initialize a new matrix to store the result

        # Base case: when the size of the matrix is 1x1
        if n == 1:
            mat[0][0] = a[0][0] * b[0][0]  # Multiply the elements and store the result in the matrix
        else:  # Recursive case: when the size of the matrix is greater than 1x1
            # Split the given matrices into 4 sub-matrices
            a11, a12, a21, a22 = self.split(a)
            b11, b12, b21, b22 = self.split(b)

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
            mat = self.join(c11, c12, c21, c22)

        return mat  # Return the final result matrix

    # Method definition for matrix subtraction
    def sub(self, a, b):
        return a - b  # Subtract the corresponding elements and return the result

    # Method definition for matrix addition
    def add(self, a, b):
        return a + b  # Add the corresponding elements and return the result

    # Method definition for splitting a matrix into sub-matrices
    def split(self, p):
        n = len(p)
        mid = n // 2
        a11 = p[:mid, :mid]
        a12 = p[:mid, mid:]
        a21 = p[mid:, :mid]
        a22 = p[mid:, mid:]
        return a11, a12, a21, a22

    # Method definition for joining four sub-matrices into one
    def join(self, c11, c12, c21, c22):
        top = np.hstack((c11, c12))
        bottom = np.hstack((c21, c22))
        return np.vstack((top, bottom))

# Main method to read input matrices and call the multiply method
if __name__ == "__main__":
    n = int(input("Enter the size of the matrices: "))  # Read the size of the matrices from the user
    a = np.zeros((n, n), dtype=int)  # Initialize a new matrix to store the first matrix
    b = np.zeros((n, n), dtype=int)  # Initialize a new matrix to store the second matrix

    # Read the elements of the matrices from the user
    print("Enter the elements of the first matrix:")
    for i in range(n):
        a[i] = list(map(int, input().split()))

    print("Enter the elements of the second matrix:")
    for i in range(n):
        b[i] = list(map(int, input().split()))

    strassen = Main()  # Create an instance of the Main class
    result = strassen.multiply(a, b)  # Call the multiply method to compute the result

    print("Resultant Matrix:")  # Print the header for the result matrix
    for row in result:  # Print each row of the result matrix
        print(" ".join(map(str, row)))

# <END-OF-CODE>

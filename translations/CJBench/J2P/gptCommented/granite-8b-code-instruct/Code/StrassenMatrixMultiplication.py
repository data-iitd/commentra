
import numpy as np

def multiply(a, b):
    n = a.shape[0] # Get the size of the matrices (assuming square matrices)
    mat = np.zeros((n, n)) # Initialize the resultant matrix

    # Base case for recursion: if the matrix size is 1
    if n == 1:
        mat[0][0] = a[0][0] * b[0][0] # Multiply the single elements
    else:
        # Create submatrices for a and b
        a11 = a[:n//2, :n//2]
        a12 = a[:n//2, n//2:]
        a21 = a[n//2:, :n//2]
        a22 = a[n//2:, n//2:]
        b11 = b[:n//2, :n//2]
        b12 = b[:n//2, n//2:]
        b21 = b[n//2:, :n//2]
        b22 = b[n//2:, n//2:]

        # Calculate the 7 products using Strassen's formulas
        m1 = multiply(a11 + a22, b11 + b22)
        m2 = multiply(a21 + a22, b11)
        m3 = multiply(a11, b12 - b22)
        m4 = multiply(a22, b21 - b11)
        m5 = multiply(a11 + a12, b22)
        m6 = multiply(a21 - a11, b11 + b12)
        m7 = multiply(a12 - a22, b21 + b22)

        # Combine the results into the resultant matrix
        c11 = m1 + m4 - m5 + m7
        c12 = m3 + m5
        c21 = m2 + m4
        c22 = m1 - m2 + m3 + m6

        # Join the submatrices into the final result matrix
        mat[:n//2, :n//2] = c11
        mat[:n//2, n//2:] = c12
        mat[n//2:, :n//2] = c21
        mat[n//2:, n//2:] = c22

    return mat # Return the resultant matrix

# Main method to execute the program
if __name__ == "__main__":
    n = int(input("Enter the size of the matrices: ")) # Read the size of the matrices
    a = np.array([[int(x) for x in input().split()] for _ in range(n)]) # Read the first matrix
    b = np.array([[int(x) for x in input().split()] for _ in range(n)]) # Read the second matrix

    # Multiply the two matrices
    result = multiply(a, b)

    # Print the resultant matrix
    print("Resultant Matrix:")
    for row in result:
        print(row)


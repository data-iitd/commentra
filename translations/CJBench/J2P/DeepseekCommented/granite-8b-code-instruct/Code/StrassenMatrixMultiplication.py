
import numpy as np # Importing numpy library for matrix operations

def multiply(a, b):
    n = a.shape[0] # Get the size of the matrix
    if n == 1:
        return np.array([[a[0][0] * b[0][0]]]) # Base case: single element multiplication
    else:
        # Divide the matrix into four quadrants
        a11 = a[:n//2, :n//2]
        a12 = a[:n//2, n//2:]
        a21 = a[n//2:, :n//2]
        a22 = a[n//2:, n//2:]
        b11 = b[:n//2, :n//2]
        b12 = b[:n//2, n//2:]
        b21 = b[n//2:, :n//2]
        b22 = b[n//2:, n//2:]
        # Recursively compute the seven products
        m1 = multiply(a11 + a22, b11 + b22)
        m2 = multiply(a21 + a22, b11)
        m3 = multiply(a11, b12 - b22)
        m4 = multiply(a22, b21 - b11)
        m5 = multiply(a11 + a12, b22)
        m6 = multiply(a21 - a11, b11 + b12)
        m7 = multiply(a12 - a22, b21 + b22)
        # Compute the four quadrants of the resulting matrix
        c11 = (m1 + m4 - m5 + m7)
        c12 = (m3 + m5)
        c21 = (m2 + m4)
        c22 = (m1 - m2 + m3 + m6)
        # Join the quadrants back into the result matrix
        c = np.zeros((n, n))
        c[:n//2, :n//2] = c11
        c[:n//2, n//2:] = c12
        c[n//2:, :n//2] = c21
        c[n//2:, n//2:] = c22
        return c # Return the resultant matrix

# Main method to read input, call the multiply method, and print the result
if __name__ == "__main__":
    n = int(input("Enter the size of the matrix: ")) # Read the size of the matrix
    a = np.array([[int(x) for x in input().split()] for _ in range(n)]) # Read the first matrix
    b = np.array([[int(x) for x in input().split()] for _ in range(n)]) # Read the second matrix
    result = multiply(a, b) # Call the multiply method
    print("Resultant Matrix:") # Print the result
    for row in result:
        print(" ".join(map(str, row))) # Print elements of the resultant matrix



import numpy as np

# Function definition for matrix multiplication
def multiply(a, b):
    n = a.shape[0] # Get the size of the matrices
    if n == 1: # Base case: when the size of the matrix is 1x1
        return np.array([[a[0][0] * b[0][0]]]) # Multiply the elements and return the result
    else: # Recursive case: when the size of the matrix is greater than 1x1
        a11, a12, a21, a22, b11, b12, b21, b22 = np.split(a, 4, axis=0), np.split(a, 4, axis=1), np.split(b, 4, axis=0), np.split(b, 4, axis=1), np.split(b, 4, axis=0), np.split(b, 4, axis=1), np.split(b, 4, axis=0), np.split(b, 4, axis=1) # Split the given matrices into 4 sub-matrices
        m1, m2, m3, m4, m5, m6, m7 = multiply(a11 + a22, b11 + b22), multiply(a21 + a22, b11), multiply(a11 - a22, b21 - b11), multiply(a22 - a11, b11 + b12), multiply(a11 + a12, b22), multiply(a21 - a11, b11 + b21), multiply(a12 - a22, b21 + b22) # Multiply the sub-matrices recursively
        c11, c12, c21, c22 = add(sub(add(m1, m4), m5), m7), add(m3, m5), add(m2, m4), add(sub(add(m1, m3), m2), m6) # Combine the results from the sub-matrices to form the final result
        return np.concatenate([np.concatenate([c11, c12], axis=1), np.concatenate([c21, c22], axis=1)], axis=0) # Join the sub-matrices to form the final result matrix

# Function definition for matrix subtraction
def sub(a, b):
    return a - b # Subtract the corresponding elements and return the result

# Function definition for matrix addition
def add(a, b):
    return a + b # Add the corresponding elements and return the result

# Main method to read input matrices and call the multiply method
if __name__ == "__main__":
    n = int(input("Enter the size of the matrices: ")) # Read the size of the matrices from the user
    a = np.array([[int(x) for x in input("Enter row " + str(i+1) + " of matrix A: ").split()] for i in range(n)]) # Read the elements of the first matrix from the user
    b = np.array([[int(x) for x in input("Enter row " + str(i+1) + " of matrix B: ").split()] for i in range(n)]) # Read the elements of the second matrix from the user
    result = multiply(a, b) # Call the multiply method to compute the result
    print("Resultant Matrix:") # Print the header for the result matrix
    for row in result: # Print each row of the result matrix
        print(row)


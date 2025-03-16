
import numpy as np

def main():
    # Read the size of the matrix (n x n)
    n = int(input("Enter the size of the matrix: "))
    
    # Initialize a 2D array to hold the matrix values
    matrix = np.zeros((n, n))
    
    # Read the matrix values from user input
    for i in range(n):
        row = list(map(float, input(f"Enter row {i+1}: ").split()))
        matrix[i] = row
    
    # Compute the inverse of the matrix
    inverse = np.linalg.inv(matrix)
    
    # Print the inverse matrix with six decimal places
    for row in inverse:
        print(" ".join(f"{val:.6f}" for val in row))

if __name__ == "__main__":
    main()


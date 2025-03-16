import numpy as np

def main():
    # Read the size of the matrix (n x n)
    n = int(input())
    
    # Initialize a 2D array to hold the matrix values
    matrix = np.zeros((n, n))
    
    # Read the matrix values from user input
    for i in range(n):
        matrix[i] = list(map(float, input().split()))
    
    # Compute the inverse of the matrix
    inverse = invert(matrix)
    
    # Print the inverse matrix with six decimal places
    for row in inverse:
        print(" ".join(f"{value:.6f}" for value in row))

def invert(a):
    n = a.shape[0]  # Get the size of the matrix
    x = np.zeros((n, n))  # Initialize the result matrix
    b = np.eye(n)  # Matrix to hold intermediate results
    index = np.arange(n)  # Array to hold the pivot indices
    
    # Perform Gaussian elimination to transform the matrix
    gaussian(a, index)
    
    # Back substitution to find the inverse matrix
    for i in range(n - 1):
        for j in range(i + 1, n):
            for k in range(n):
                b[index[j], k] -= a[index[j], i] * b[index[i], k]
    
    # Calculate the values of the inverse matrix
    for i in range(n):
        x[n - 1, i] = b[index[n - 1], i] / a[index[n - 1], n - 1]
        for j in range(n - 2, -1, -1):
            x[j, i] = b[index[j], i]
            for k in range(j + 1, n):
                x[j, i] -= a[index[j], k] * x[k, i]
            x[j, i] /= a[index[j], j]
    
    # Return the computed inverse matrix
    return x

def gaussian(a, index):
    n = index.size  # Get the size of the matrix
    c = np.zeros(n)  # Array to hold the scaling factors
    
    # Initialize the index array
    for i in range(n):
        index[i] = i
    
    # Compute the scaling factors for each row
    for i in range(n):
        c[i] = np.max(np.abs(a[i]))
    
    # Perform the Gaussian elimination process
    for j in range(n - 1):
        pi1 = 0
        k = j
        for i in range(j, n):
            pi0 = np.abs(a[index[i], j]) / c[index[i]]
            if pi0 > pi1:
                pi1 = pi0  # Update the pivot row
                k = i
        # Swap the pivot row with the current row
        index[j], index[k] = index[k], index[j]
        
        # Eliminate the entries below the pivot
        for i in range(j + 1, n):
            pj = a[index[i], j] / a[index[j], j]
            a[index[i], j] = pj
            for l in range(j + 1, n):
                a[index[i], l] -= pj * a[index[j], l]

if __name__ == "__main__":
    main()

# <END-OF-CODE>

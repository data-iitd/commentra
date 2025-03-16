import math

def invert(a):
    n = len(a) # Get the size of the matrix
    x = [[0 for i in range(n)] for j in range(n)] # Initialize the result matrix
    b = [[0 for i in range(n)] for j in range(n)] # Matrix to hold intermediate results
    index = [0 for i in range(n)] # Array to hold the pivot indices
    
    # Initialize the identity matrix in b
    for i in range(n):
        b[i][i] = 1
    
    # Perform Gaussian elimination to transform the matrix
    gaussian(a, index)
    
    # Back substitution to find the inverse matrix
    for i in range(n - 1):
        for j in range(i + 1, n):
            for k in range(n):
                b[index[j]][k] -= a[index[j]][i] * b[index[i]][k]
    
    # Calculate the values of the inverse matrix
    for i in range(n):
        x[n - 1][i] = b[index[n - 1]][i] / a[index[n - 1]][n - 1]
        for j in range(n - 2, -1, -1):
            x[j][i] = b[index[j]][i]
            for k in range(j + 1, n):
                x[j][i] -= a[index[j]][k] * x[k][i]
            x[j][i] /= a[index[j]][j]
    
    # Return the computed inverse matrix
    return x

def gaussian(a, index):
    n = len(index) # Get the size of the matrix
    c = [0 for i in range(n)] # Array to hold the scaling factors
    
    # Initialize the index array
    for i in range(n):
        index[i] = i
    
    # Compute the scaling factors for each row
    for i in range(n):
        c1 = 0
        for j in range(n):
            c0 = abs(a[i][j])
            if c0 > c1:
                c1 = c0 # Update the maximum value for scaling
        c[i] = c1
    
    # Perform the Gaussian elimination process
    for j in range(n - 1):
        pi1 = 0
        k = j
        for i in range(j, n):
            pi0 = abs(a[index[i]][j]) / c[index[i]]
            if pi0 > pi1:
                pi1 = pi0 # Update the pivot row
                k = i
        # Swap the pivot row with the current row
        temp = index[j]
        index[j] = index[k]
        index[k] = temp
        
        # Eliminate the entries below the pivot
        for i in range(j + 1, n):
            pj = a[index[i]][j] / a[index[j]][j]
            a[index[i]][j] = pj
            for l in range(j + 1, n):
                a[index[i]][l] -= pj * a[index[j]][l]

# 
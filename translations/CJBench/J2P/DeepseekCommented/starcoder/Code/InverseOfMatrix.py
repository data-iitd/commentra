import sys

# <START-OF-CODE>

def invert(a):
    n = len(a)
    x = [[0.0] * n for i in range(n)]
    b = [[0.0] * n for i in range(n)]
    index = [0] * n

    # Initialize the matrix b to the identity matrix
    for i in range(n):
        b[i][i] = 1.0

    # Perform Gaussian elimination and update b
    gaussian(a, index)

    # Perform back substitution to find the inverse
    for i in range(n):
        x[n - 1][i] = b[index[n - 1]][i] / a[index[n - 1]][n - 1]
        for j in range(n - 2, -1, -1):
            x[j][i] = b[index[j]][i]
            for k in range(j + 1, n):
                x[j][i] -= a[index[j]][k] * x[k][i]
            x[j][i] /= a[index[j]][j]
    return x

# Helper method to perform Gaussian elimination
def gaussian(a, index):
    n = len(a)
    c = [0.0] * n # Array to store the scaling factors

    # Initialize the index array
    for i in range(n):
        index[i] = i

    # Compute the scaling factors
    for i in range(n):
        c1 = 0.0
        for j in range(n):
            c0 = abs(a[i][j])
            if c0 > c1:
                c1 = c0
        c[i] = c1

    # Perform Gaussian elimination
    for j in range(n - 1):
        pi1 = 0.0
        k = j
        for i in range(j, n):
            pi0 = abs(a[index[i]][j]) / c[index[i]]
            if pi0 > pi1:
                pi1 = pi0
                k = i
        temp = index[j]
        index[j] = index[k]
        index[k] = temp
        for i in range(j + 1, n):
            pj = a[index[i]][j] / a[index[j]][j]
            a[index[i]][j] = pj
            for l in range(j + 1, n):
                a[index[i]][l] -= pj * a[index[j]][l]

# 
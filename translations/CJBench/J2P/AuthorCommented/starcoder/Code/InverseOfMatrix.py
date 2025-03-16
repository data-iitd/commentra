import sys

# <START-OF-CODE>

def invert(a):
    n = len(a)
    x = [[0.0] * n for i in range(n)]
    b = [[0.0] * n for i in range(n)]
    index = [0] * n

    # Initialize the identity matrix
    for i in range(n):
        b[i][i] = 1.0

    # Perform Gaussian elimination
    gaussian(a, index)

    # Update matrix b with the ratios stored during elimination
    for i in range(n - 1):
        for j in range(i + 1, n):
            for k in range(n):
                b[index[j]][k] -= a[index[j]][i] * b[index[i]][k]

    # Perform backward substitution to find the inverse
    for i in range(n):
        x[n - 1][i] = b[index[n - 1]][i] / a[index[n - 1]][n - 1]
        for j in range(n - 2, -1, -1):
            x[j][i] = b[index[j]][i]
            for k in range(j + 1, n):
                x[j][i] -= a[index[j]][k] * x[k][i]
            x[j][i] /= a[index[j]][j]
    return x

# Partial-pivoting Gaussian elimination
def gaussian(a, index):
    n = len(a)
    c = [0.0] * n

    # Initialize the index array
    for i in range(n):
        index[i] = i

    # Find the rescaling factors for each row
    for i in range(n):
        c1 = 0
        for j in range(n):
            c0 = abs(a[i][j])
            if c0 > c1:
                c1 = c0
        c[i] = c1

    # Perform pivoting
    for j in range(n - 1):
        pi1 = 0
        k = j
        for i in range(j, n):
            pi0 = abs(a[index[i]][j]) / c[index[i]]
            if pi0 > pi1:
                pi1 = pi0
                k = i

        # Swap rows
        temp = index[j]
        index[j] = index[k]
        index[k] = temp

        for i in range(j + 1, n):
            pj = a[index[i]][j] / a[index[j]][j]

            # Record pivoting ratios below the diagonal
            a[index[i]][j] = pj

            # Modify other elements accordingly
            for l in range(j + 1, n):
                a[index[i]][l] -= pj * a[index[j]][l]

# 
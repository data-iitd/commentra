import math

def invert(a):
    n = len(a)
    x = [[0 for i in range(n)] for j in range(n)]
    b = [[0 for i in range(n)] for j in range(n)]
    index = [0 for i in range(n)]

    # Initialize the matrix b to the identity matrix
    for i in range(n):
        for j in range(n):
            if i == j:
                b[i][j] = 1

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

def gaussian(a, index):
    n = len(index)
    c = [0 for i in range(n)]

    # Initialize the index array
    for i in range(n):
        index[i] = i

    # Compute the scaling factors
    for i in range(n):
        c1 = 0
        for j in range(n):
            c0 = abs(a[i][j])
            if c0 > c1:
                c1 = c0
        c[i] = c1

    # Perform Gaussian elimination
    for j in range(n - 1):
        pi1 = 0
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

def main():
    scanner = Scanner(System.in)
    n = scanner.nextInt()
    matrix = [[0 for i in range(n)] for j in range(n)]

    # Read the elements of the matrix from the user
    for i in range(n):
        for j in range(n):
            matrix[i][j] = scanner.nextDouble()

    # Invert the matrix and print the result
    inverse = invert(matrix)
    for i in range(n):
        for j in range(n):
            print("%.6f " % inverse[i][j], end="")
        print()
    scanner.close()

if __name__ == "__main__":
    main()

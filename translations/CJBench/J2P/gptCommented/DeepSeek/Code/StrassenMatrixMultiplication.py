def multiply(a, b):
    n = len(a)  # Get the size of the matrices (assuming square matrices)
    mat = [[0] * n for _ in range(n)]  # Initialize the resultant matrix

    # Base case for recursion: if the matrix size is 1
    if n == 1:
        mat[0][0] = a[0][0] * b[0][0]  # Multiply the single elements
    else:
        # Create submatrices for a and b
        a11 = [[0] * (n // 2) for _ in range(n // 2)]
        a12 = [[0] * (n // 2) for _ in range(n // 2)]
        a21 = [[0] * (n // 2) for _ in range(n // 2)]
        a22 = [[0] * (n // 2) for _ in range(n // 2)]
        b11 = [[0] * (n // 2) for _ in range(n // 2)]
        b12 = [[0] * (n // 2) for _ in range(n // 2)]
        b21 = [[0] * (n // 2) for _ in range(n // 2)]
        b22 = [[0] * (n // 2) for _ in range(n // 2)]

        # Split matrices a and b into submatrices
        split(a, a11, 0, 0)
        split(a, a12, 0, n // 2)
        split(a, a21, n // 2, 0)
        split(a, a22, n // 2, n // 2)
        split(b, b11, 0, 0)
        split(b, b12, 0, n // 2)
        split(b, b21, n // 2, 0)
        split(b, b22, n // 2, n // 2)

        # Calculate the 7 products using Strassen's formulas
        m1 = add(add(multiply(add(a11, a22), add(b11, b22)), multiply(add(a21, a22), b11)), sub(multiply(sub(b21, b11), add(a12, a22)), multiply(add(a11, a12), b22)))
        m2 = multiply(add(a21, a22), b11)
        m3 = multiply(a11, sub(b12, b22))
        m4 = multiply(a22, sub(b21, b11))
        m5 = multiply(add(a11, a12), b22)
        m6 = multiply(sub(a21, a11), add(b11, b12))
        m7 = multiply(sub(a12, a22), add(b21, b22))

        # Combine the results into the resultant matrix
        c11 = add(sub(add(m1, m4), m5), m7)
        c12 = add(m3, m5)
        c21 = add(m2, m4)
        c22 = add(sub(add(m1, m3), m2), m6)

        # Join the submatrices into the final result matrix
        join(c11, mat, 0, 0)
        join(c12, mat, 0, n // 2)
        join(c21, mat, n // 2, 0)
        join(c22, mat, n // 2, n // 2)

    return mat  # Return the resultant matrix


def sub(a, b):
    n = len(a)  # Get the size of the matrices
    c = [[0] * n for _ in range(n)]  # Initialize the resultant matrix for subtraction
    # Perform element-wise subtraction
    for i in range(n):
        for j in range(n):
            c[i][j] = a[i][j] - b[i][j]
    return c  # Return the resultant matrix


def add(a, b):
    n = len(a)  # Get the size of the matrices
    c = [[0] * n for _ in range(n)]  # Initialize the resultant matrix for addition
    # Perform element-wise addition
    for i in range(n):
        for j in range(n):
            c[i][j] = a[i][j] + b[i][j]
    return c  # Return the resultant matrix


def split(p, c, iB, jB):
    # Copy elements from matrix p to submatrix c
    for i1 in range(len(c)):
        for j1 in range(len(c)):
            c[i1][j1] = p[iB + i1][jB + j1]


def join(c, p, iB, jB):
    # Copy elements from submatrix c to matrix p
    for i1 in range(len(c)):
        for j1 in range(len(c)):
            p[iB + i1][jB + j1] = c[i1][j1]


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])  # Read the size of the matrices
    index = 1
    a = [[0] * n for _ in range(n)]  # Initialize the first matrix
    b = [[0] * n for _ in range(n)]  # Initialize the second matrix

    # Read elements for the first matrix
    for i in range(n):
        for j in range(n):
            a[i][j] = int(data[index])
            index += 1

    # Read elements for the second matrix
    for i in range(n):
        for j in range(n):
            b[i][j] = int(data[index])
            index += 1

    # Multiply the two matrices
    result = multiply(a, b)

    # Print the resultant matrix
    print("Resultant Matrix:")
    for i in range(n):
        for j in range(n):
            print(result[i][j], end=" ")  # Print each element
        print()  # Move to the next line after each row


if __name__ == "__main__":
    main()

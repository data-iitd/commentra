def multiply(a, b):
    n = len(a)  # Get the size of the matrices
    mat = [[0 for _ in range(n)] for _ in range(n)]  # Initialize a new matrix to store the result

    # Base case: when the size of the matrix is 1x1
    if n == 1:
        mat[0][0] = a[0][0] * b[0][0]  # Multiply the elements and store the result in the matrix
    else:  # Recursive case: when the size of the matrix is greater than 1x1
        a11, a12, a21, a22 = [], [], [], []
        b11, b12, b21, b22 = [], [], [], []

        # Split the given matrices into 4 sub-matrices
        split(a, a11, 0, 0)
        split(a, a12, 0, n // 2)
        split(a, a21, n // 2, 0)
        split(a, a22, n // 2, n // 2)
        split(b, b11, 0, 0)
        split(b, b12, 0, n // 2)
        split(b, b21, n // 2, 0)
        split(b, b22, n // 2, n // 2)

        # Multiply the sub-matrices recursively and store the results in new matrices
        m1 = add(add(multiply(add(a11, a22), add(b11, b22)), multiply(sub(a21, a22), add(b21, b22))), sub(multiply(sub(a12, a22), add(b21, b22)), multiply(add(a11, a12), b22)))
        m2 = multiply(add(a21, a22), b11)
        m3 = multiply(a11, sub(b12, b22))
        m4 = multiply(a22, sub(b21, b11))
        m5 = multiply(add(a11, a12), b22)
        m6 = multiply(sub(a21, a11), add(b11, b12))
        m7 = multiply(sub(a12, a22), add(b21, b22))

        # Combine the results from the sub-matrices to form the final result
        c11 = add(sub(add(m1, m4), m5), m7)
        c12 = add(m3, m5)
        c21 = add(m2, m4)
        c22 = add(sub(add(m1, m3), m2), m6)

        # Join the sub-matrices to form the final result matrix
        join(c11, mat, 0, 0)
        join(c12, mat, 0, n // 2)
        join(c21, mat, n // 2, 0)
        join(c22, mat, n // 2, n // 2)

    return mat  # Return the final result matrix


def sub(a, b):
    n = len(a)  # Get the size of the matrices
    c = [[0 for _ in range(n)] for _ in range(n)]  # Initialize a new matrix to store the result

    # Subtract the corresponding elements and store the result in the matrix
    for i in range(n):
        for j in range(n):
            c[i][j] = a[i][j] - b[i][j]
    return c  # Return the result matrix


def add(a, b):
    n = len(a)  # Get the size of the matrices
    c = [[0 for _ in range(n)] for _ in range(n)]  # Initialize a new matrix to store the result

    # Add the corresponding elements and store the result in the matrix
    for i in range(n):
        for j in range(n):
            c[i][j] = a[i][j] + b[i][j]
    return c  # Return the result matrix


def split(p, c, iB, jB):
    for i1 in range(len(c)):
        for j1 in range(len(c)):
            c[i1][j1] = p[iB + i1][jB + j1]  # Copy the elements from the given matrix to the sub-matrix


def join(c, p, iB, jB):
    for i1 in range(len(c)):
        for j1 in range(len(c)):
            p[iB + i1][jB + j1] = c[i1][j1]  # Copy the elements from the sub-matrix to the given matrix


# Main method to read input matrices and call the multiply method
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])  # Read the size of the matrices from the user
    index = 1
    a = [[0 for _ in range(n)] for _ in range(n)]  # Initialize a new matrix to store the first matrix
    b = [[0 for _ in range(n)] for _ in range(n)]  # Initialize a new matrix to store the second matrix

    # Read the elements of the matrices from the user
    for i in range(n):
        for j in range(n):
            a[i][j] = int(data[index])
            b[i][j] = int(data[index + n * n])
            index += 1

    result = multiply(a, b)  # Call the multiply method to compute the result

    print("Resultant Matrix:")  # Print the header for the result matrix
    for i in range(n):  # Print each row of the result matrix
        for j in range(n):
            print(result[i][j], end=" ")
        print()

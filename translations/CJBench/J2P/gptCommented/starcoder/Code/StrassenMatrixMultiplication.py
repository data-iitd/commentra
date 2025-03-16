# Method to multiply two matrices using Strassen's algorithm
def multiply(a, b):
    n = len(a) # Get the size of the matrices (assuming square matrices)
    mat = [[0 for i in range(n)] for j in range(n)] # Initialize the resultant matrix

    # Base case for recursion: if the matrix size is 1
    if n == 1:
        mat[0][0] = a[0][0] * b[0][0] # Multiply the single elements
    else:
        # Create submatrices for a and b
        a11 = [[0 for i in range(n / 2)] for j in range(n / 2)]
        a12 = [[0 for i in range(n / 2)] for j in range(n / 2)]
        a21 = [[0 for i in range(n / 2)] for j in range(n / 2)]
        a22 = [[0 for i in range(n / 2)] for j in range(n / 2)]
        b11 = [[0 for i in range(n / 2)] for j in range(n / 2)]
        b12 = [[0 for i in range(n / 2)] for j in range(n / 2)]
        b21 = [[0 for i in range(n / 2)] for j in range(n / 2)]
        b22 = [[0 for i in range(n / 2)] for j in range(n / 2)]

        # Split matrices a and b into submatrices
        split(a, a11, 0, 0)
        split(a, a12, 0, n / 2)
        split(a, a21, n / 2, 0)
        split(a, a22, n / 2, n / 2)
        split(b, b11, 0, 0)
        split(b, b12, 0, n / 2)
        split(b, b21, n / 2, 0)
        split(b, b22, n / 2, n / 2)

        # Calculate the 7 products using Strassen's formulas
        m1 = multiply(add(a11, a22), add(b11, b22))
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
        join(c12, mat, 0, n / 2)
        join(c21, mat, n / 2, 0)
        join(c22, mat, n / 2, n / 2)
    return mat # Return the resultant matrix

# Method to subtract two matrices
def sub(a, b):
    n = len(a) # Get the size of the matrices
    c = [[0 for i in range(n)] for j in range(n)] # Initialize the resultant matrix for subtraction
    # Perform element-wise subtraction
    for i in range(n):
        for j in range(n):
            c[i][j] = a[i][j] - b[i][j]
    return c # Return the resultant matrix

# Method to add two matrices
def add(a, b):
    n = len(a) # Get the size of the matrices
    c = [[0 for i in range(n)] for j in range(n)] # Initialize the resultant matrix for addition
    # Perform element-wise addition
    for i in range(n):
        for j in range(n):
            c[i][j] = a[i][j] + b[i][j]
    return c # Return the resultant matrix

# Method to split a matrix into a submatrix
def split(p, c, iB, jB):
    # Copy elements from matrix p to submatrix c
    for i1 in range(len(c)):
        for j1 in range(len(c)):
            c[i1][j1] = p[i1 + iB][j1 + jB]

# Method to join a submatrix into a larger matrix
def join(c, p, iB, jB):
    # Copy elements from submatrix c to matrix p
    for i1 in range(len(c)):
        for j1 in range(len(c)):
            p[i1 + iB][j1 + jB] = c[i1][j1]

# Main method to execute the program
if __name__ == "__main__":
    import sys # Import the system module
    scanner = sys.stdin # Create a scanner for input
    n = int(scanner.readline()) # Read the size of the matrices
    a = [[0 for i in range(n)] for j in range(n)] # Initialize the first matrix
    b = [[0 for i in range(n)] for j in range(n)] # Initialize the second matrix

    # Read elements for the first matrix
    for i in range(n):
        a[i] = map(int, scanner.readline().split())

    # Read elements for the second matrix
    for i in range(n):
        b[i] = map(int, scanner.readline().split())

    # Create an instance of Main to use the multiply method
    strassen = Main()
    result = strassen.multiply(a, b) # Multiply the two matrices

    # Print the resultant matrix
    print "Resultant Matrix:"
    for i in range(n):
        for j in range(n):
            print result[i][j], # Print each element
        print # Move to the next line after each row



import sys

def main():
    n = int(input())
    # Read the size of the matrix from the user

    matrix = [[0.0] * n for _ in range(n)]
    # Create a 2D list of size n x n to store the matrix elements

    for i in range(n):
        row = list(map(float, input().split()))
        # Read the elements of the matrix from the user and store them in the matrix list

        for j in range(n):
            matrix[i][j] = row[j]
            # Assign the input values to the corresponding elements of the matrix

    inverse = invert(matrix)
    # Call the invert method to find the inverse of the matrix

    for i in range(n):
        print(*inverse[i], sep=" ")
        # Print the elements of the inverse matrix with 6 decimal places

def invert(a):
    n = len(a)
    # Get the size of the matrix from its 2D list representation

    x = [[0.0] * n for _ in range(n)]
    # Create a 2D list of size n x n to store the inverse matrix elements

    b = [[0.0] * n for _ in range(n)]
    # Create a 2D list of size n x n to store the intermediate values

    index = list(range(n))
    # Create a list to store the row indices for swapping rows during the Gauss-Jordan elimination process

    for i in range(n):
        b[i][i] = 1.0
        # Set the diagonal elements of the b matrix to 1

    gaussian(a, index)
    # Call the gaussian method to perform the Gauss-Jordan elimination process

    for i in range(n - 1):
        for j in range(i + 1, n):
            for k in range(n):
                b[index[j]][k] -= a[index[j]][i] * b[index[i]][k]
                # Eliminate the elements below the diagonal by subtracting the product of the corresponding elements above the diagonal and the elements in the same column from the elements below the diagonal

    for i in range(n):
        x[n - 1][i] = b[index[n - 1]][i] / a[index[n - 1]][n - 1]
        # Find the last column of the inverse matrix by dividing the last row of the b matrix by the determinant of the last column of the a matrix

        for j in range(n - 2, -1, -1):
            x[j][i] = b[index[j]][i]
            # Find the other elements of the inverse matrix by copying the elements from the b matrix

            for k in range(j + 1, n):
                x[j][i] -= a[index[j]][k] * x[k][i]
                # Eliminate the elements above the diagonal by subtracting the product of the corresponding elements above the diagonal and the elements in the same column from the elements above the diagonal

    return x
    # Return the inverse matrix as a 2D list

def gaussian(a, index):
    n = len(index)
    # Get the size of the matrix from its 2D list representation and the number of rows

    c = [0.0] * n
    # Create a list to store the absolute values of the diagonal elements for row swapping

    for i in range(n):
        index[i] = i
        # Initialize the row indices for swapping

    for i in range(n):
        c1 = 0.0
        for j in range(n):
            c0 = abs(a[i][j])
            if c0 > c1:
                c1 = c0
                # Find the maximum absolute value of the diagonal elements and store its index

        c[i] = c1
        # Store the maximum absolute value of the diagonal elements

    for j in range(n - 1):
        pi1 = 0.0
        k = j
        for i in range(j, n):
            pi0 = abs(a[index[i]][j]) / c[index[i]]
            if pi0 > pi1:
                pi1 = pi0
                k = i
                # Find the row with the maximum absolute value of the diagonal element and swap its index with the current index

        temp = index[j]
        index[j] = index[k]
        index[k] = temp
        # Swap the rows

        for i in range(j + 1, n):
            pj = a[index[i]][j] / a[index[j]][j]
            a[index[i]][j] = pj
            # Divide the elements below the diagonal by the corresponding diagonal elements to eliminate the elements below the diagonal

            for l in range(j + 1, n):
                a[index[i]][l] -= pj * a[index[j]][l]
                # Eliminate the elements below the diagonal by subtracting the product of the corresponding elements above the diagonal and the elements in the same column from the elements below the diagonal

    return a
    # Return the modified matrix after performing the Gaussian elimination process

if __name__ == "__main__":
    main()
    # Call the main function to execute the program


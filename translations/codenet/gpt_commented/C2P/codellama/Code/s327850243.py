#include<stdio.h>

int main() {
    # Declare variables for the number of rows (m) and columns (n)
    m, n = int, int
    # Loop counters
    i, j = int, int
    # Declare a 2D array A for storing the matrix and a 1D array B for the vector
    A = [[int]]
    B = [int]
    # Declare an array S to store the results of the matrix-vector multiplication, initialized to 0
    S = [0] * 100

    # Read the dimensions of the matrix (m rows and n columns)
    scanf("%d %d", &m, &n)

    # Input the matrix A
    for i in range(m):
        # Read each row of the matrix
        for j in range(n - 1):
            scanf("%d ", &A[i][j]) # Read elements of the row
        # Read the last element of the row
        scanf("%d\n", &A[i][n - 1])

    # Input the vector B
    for i in range(n):
        scanf("%d\n", &B[i]) # Read each element of the vector

    # Perform matrix-vector multiplication
    for i in range(m):
        for j in range(n):
            S[i] = S[i] + A[i][j] * B[j] # Calculate the dot product for each row

    # Output the result of the multiplication
    for i in range(m):
        printf("%d\n", S[i]) # Print each element of the result array S

    return 0 # Indicate successful completion of the program
}


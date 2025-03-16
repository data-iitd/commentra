# <START-OF-CODE>

# Declare variables for the number of rows (m) and columns (n)
m = 0
n = 0

# Loop counters
i = 0
j = 0

# Declare a 2D array A for storing the matrix and a 1D array B for the vector
A = [[0 for x in range(100)] for y in range(100)]
B = [0 for x in range(100)]

# Declare an array S to store the results of the matrix-vector multiplication, initialized to 0
S = [0 for x in range(100)]

# Read the dimensions of the matrix (m rows and n columns)
m = int(input())
n = int(input())

# Input the matrix A
for i in range(m):
    # Read each row of the matrix
    for j in range(n - 1):
        A[i][j] = int(input()) # Read elements of the row
    # Read the last element of the row
    A[i][n - 1] = int(input())

# Input the vector B
for i in range(n):
    B[i] = int(input()) # Read each element of the vector

# Perform matrix-vector multiplication
for i in range(m):
    for j in range(n):
        S[i] = S[i] + A[i][j] * B[j] # Calculate the dot product for each row

# Output the result of the multiplication
for i in range(m):
    print(S[i]) # Print each element of the result array S

# 
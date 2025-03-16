
# Read the dimensions of the matrix (m rows and n columns)
m, n = map(int, input().split())

# Initialize a 2D array A for storing the matrix and a 1D array B for the vector
A = [[0 for _ in range(n)] for _ in range(m)]
B = [0 for _ in range(n)]

# Input the matrix A
for i in range(m):
    A[i] = list(map(int, input().split()))

# Input the vector B
for i in range(n):
    B[i] = int(input())

# Perform matrix-vector multiplication
S = [0 for _ in range(m)]
for i in range(m):
    for j in range(n):
        S[i] += A[i][j] * B[j]

# Output the result of the multiplication
for i in range(m):
    print(S[i])


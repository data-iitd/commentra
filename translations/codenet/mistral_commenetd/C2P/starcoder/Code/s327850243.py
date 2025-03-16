
# Declare variables
m, n = 0, 0
A = []
B = []
S = []

# Read the dimensions of the matrices from user
m, n = map(int, input().split())
# Read the elements of matrix A row-wise
for i in range(m):
    A.append(list(map(int, input().split())))
# Read the elements of vector B
B = list(map(int, input().split()))
# Perform element-wise multiplication of matrices A and B, and store the result in vector S
for i in range(m):
    S.append(0)
    for j in range(n):
        S[i] += A[i][j] * B[j]
# Print the elements of vector S
for i in range(m):
    print(S[i])

# The program ends with a return statement with value 0
return 0


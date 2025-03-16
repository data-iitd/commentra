# Declare variables for the number of rows (m) and columns (n)
m, n = map(int, input().split())
# Declare a 2D list A for storing the matrix and a 1D list B for the vector
A = []
B = []
# Declare a list S to store the results of the matrix-vector multiplication, initialized to 0
S = [0] * m

# Input the matrix A
for i in range(m):
    row = list(map(int, input().split()))  # Read each row of the matrix
    A.append(row)

# Input the vector B
B = list(map(int, input().split()))  # Read each element of the vector

# Perform matrix-vector multiplication
for i in range(m):
    for j in range(n):
        S[i] += A[i][j] * B[j]  # Calculate the dot product for each row

# Output the result of the multiplication
for i in range(m):
    print(S[i])  # Print each element of the result list S

# <END-OF-CODE>

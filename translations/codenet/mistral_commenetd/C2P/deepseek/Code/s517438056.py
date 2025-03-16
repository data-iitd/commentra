import math

# Read the number of rows and columns from the user
N, D = map(int, input().split())

# Read the elements of the matrix from the user
matrix = []
for i in range(N):
    row = list(map(int, input().split()))
    matrix.append(row)

# Calculate the number of identical rows
k = 0
for i in range(N - 1):
    for j in range(i + 1, N):
        m = 0
        for n in range(D):
            # Calculate the difference between the corresponding elements of two rows and square it
            m += (matrix[i][n] - matrix[j][n]) ** 2
        # Calculate the square root of the sum of squared differences
        l = math.sqrt(m)
        # If the square root is an integer, increment the counter k
        if math.ceil(l) == math.floor(l):
            k += 1

# Print the result
print(k)

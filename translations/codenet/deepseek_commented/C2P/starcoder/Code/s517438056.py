# Step 1: Reading Input
N, D = map(int, input().split())

# Allocate memory for the matrix
matrix = [[0 for i in range(D)] for j in range(N)]

# Step 2: Inputting Points
for i in range(N):
    for j in range(D):
        matrix[i][j] = int(input())

# Step 3: Calculating Distances
k = 0
for i in range(N - 1):
    for j in range(i + 1, N):
        m = 0
        for n in range(D):
            m = (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n]) + m
        l = m ** 0.5
        if ceil(l) == floor(l):
            k += 1

# Step 4: Outputting the Result
print(k)

# 
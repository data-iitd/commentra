
# <START-OF-CODE>

import math

# Step 1: Reading Input
N, D = map(int, input().split())
matrix = []
for i in range(N):
    matrix.append(list(map(int, input().split())))

# Step 2: Inputting Points

# Step 3: Calculating Distances
k = 0
for i in range(N - 1):
    for j in range(i + 1, N):
        m = 0
        for n in range(D):
            m = (matrix[i][n] - matrix[j][n]) ** 2 + m
        l = math.sqrt(m)
        if l.is_integer():
            k += 1

# Step 4: Outputting the Result
print(k)

# 
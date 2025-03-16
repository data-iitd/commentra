import sys

# Reading input from the console
H, W, A, B = map(int, sys.stdin.readline().split())

# Checking if the matrix dimensions are suitable for the given values of A and B
if W < 2 * A or H < 2 * B:
    print(-1)
    exit()

# Nested loops to generate the matrix
for i in range(H):
    for j in range(W):
        # Assigning 0 or 1 based on the conditions specified
        if (i < B and j < A) or (i >= B) and (j >= A):
            print(0, end="")
        else:
            print(1, end="")
    print()

# 
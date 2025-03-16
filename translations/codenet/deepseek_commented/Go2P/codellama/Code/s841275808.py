
import sys

# Initializes a scanner to read from standard input and sets the split function to scan words.
scanner = sys.stdin
scanner.split = scanner.split()

# Reads the number of elements N.
N = int(scanner.readline())

# Initializes slices X and Y to store N integers.
X = [0] * N
Y = [0] * N

# Reads N integers into slice X and copies them to slice Y.
for i in range(N):
    X[i] = int(scanner.readline())
    Y[i] = X[i]

# Sorts slice Y in ascending order.
Y.sort()

# Calculates the two middle values of the sorted slice Y.
m1 = Y[N // 2 - 1]
m2 = Y[N // 2]

# For each element in slice X, prints the corresponding median value.
for i in range(N):
    if X[i] <= m1:
        print(m2)
    else:
        print(m1)

# 
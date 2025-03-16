
import sys
from operator import itemgetter

# Reads the number of elements N from standard input.
N = int(sys.stdin.readline())

# Initializes slices X and Y to store N integers.
X = []
Y = []

# Reads N integers into slice X and copies them to slice Y.
for i in range(N):
    x = int(sys.stdin.readline())
    X.append(x)
    Y.append(x)

# Sorts slice Y in ascending order.
Y.sort()

# Calculates the two middle values of the sorted slice Y.
m1 = Y[N // 2 - 1]
m2 = Y[N // 2]

# For each element in slice X, prints the corresponding median value.
for x in X:
    if x <= m1:
        print(m2)
    else:
        print(m1)


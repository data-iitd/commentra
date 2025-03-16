import math
import sys

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))
r = []
m = 0

# Finding the index of the element with the maximum absolute value in the array 'a'
for i in range(1, n):
    if abs(a[m]) < abs(a[i]):
        m = i

# Finding pairs of indices where one element is non-negative and the other is negative
for i in range(n):
    if a[m] >= 0 ^ a[i] >= 0:
        r.append(str(m + 1) + " " + str(i + 1))

# Generating operations based on whether the maximum absolute value element is non-negative or negative
if a[m] >= 0:
    for i in range(1, n):
        r.append(str(i + 1) + " " + str(i + 2))
else:
    for i in range(n, 1, -1):
        r.append(str(i) + " " + str(i - 1))

# Printing the number of operations and the operations themselves
print(len(r))
for i in r:
    print(i)


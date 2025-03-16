
# Importing the required libraries
import sys

# Reading the number of elements
n = int(sys.stdin.readline())

# Initializing two lists to store the elements
a = []
b = []

# Initializing variables to track the minimum and maximum values
left = float('inf')
right = 0

# Looping through n elements to read and update the lists and variables
for i in range(n):
    a.append(int(sys.stdin.readline()))
    b.append(int(sys.stdin.readline()))
    left = min(left, a[i])
    right = max(right, b[i])

# Looping through the lists to find the target element
for i in range(n):
    if left == a[i] and right == b[i]:
        print(i + 1)
        break
else:
    print(-1)

# 
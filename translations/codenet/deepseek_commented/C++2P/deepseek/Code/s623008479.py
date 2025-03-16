# Include the necessary modules
import sys

# Read the values of n and k from the input
n, k = map(int, sys.stdin.readline().split())

# Read the elements of the list l
l = list(map(int, sys.stdin.readline().split()))

# Sort the list l in ascending order
l.sort()

# Initialize ans to 0
ans = 0

# Sum the last k elements of the sorted list
for i in range(k):
    ans += l[n - 1 - i]

# Print the result
print(ans)

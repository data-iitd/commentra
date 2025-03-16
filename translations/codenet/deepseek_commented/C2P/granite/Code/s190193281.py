
# Define constants for the maximum sizes of arrays S and T
N = 1000000
Q = 500000

# Read the size of array S
n = int(input())
S = list(map(int, input().split()))

# Read the size of array T
q = int(input())
T = list(map(int, input().split()))

# Initialize a counter for the elements in T that are also in S
c = 0

# Perform binary search on array S for each element in T
for t in T:
    if t in S:
        c += 1

# Print the count of elements in T that are also in S
print(c)


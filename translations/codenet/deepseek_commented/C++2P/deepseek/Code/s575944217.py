import sys
from collections import defaultdict

# Read the number of elements or nodes
n = int(sys.stdin.readline().strip())

# Initialize a dictionary to store the count of incoming edges for each node
ans = defaultdict(int)

# Read edges and populate the dictionary
for _ in range(n - 1):
    a = int(sys.stdin.readline().strip())
    a -= 1  # Decrement by 1 to convert to 0-based indexing
    ans[a] += 1  # Increment the count of incoming edges for the node

# Output the results
for i in range(n):
    print(ans[i])


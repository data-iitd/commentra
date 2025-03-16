import sys
from collections import defaultdict

# Read the number of nodes
n = int(sys.stdin.readline().strip())

# Initialize a list to count the number of children for each node
ans = [0] * n

# Read the input and update the count of children for each node
for _ in range(n - 1):
    a = int(sys.stdin.readline().strip())
    ans[a - 1] += 1

# Output the number of children for each node
for count in ans:
    print(count)

print("<END-OF-CODE>")
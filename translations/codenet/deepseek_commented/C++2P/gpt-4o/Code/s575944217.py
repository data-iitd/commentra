# Import necessary libraries
import sys
from collections import defaultdict

# Read the number of elements or nodes
n = int(sys.stdin.readline().strip())
ans = [0] * n  # Initialize a list to store the count of incoming edges for each node

# Loop to read edges and populate the list
for _ in range(n - 1):
    a = int(sys.stdin.readline().strip())  # Read an integer
    a -= 1  # Decrement by 1 to convert to 0-based indexing
    ans[a] += 1  # Increment the count of incoming edges for the node

# Loop to output the results
for count in ans:
    print(count)  # Print the number of incoming edges for each node

# <END-OF-CODE>

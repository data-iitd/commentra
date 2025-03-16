import sys
from collections import defaultdict

# Array to store colors assigned to each point
colors = []

def dfs(p, length):
    # Check if the point has already been colored
    if colors[p] != -1:
        return
    
    # Assign color based on the length (even or odd)
    if length % 2 == 0:
        colors[p] = 0  # Even length -> color 0
    else:
        colors[p] = 1  # Odd length -> color 1
    
    # Recursively visit all friends of the current point
    for friend, length2 in points[p].items():
        dfs(friend, length + length2)  # Recursive DFS call

# Read input
n = int(input().strip())
m = n - 1

# Initialize colors array with -1 (indicating uncolored)
colors = [-1] * n

# Create a dictionary to store points and their friends
points = defaultdict(dict)

# Read edges and establish friendships between points
for _ in range(m):
    me, you, length = map(int, input().strip().split())
    # Establish friendship in both directions
    points[me - 1][you - 1] = length
    points[you - 1][me - 1] = length

# Start DFS from the first point (index 0)
dfs(0, 0)

# Output the colors assigned to each point
for c in colors:
    print(c)

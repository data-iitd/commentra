
import sys

# Read input from the user
n = int(input()) # Number of points (nodes)
m = n - 1 # Number of edges (m = n - 1 for a tree)

# Initialize colors array with -1 (indicating uncolored)
colors = [-1] * n

# Create a class to represent a point in the graph
class Point:
    def __init__(self, name):
        self.name = name
        self.friends = {} # Map to store friends and their friendship lengths

    # Method to establish friendship with another point
    def becomeFriend(self, p, length):
        self.friends[p] = length # Add friend with the specified length

# Create an array of Point objects
points = [Point(i) for i in range(n)]

# Read edges and establish friendships between points
for _ in range(m):
    me, you, length = map(int, input().split()) # Read first point (0-indexed), second point (0-indexed), and length of the friendship
    points[me - 1].becomeFriend(points[you - 1], length) # Establish friendship in both directions
    points[you - 1].becomeFriend(points[me - 1], length)

# Start DFS from the first point (index 0)
def dfs(p, length):
    # Check if the point has already been colored
    already_known = colors[p.name]!= -1
    if already_known: return # Exit if already colored

    # Assign color based on the length (even or odd)
    if length % 2 == 0:
        colors[p.name] = 0 # Even length -> color 0
    else:
        colors[p.name] = 1 # Odd length -> color 1

    # Recursively visit all friends of the current point
    for friend, length2 in p.friends.items():
        dfs(friend, length + length2) # Recursive DFS call

dfs(points[0], 0) # Start DFS from the first point

# Output the colors assigned to each point
print("\n".join(map(str, colors))) # Print the colors

END-OF-CODE

import sys 

# Array to store colors assigned to each point
colors = [-1] * int(sys.stdin.readline()) 

# Read the number of points (nodes)
n = int(sys.stdin.readline()) 

# Calculate the number of edges (m = n - 1 for a tree)
m = n - 1

# Create an array of Point objects
points = [Point(i) for i in range(n)] 

# Initialize each Point object with its index
for i in range(n): 
    points[i].name = i 

# Read edges and establish friendships between points
while m > 0: 
    me, you, length = map(int, sys.stdin.readline().split()) 
    points[me - 1].becomeFriend(points[you - 1], length) 
    points[you - 1].becomeFriend(points[me - 1], length) 
    m -= 1

# Start DFS from the first point (index 0)
dfs(points[0], 0) 

# Output the colors assigned to each point
for c in colors: 
    print(c) 

# Class representing a point in the graph
class Point: 
    def __init__(self, name): 
        self.name = name 
        self.friends = {} # Map to store friends and their friendship lengths

    # Method to establish friendship with another point
    def becomeFriend(self, p, length): 
        self.friends[p] = length # Add friend with the specified length

# Depth-First Search (DFS) to assign colors based on friendship lengths
def dfs(p, length): 
    # Check if the point has already been colored
    alreadyKnown = colors[p.name] != -1
    if alreadyKnown: return # Exit if already colored

    # Assign color based on the length (even or odd)
    if length % 2 == 0: 
        colors[p.name] = 0 # Even length -> color 0
    else: 
        colors[p.name] = 1 # Odd length -> color 1

    # Recursively visit all friends of the current point
    for friend, length2 in p.friends.items(): 
        dfs(friend, length + length2) # Recursive DFS call



import sys

def main():
    n = int(input()) # Step 1: Read the number of nodes
    m = n - 1 # Calculate the number of edges
    colors = [-1] * n # Step 2: Initialize the colors list with size n
    points = [Point(i) for i in range(n)] # Step 3: Create a list to store the points (nodes)

    for _ in range(m): # Step 4: Read the edges and their lengths
        me = int(input()) - 1 # Read the first node and adjust for 0-based index
        you = int(input()) - 1 # Read the second node and adjust for 0-based index
        length = int(input()) # Read the length of the edge
        points[me].becomeFriend(points[you], length) # Update the friends list for the first node
        points[you].becomeFriend(points[me], length) # Update the friends list for the second node

    dfs(points[0], 0) # Step 5: Perform a DFS starting from the first point

    for c in colors: # Step 6: Output the color of each node
        print(c)

def dfs(p, length):
    if colors[p.name]!= -1: # Check if the color of the current point is already known
        return # If the color is already known, return

    if length % 2 == 0: # Check if the length of the path is even
        colors[p.name] = 0 # Color the current point as 0
    else:
        colors[p.name] = 1 # Color the current point as 1

    for friend, length2 in p.friends.items(): # Iterate through the friends of the current point
        dfs(friend, length + length2) # Recursively call DFS for the friend

class Point:
    def __init__(self, name):
        self.name = name
        self.friends = {} # Initialize the friends dictionary

    def becomeFriend(self, p, length):
        self.friends[p] = length # Add the friend and the length of the edge

if __name__ == "__main__":
    main()


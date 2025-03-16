import sys

class Main:
    colors = [] # Step 2: Declare an array to store the color of each node

    def main(self):
        n = int(sys.stdin.readline()) # Read the number of nodes
        m = n - 1 # Calculate the number of edges
        self.colors = [-1] * n # Step 2: Initialize the colors array with size n

        points = [Point(i) for i in range(n)] # Step 3: Create an array to store the points (nodes)

        while m > 0: # Step 4: Read the edges and their lengths
            me = int(sys.stdin.readline()) - 1 # Read the first node and adjust for 0-based index
            you = int(sys.stdin.readline()) - 1 # Read the second node and adjust for 0-based index
            length = int(sys.stdin.readline()) # Read the length of the edge
            points[me].becomeFriend(points[you], length) # Update the friends list for the first node
            points[you].becomeFriend(points[me], length) # Update the friends list for the second node
            m -= 1

        self.dfs(points[0], 0) # Step 5: Perform a DFS starting from the first point

        for c in self.colors: # Step 6: Output the color of each node
            print(c)

    def dfs(self, p, length):
        alreadyKnown = self.colors[p.name]!= -1 # Check if the color of the current point is already known
        if alreadyKnown: return # If the color is already known, return

        if length % 2 == 0: # Check if the length of the path is even
            self.colors[p.name] = 0 # Color the current point as 0
        else:
            self.colors[p.name] = 1 # Color the current point as 1

        for friend, length2 in p.friends.items(): # Iterate through the friends of the current point
            self.dfs(friend, length + length2) # Recursively call DFS for the friend

    class Point:
        name = 0
        friends = {}

        def __init__(self, name):
            self.name = name

        def becomeFriend(self, p, length):
            self.friends[p] = length # Add the friend and the length of the edge

# 
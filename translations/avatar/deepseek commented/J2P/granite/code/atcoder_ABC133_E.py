

import sys

class Node:
    def __init__(self, i):
        self.pattern = 0 # Stores the pattern for the node
        self.index = i # Index of the node in the tree
        self.children = [] # List of children nodes
        self.parent = -1 # Index of the parent node, initialized to -1 for root

    # Method to set the parent of the node recursively
    def setParent(self, K, parent, use, nodes):
        self.pattern = K - use # Set the pattern for the node
        self.parent = parent # Set the parent index
        count = 1 # Initialize count of children
        if parent!= -1:
            count += 1 # Increment count if the node has a parent
        for n in self.children: # Iterate through children
            if n == self.parent:
                continue # Skip the current parent to avoid recursion loop
            nodes[n].setParent(K, self.index, count, nodes) # Recursively set parent for children
            count += 1 # Increment count for the next child

# Method to solve the problem
def solve():
    N, K = map(int, input().split()) # Read number of nodes and parameter K
    nodes = [Node(i) for i in range(N)] # Initialize array of nodes
    for i in range(N - 1):
        a, b = map(int, input().split()) # Read edge node a and b
        nodes[a - 1].children.append(b - 1) # Add b as a child of a
        nodes[b - 1].children.append(a - 1) # Add a as a child of b
    nodes[0].setParent(K, -1, 0, nodes) # Set parent for the root node
    patterns = 1 # Initialize patterns variable
    for i in range(N):
        patterns = (patterns * nodes[i].pattern) % 1_000_000_007 # Calculate total patterns
    print(patterns) # Print the result

# Main method to execute the program
if __name__ == "__main__":
    solve()


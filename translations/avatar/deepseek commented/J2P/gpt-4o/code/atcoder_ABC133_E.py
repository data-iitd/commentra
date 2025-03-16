from collections import defaultdict

class Node:
    def __init__(self, index):
        self.pattern = 0  # Stores the pattern for the node
        self.index = index  # Index of the node in the tree
        self.children = []  # List of children nodes
        self.parent = -1  # Index of the parent node, initialized to -1 for root

    def set_parent(self, K, parent, use, nodes):
        self.pattern = K - use  # Set the pattern for the node
        self.parent = parent  # Set the parent index
        count = 1  # Initialize count of children
        if parent != -1:
            count += 1  # Increment count if the node has a parent
        for n in self.children:  # Iterate through children
            if n == self.parent:
                continue  # Skip the current parent to avoid recursion loop
            nodes[n].set_parent(K, self.index, count, nodes)  # Recursively set parent for children
            count += 1  # Increment count for the next child

def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])  # Read number of nodes
    K = int(data[1])  # Read parameter K
    nodes = [Node(i) for i in range(N)]  # Initialize array of nodes
    
    index = 2
    for _ in range(N - 1):
        a = int(data[index]) - 1  # Read edge node a
        b = int(data[index + 1]) - 1  # Read edge node b
        nodes[a].children.append(b)  # Add b as a child of a
        nodes[b].children.append(a)  # Add a as a child of b
        index += 2
    
    nodes[0].set_parent(K, -1, 0, nodes)  # Set parent for the root node
    patterns = 1  # Initialize patterns variable
    for i in range(N):
        patterns = (patterns * nodes[i].pattern) % 1_000_000_007  # Calculate total patterns
    
    print(patterns)  # Print the result

if __name__ == "__main__":
    solve()

# <END-OF-CODE>

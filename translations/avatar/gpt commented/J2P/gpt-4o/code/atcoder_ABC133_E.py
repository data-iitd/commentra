from collections import defaultdict

class Node:
    def __init__(self, index):
        self.pattern = 0  # Variable to store the pattern value
        self.index = index  # Index of the node
        self.children = []  # List of child nodes
        self.parent = -1  # Parent index, -1 indicates no parent

    def set_parent(self, K, parent, use, nodes):
        self.pattern = K - use  # Calculate the pattern based on K and used count
        self.parent = parent  # Set the parent index
        count = 1  # Initialize count of used nodes

        # If the node has a parent, increment the count
        if parent != -1:
            count += 1

        # Recursively set the parent for each child node
        for n in self.children:
            if n == self.parent:  # Skip the parent node
                continue
            nodes[n].set_parent(K, self.index, count, nodes)  # Recursive call for child
            count += 1  # Increment count for each child processed


class Main:
    def solve(self):
        import sys
        input = sys.stdin.read
        data = input().splitlines()
        
        N, K = map(int, data[0].split())  # Read the number of nodes and the value of K
        nodes = [Node(i) for i in range(N)]  # Create a new node for each index

        # Read edges and build the tree structure
        for i in range(1, N):
            a, b = map(int, data[i].split())
            nodes[a - 1].children.append(b - 1)  # Add b as a child of a
            nodes[b - 1].children.append(a - 1)  # Add a as a child of b (undirected tree)

        # Set the parent for the root node (node 0)
        nodes[0].set_parent(K, -1, 0, nodes)

        patterns = 1  # Variable to store the product of patterns

        # Calculate the product of all node patterns
        for i in range(N):
            patterns = (patterns * nodes[i].pattern) % 1_000_000_007  # Update patterns with modulo

        # Output the final result
        print(patterns)


if __name__ == "__main__":
    main = Main()  # Create an instance of Main
    main.solve()  # Call the solve method to execute the logic
# <END-OF-CODE>

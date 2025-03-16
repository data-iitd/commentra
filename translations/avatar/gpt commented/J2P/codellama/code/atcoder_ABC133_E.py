import sys

# Inner class to represent a node in the tree
class Node:
    def __init__(self, index):
        self.pattern = 0
        self.index = index
        self.children = []
        self.parent = -1

    # Method to set the parent of the node and calculate the pattern
    def set_parent(self, K, parent, use, nodes):
        self.pattern = K - use
        self.parent = parent
        count = 1

        # If the node has a parent, increment the count
        if parent != -1:
            count += 1

        # Recursively set the parent for each child node
        for n in self.children:
            if n == self.parent:
                continue
            nodes[n].set_parent(K, self.index, count, nodes)
            count += 1

# Main logic to solve the problem
def solve():
    N, K = map(int, sys.stdin.readline().split())
    nodes = [Node(i) for i in range(N)]

    # Read edges and build the tree structure
    for i in range(N - 1):
        a, b = map(int, sys.stdin.readline().split())
        nodes[a - 1].children.append(b - 1)
        nodes[b - 1].children.append(a - 1)

    # Set the parent for the root node (node 0)
    nodes[0].set_parent(K, -1, 0, nodes)

    patterns = 1

    # Calculate the product of all node patterns
    for i in range(N):
        patterns = (patterns * nodes[i].pattern) % 1_000_000_007

    # Output the final result
    print(patterns)

# Main method to execute the program
if __name__ == "__main__":
    solve()


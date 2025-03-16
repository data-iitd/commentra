from collections import defaultdict  # Importing defaultdict for creating adjacency list
import sys  # Importing sys for reading input

class Node:  # Defining a Node class
    def __init__(self, i):  # Constructor to initialize a new node
        self.pattern = 0  # Pattern to store the result of the subtree rooted at this node
        self.index = i  # Index of the node in the array
        self.children = []  # List to store the indices of children
        self.parent = -1  # Index of the parent node

    def set_parent(self, K, parent, use, nodes):  # Method to set the parent of this node and calculate its pattern
        self.pattern = K - use
        self.parent = parent
        count = 1
        if parent != -1:  # If this node has a parent
            count += 1
        for n in self.children:  # For each child
            if n == self.parent:  # If the child is the parent of this node (avoiding self-loop)
                continue
            nodes[n].set_parent(K, self.index, count, nodes)  # Recursively setting the parent and calculating the pattern for the child
            count += 1

def solve():  # Function to solve the problem by calculating the pattern for the entire tree
    input = sys.stdin.read  # Reading input from standard input
    data = input().split()  # Splitting the input into a list
    index = 0  # Index for reading data

    N = int(data[index])  # Reading the number of nodes in the tree
    index += 1
    K = int(data[index])  # Reading the sum of edges' weights
    index += 1

    nodes = [Node(i) for i in range(N)]  # Creating a list of Node objects to store the nodes

    for _ in range(N - 1):  # Reading the edges and adding them to the list of children for both nodes
        a = int(data[index]) - 1
        index += 1
        b = int(data[index]) - 1
        index += 1
        nodes[a].children.append(b)
        nodes[b].children.append(a)

    nodes[0].set_parent(K, -1, 0, nodes)  # Setting the parent and calculating the pattern for the root node
    patterns = 1  # Initializing the result variable

    for i in range(N):  # Calculating the pattern for the entire tree by multiplying the patterns of subtrees
        patterns = (patterns * nodes[i].pattern) % 1_000_000_007

    print(patterns)  # Printing the result

if __name__ == "__main__":  # Main method to call the solve function
    solve()

# <END-OF-CODE>

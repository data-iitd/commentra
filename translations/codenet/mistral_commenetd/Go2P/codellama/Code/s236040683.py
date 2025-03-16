
# Package main is the entry point of the program.
import sys

# out is a custom function for printing output.
def out(x):
    print(x)

# getInt reads and converts an integer from the input.
def getInt():
    return int(sys.stdin.readline())

# getString reads and returns a string from the input.
def getString():
    return sys.stdin.readline().strip()

# Node is a custom data structure for representing a node in the graph.
class Node:
    def __init__(self):
        self.to = []

# main is the entry point of the program.
def main():
    # Set up the scanner to read words instead of lines.
    # sc.Split(bufio.ScanWords)

    # Read the number of nodes N and edges M from the input.
    N, M = getInt(), getInt()

    # Create a slice n of size N to store the nodes.
    n = [Node() for _ in range(N)]

    # Process each edge by adding it to the to slice of the corresponding nodes.
    for i in range(M):
        # Read the from and to nodes from the input.
        from, to = getInt()-1, getInt()-1

        # Add the edge to the to slice of the from node.
        n[from].to.append(to)

        # Add the edge to the to slice of the to node.
        n[to].to.append(from)

    # Print the number of neighbors for each node.
    for i in range(N):
        # Print the number of neighbors of the current node.
        out(len(n[i].to))

# 


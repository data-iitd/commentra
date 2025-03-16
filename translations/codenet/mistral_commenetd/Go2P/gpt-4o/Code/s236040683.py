# Import necessary modules
import sys

# out is a custom function for printing output
def out(*args):
    print(*args)

# getInt reads and converts an integer from the input
def getInt():
    return int(sys.stdin.readline().strip())

# getString reads and returns a string from the input
def getString():
    return sys.stdin.readline().strip()

# Node is a custom data structure for representing a node in the graph
class Node:
    def __init__(self):
        self.to = []

# main is the entry point of the program
def main():
    # Read the number of nodes N and edges M from the input
    N, M = map(int, sys.stdin.readline().strip().split())

    # Create a list n of size N to store the nodes
    n = [Node() for _ in range(N)]

    # Process each edge by adding it to the to list of the corresponding nodes
    for _ in range(M):
        from_node, to_node = map(int, sys.stdin.readline().strip().split())
        from_node -= 1  # Convert to 0-based index
        to_node -= 1    # Convert to 0-based index

        # Add the edge to the to list of the from node
        n[from_node].to.append(to_node)

        # Add the edge to the to list of the to node
        n[to_node].to.append(from_node)

    # Print the number of neighbors for each node
    for i in range(N):
        # Print the number of neighbors of the current node
        out(len(n[i].to))

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>

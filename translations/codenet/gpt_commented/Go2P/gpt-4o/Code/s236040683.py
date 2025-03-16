import sys

# out is a helper function to print output to the console.
def out(*args):
    print(*args)

# getInt reads an integer from standard input and returns it.
def getInt():
    return int(sys.stdin.readline().strip())

# getString reads a string from standard input and returns it.
def getString():
    return sys.stdin.readline().strip()

# Node represents a graph node with a list of connected nodes.
class Node:
    def __init__(self):
        self.to = []  # List to hold indices of connected nodes

def main():
    # Read the number of nodes (N) and edges (M) from input
    N, M = map(int, sys.stdin.readline().strip().split())
    # Create a list of Node structures to represent the graph
    n = [Node() for _ in range(N)]

    # Read M edges and populate the graph
    for _ in range(M):
        from_node, to_node = map(int, sys.stdin.readline().strip().split())
        from_node -= 1  # Convert to 0-indexed
        to_node -= 1    # Convert to 0-indexed
        n[from_node].to.append(to_node)  # Add the connection from 'from' to 'to'
        n[to_node].to.append(from_node)   # Add the connection from 'to' to 'from' (undirected graph)

    # Output the degree (number of connections) of each node
    for i in range(N):
        out(len(n[i].to))  # Print the number of connections for node i

if __name__ == "__main__":
    main()

# <END-OF-CODE>

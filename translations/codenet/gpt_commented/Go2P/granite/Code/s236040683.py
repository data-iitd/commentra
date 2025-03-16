
import sys

# Create a scanner to read input from standard input
sc = bufio.Scanner(sys.stdin)

# getInt reads an integer from standard input and returns it
def getInt():
    sc.scan() # Read the next token from input
    return int(sc.text()) # Convert the token to an integer and return it

# getString reads a string from standard input and returns it
def getString():
    sc.scan() # Read the next token from input
    return sc.text() # Return the string value

# Node represents a graph node with a list of connected nodes
class Node:
    def __init__(self):
        self.to = [] # List to hold indices of connected nodes

def main():
    # Set the scanner to split input by whitespace
    sc.whitespace = " \n\r\t"

    # Read the number of nodes (N) and edges (M) from input
    N, M = getInt(), getInt()
    # Create a list of Node objects to represent the graph
    n = [Node() for _ in range(N)]

    # Read M edges and populate the graph
    for i in range(M):
        from_, to = getInt()-1, getInt()-1 # Read the edge endpoints (0-indexed)
        n[from_].to.append(to) # Add the connection from 'from_' to 'to'
        n[to].to.append(from_) # Add the connection from 'to' to 'from_' (undirected graph)

    # Output the degree (number of connections) of each node
    for i in range(N):
        print(len(n[i].to)) # Print the number of connections for node i

# End of code

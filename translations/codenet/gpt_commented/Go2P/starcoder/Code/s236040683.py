import sys

# out is a helper function to print output to the console.
def out(x):
	print(x)

# Create a new scanner to read input from standard input.
sc = bufio.NewScanner(sys.stdin)

# getInt reads an integer from standard input and returns it.
# It panics if the input cannot be converted to an integer.
def getInt():
	sc.Scan() # Read the next token from input
	i, e = int(sc.Text()), None # Convert the token to an integer
	if e!= None:
		panic(e) # Panic if there is an error during conversion
	return i # Return the integer value

# getString reads a string from standard input and returns it.
def getString():
	sc.Scan() # Read the next token from input
	return sc.Text() # Return the string value

# Node represents a graph node with a slice of connected nodes.
class Node:
	def __init__(self):
		self.to = [] # Slice to hold indices of connected nodes

# Main entry point of program.
if __name__ == "__main__":
	# Set the scanner to split input by whitespace
	sc.Split(bufio.ScanWords)

	# Read the number of nodes (N) and edges (M) from input
	N, M = getInt(), getInt()
	# Create a slice of Node structures to represent the graph
	n = [Node() for i in range(N)]

	# Read M edges and populate the graph
	for i in range(M):
		from, to = getInt()-1, getInt()-1 # Read the edge endpoints (0-indexed)
		n[from].to.append(to) # Add the connection from 'from' to 'to'
		n[to].to.append(from) # Add the connection from 'to' to 'from' (undirected graph)

	# Output the degree (number of connections) of each node
	for i in range(N):
		out(len(n[i].to)) # Print the number of connections for node i

# 
# We use sys package for reading input.
import sys

# out is a custom function for printing output.
def out(x):
	print(x)

# getInt reads and converts an integer from the input.
def getInt():
	return int(sys.stdin.readline())

# getString reads and returns a string from the input.
def getString():
	return sys.stdin.readline()

# Node is a custom data structure for representing a node in the graph.
class Node:
	def __init__(self):
		self.to = []

# main is the entry point of the program.
def main():
	# Read the number of nodes N and edges M from the input.
	N, M = getInt(), getInt()

	# Create a slice n of size N to store the nodes.
	n = [Node() for i in range(N)]

	# Process each edge by adding it to the to slice of the corresponding nodes.
	for i in range(M):
		# Read the from and to nodes from the input.
		from_, to_ = getInt()-1, getInt()-1

		# Add the edge to the to slice of the from node.
		n[from_].to.append(to_)

		# Add the edge to the to slice of the to node.
		n[to_].to.append(from_)

	# Print the number of neighbors for each node.
	for i in range(N):
		# Print the number of neighbors of the current node.
		out(len(n[i].to))

# 

import sys

def out(*args, **kwargs):
	print(*args, **kwargs)

def getInt():
	return int(input())

def getString():
	return input()

class Node:
	def __init__(self):
		self.to = []

def main():
	# Read the number of nodes (N) and the number of edges (M)
	N, M = getInt(), getInt()

	# Initialize a slice of Node with N elements
	n = [Node() for i in range(N)]

	# Read M pairs of edges and populate the adjacency list for each node
	for i in range(M):
		from_, to_ = getInt()-1, getInt()-1
		n[from_].to.append(to_)
		n[to_].to.append(from_)

	# Print the size of the adjacency list for each node
	for i in range(N):
		out(len(n[i].to))

if __name__ == "__main__":
	main()

# 
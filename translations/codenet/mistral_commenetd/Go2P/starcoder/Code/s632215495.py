# Importing necessary packages
import sys
import math

# Defining node and tree structures
class node:
	def __init__(self, key):
		self.key = key
		self.parent = None
		self.left = None
		self.right = None

class tree:
	def __init__(self):
		self.root = None

	# Method to insert a new node into the tree
	def insert(self, key):
		# Base case: If the tree is empty, create a new root node
		if self.root == None:
			self.root = node(key)
			return

		# Variables to keep track of current and previous nodes
		currentNode = self.root
		prevNode = None

		# Traverse the tree to find the correct position for the new node
		while currentNode!= None:
			prevNode = currentNode
			if currentNode.key < key:
				currentNode = currentNode.right
			else:
				currentNode = currentNode.left

		# Create a new node with the given key
		newNode = node(key)

		# Set the new node's parent to the previous node
		newNode.parent = prevNode

		# If the previous node's key is less than the new node's key,
		# set the previous node's right child to the new node
		if prevNode.key < key:
			prevNode.right = newNode
		else:
			# Otherwise, set the previous node's left child to the new node
			prevNode.left = newNode

	# Method to print the tree in inorder and preorder traversals
	def print(self):
		# Base case: If the tree is empty, print an empty tree
		if self.root == None:
			print("")
			print("")
			return

		# Variable to store the visited nodes in inorder traversal
		acc = []

		# Print the tree in inorder and preorder traversals
		print("Inorder traversal: ", " ".join(map(str, self.visitInorder(self.root, acc))))
		print("Preorder traversal: ", " ".join(map(str, self.visitPreorder(self.root, acc))))

	# Helper functions for depth-first traversals of the tree
	def visitPreorder(self, node, acc):
		# Base case: If the node is nil, return the accumulator array
		if node == None:
			return acc

		# Add the current node's key to the accumulator array
		acc.append(node.key)

		# Recursively traverse the left and right subtrees
		if node.left!= None:
			acc = self.visitPreorder(node.left, acc)
		if node.right!= None:
			acc = self.visitPreorder(node.right, acc)

		# Return the updated accumulator array
		return acc

	def visitInorder(self, node, acc):
		# Base case: If the node is nil, return the accumulator array
		if node == None:
			return acc

		# Recursively traverse the left subtree and add its keys to the accumulator array
		if node.left!= None:
			acc = self.visitInorder(node.left, acc)

		# Add the current node's key to the accumulator array
		acc.append(node.key)

		# Recursively traverse the right subtree and add its keys to the accumulator array
		if node.right!= None:
			acc = self.visitInorder(node.right, acc)

		# Return the updated accumulator array
		return acc

# Main function to read input and call the appropriate methods
def main():
	# Creating a new scanner to read input from stdin
	sc = bufio.NewScanner(sys.stdin)
	sc.Split(bufio.ScanWords)

	# Reading the number of nodes in the tree
	n, err = nextInt(sc)
	if err!= None:
		raise(err)

	# Creating a new tree object
	tree = tree()

	# Reading the commands and calling the appropriate methods
	for i in range(n):
		command = nextText(sc)
		if command == "insert":
			key, err = nextInt(sc)
			if err!= None:
				raise(err)
			tree.insert(key)
		elif command == "print":
			tree.print()
		else:
			raise("unknown command: " + command)

# Helper functions to read text and integers from the scanner
def nextText(sc):
	sc.Scan()
	return sc.Text()

def nextInt(sc):
	return int(nextText(sc))

# 
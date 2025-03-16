#include <stdio.h>
#include <stdlib.h>
#define NIL None

# Define a structure for a node in the AVL tree
class Node:
	def __init__(self, key, priority):
		self.key = key
		self.priority = priority
		self.left = NIL
		self.right = NIL

# Function to delete a node from the AVL tree
def Delete(t, key):
	# If the tree is empty, do nothing
	if t == NIL: return NIL
	# Recursively search for the node to delete
	if key < t.key: t.left = Delete(t.left, key)
	elif key > t.key: t.right = Delete(t.right, key)
	# If the node to be deleted was found, delete it and update the tree
	else:
		q = t
		t = delete(t, key)
		free(q)
	# If the deleted node was a rotated node, check if the tree needs to be rotated
	if t.priority < t.left.priority or t.priority < t.right.priority:
		# Perform a right rotation if the left child has a higher priority
		if t.left.priority > t.right.priority:
			t = rightRotate(t)
		# Perform a left rotation if the right child has a higher priority
		t = leftRotate(t)
	# Return the updated tree
	return t

# Function to perform a right rotation on an AVL tree
def rightRotate(p):
	# Save a reference to the left child
	q = p.left
	# Make the left child's right subtree the new root
	p.left = q.right
	# Make the old root the new left child of the left child
	q.right = p
	# Return the new root
	return q

# Function to perform a left rotation on an AVL tree
def leftRotate(p):
	# Save a reference to the right child
	q = p.right
	# Make the right child's left subtree the new root
	p.right = q.left
	# Make the old root the new right child of the right child
	q.left = p
	# Return the new root
	return q

# Function to insert a new node into the AVL tree
def insert(t, key, priority):
	# If the tree is empty, create a new node and return it
	if t == NIL: return Node(key, priority)
	# Recursively search for the location to insert the new node
	t = insert(t, key, priority)
	# If the new node becomes the root, check if it needs to be rotated
	if t.priority < t.left.priority or t.priority < t.right.priority:
		# Perform a right rotation if the left child has a higher priority
		if t.left.priority > t.right.priority:
			t = rightRotate(t)
		# Perform a left rotation if the right child has a higher priority
		t = leftRotate(t)
	# Return the updated tree
	return t

# Function to check if a key is present in the AVL tree
def find(p, x):
	# While the current node is not NULL
	while p!= NIL:
		# If the key is found, return 1
		if p.key == x: return 1
		# If the key is smaller than the current node's key, move to the left
		elif p.key > x: p = p.left
		# Otherwise, move to the right
		else: p = p.right
	# If the key is not found, return 0
	return 0

# Function to perform an inorder traversal of the AVL tree and print the keys
def inorder(a):
	# If the left subtree is not NULL, recursively traverse the left subtree
	if a.left!= NIL: inorder(a.left)
	# Print the current node's key
	print(" %d", a.key)
	# If the right subtree is not NULL, recursively traverse the right subtree
	if a.right!= NIL: inorder(a.right)
	# Return from the function
	return

# Function to perform a preorder traversal of the AVL tree and print the keys
def preorder(p):
	# Print the current node's key
	print(" %d", p.key)
	# If the left subtree is not NULL, recursively traverse the left subtree
	if p.left!= NIL: preorder(p.left)
	# If the right subtree is not NULL, recursively traverse the right subtree
	if p.right!= NIL: preorder(p.right)
	# Return from the function
	return

# Function to print the AVL tree
def print(p):
	# Perform an inorder traversal of the AVL tree and print the keys
	inorder(p)
	# Perform a preorder traversal of the AVL tree and print the keys
	preorder(p)
	# Return from the function
	return

# Main function to read commands and perform the corresponding operations on the AVL tree
def main():
	# Initialize the AVL tree to be empty
	num, x, y
	com = [0] * 8
	t = NIL
	# Read the number of commands
	scanf("%d", &num)
	# Process each command
	for i in range(num):
		scanf("%s", com)
		# Based on the command, perform the corresponding operation on the AVL tree
		if com[0] == 'i': # Insert a new node
			scanf("%d %d", &x, &y)
			t = insert(t, x, y)
		elif com[0] == 'd': # Delete a node
			scanf("%d", &x)
			t = Delete(t, x)
		elif com[0] == 'f': # Find a node
			scanf("%d", &x)
			if find(t, x): printf("yes\n")
			else printf("no\n")
		elif com[0] == 'p': # Print the AVL tree
			print(t)
	# Return from the main function
	return 0

# 
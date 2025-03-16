# Define a structure to represent a node in the tree
class node:
  def __init__(self):
    self.l = -1  # Left child
    self.r = -1  # Right child
    self.par = -1  # Parent

# Function to initialize the tree nodes
def init(n):
  N = []  # Array to hold the nodes of the tree

  # Set parent, left, and right of each node to -1 (indicating no children)
  for i in range(n):
    N.append(node())

# Preorder traversal: Root -> Left -> Right
def Preorder(p):
  if p!= -1:  # Check if the node is valid
    print(" " + str(p), end="")  # Print the current node
    Preorder(N[p].l)  # Recursively traverse the left subtree
    Preorder(N[p].r)  # Recursively traverse the right subtree

# Inorder traversal: Left -> Root -> Right
def Inorder(p):
  if p!= -1:  # Check if the node is valid
    Inorder(N[p].l)  # Recursively traverse the left subtree
    print(" " + str(p), end="")  # Print the current node
    Inorder(N[p].r)  # Recursively traverse the right subtree

# Postorder traversal: Left -> Right -> Root
def Postorder(p):
  if p!= -1:  # Check if the node is valid
    Postorder(N[p].l)  # Recursively traverse the left subtree
    Postorder(N[p].r)  # Recursively traverse the right subtree
    print(" " + str(p), end="")  # Print the current node

# Read the number of nodes in the tree
n = int(input())
init(n)  # Initialize the tree nodes

# Read the tree structure from input
for i in range(n):
  id, l, r = map(int, input().split())  # Read node id and its left and right children

  # If left child is not -1, set the left child and parent
  if l!= -1:
    N[id].l = l  # Set left child
    N[l].par = id  # Set parent of left child
  # If right child is not -1, set the right child and parent
  if r!= -1:
    N[id].r = r  # Set right child
    N[r].par = id  # Set parent of right child

# Find the root of the tree (the node with no parent)
for i in range(n):
  if N[i].par == -1:
    p = i  # Store the root node id
    break  # Exit the loop once the root is found

# Perform and display the tree traversals
print("Preorder")
Preorder(p)  # Call Preorder traversal starting from the root
print("")

print("Inorder")
Inorder(p)  # Call Inorder traversal starting from the root
print("")

print("Postorder")
Postorder(p)  # Call Postorder traversal starting from the root
print("")


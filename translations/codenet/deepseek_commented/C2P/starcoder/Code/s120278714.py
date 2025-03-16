# Define the maximum number of nodes
MAX = 25

# Define the node structure
class node:
  def __init__(self):
    self.l = -1
    self.r = -1
    self.par = -1

# Array of nodes
N = [node() for i in range(MAX)]

# Initialize all nodes
def init(n):
  for i in range(n):
    N[i].par = N[i].l = N[i].r = -1

# Preorder traversal: root, left, right
def Preorder(p):
  if p!= -1:
    print(" " + str(p), end="") # Print current node
    Preorder(N[p].l) # Recursively traverse left subtree
    Preorder(N[p].r) # Recursively traverse right subtree

# Inorder traversal: left, root, right
def Inorder(p):
  if p!= -1:
    Inorder(N[p].l) # Recursively traverse left subtree
    print(" " + str(p), end="") # Print current node
    Inorder(N[p].r) # Recursively traverse right subtree

# Postorder traversal: left, right, root
def Postorder(p):
  if p!= -1:
    Postorder(N[p].l) # Recursively traverse left subtree
    Postorder(N[p].r) # Recursively traverse right subtree
    print(" " + str(p), end="") # Print current node

# Read the number of nodes
n = int(input())

# Initialize the nodes
init(n)

# Read each node's id, left child, and right child
for i in range(n):
  id, l, r = map(int, input().split())

  if l!= -1:
    N[id].l = l # Set left child
    N[l].par = id # Set parent of left child
  if r!= -1:
    N[id].r = r # Set right child
    N[r].par = id # Set parent of right child

# Find the root node (the node with no parent)
for i in range(n):
  if N[i].par == -1:
    p = i # Store the index of the root node
    break

# Print the preorder, inorder, and postorder traversals
print("Preorder")
Preorder(p)
print("")

print("Inorder")
Inorder(p)
print("")

print("Postorder")
Postorder(p)
print("")


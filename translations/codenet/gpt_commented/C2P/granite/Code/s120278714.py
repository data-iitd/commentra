
# Python code to implement the tree operations

# Define a class to represent a node in the tree
class Node:
  def __init__(self, id, l=-1, r=-1, par=-1):
    self.id = id
    self.l = l
    self.r = r
    self.par = par

# Initialize the tree nodes
def init(n):
  global N
  N = [Node(i) for i in range(n)]

# Preorder traversal: Root -> Left -> Right
def Preorder(p):
  if p!= -1:  # Check if the node is valid
    print(f" {p}", end="")  # Print the current node
    Preorder(N[p].l)  # Recursively traverse the left subtree
    Preorder(N[p].r)  # Recursively traverse the right subtree

# Inorder traversal: Left -> Root -> Right
def Inorder(p):
  if p!= -1:  # Check if the node is valid
    Inorder(N[p].l)  # Recursively traverse the left subtree
    print(f" {p}", end="")  # Print the current node
    Inorder(N[p].r)  # Recursively traverse the right subtree

# Postorder traversal: Left -> Right -> Root
def Postorder(p):
  if p!= -1:  # Check if the node is valid
    Postorder(N[p].l)  # Recursively traverse the left subtree
    Postorder(N[p].r)  # Recursively traverse the right subtree
    print(f" {p}", end="")  # Print the current node

# Main function to read the tree structure and perform the tree traversals
def main():
  n = int(input("Enter the number of nodes in the tree: "))  # Read the number of nodes in the tree
  init(n)  # Initialize the tree nodes

  # Read the tree structure from input
  for i in range(n):
    id, l, r = map(int, input(f"Enter node id, left child, and right child for node {i}: ").split())  # Read node id and its left and right children
    if l!= -1:  # If left child is not -1, set the left child and parent
      N[id].l = l
      N[l].par = id
    if r!= -1:  # If right child is not -1, set the right child and parent
      N[id].r = r
      N[r].par = id

  # Find the root of the tree (the node with no parent)
  root = -1
  for i in range(n):
    if N[i].par == -1:
      root = i
      break

  # Perform and display the tree traversals
  print("Preorder traversal:")
  Preorder(root)  # Call Preorder traversal starting from the root
  print("\nInorder traversal:")
  Inorder(root)  # Call Inorder traversal starting from the root
  print("\nPostorder traversal:")
  Postorder(root)  # Call Postorder traversal starting from the root

# Call the main function to start the program
if __name__ == "__main__":
  main()


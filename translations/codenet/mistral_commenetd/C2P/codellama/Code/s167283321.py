#include <stdio.h>
#define NIL -1

# Define a structure for a node in the binary tree
class Node:
    def __init__(self, parent, left, right):
        self.parent = parent
        self.left = left
        self.right = right

# Initialize an array of nodes R with size 10000
R = [Node(NIL, NIL, NIL) for i in range(10000)]

# Set the number of nodes n
n = 0

# Recursive function to perform preorder traversal
def preorder(x):
    # Base case: if x is NIL, return
    if x == NIL:
        return

    # Print the current node x
    print(" %d" % x)

    # Recursively traverse the left subtree
    preorder(R[x].left)

    # Recursively traverse the right subtree
    preorder(R[x].right)

# Recursive function to perform inorder traversal
def inorder(x):
    # Base case: if x is NIL, return
    if x == NIL:
        return

    # Recursively traverse the left subtree
    inorder(R[x].left)

    # Print the current node x
    print(" %d" % x)

    # Recursively traverse the right subtree
    inorder(R[x].right)

# Recursive function to perform postorder traversal
def postorder(x):
    # Base case: if x is NIL, return
    if x == NIL:
        return

    # Recursively traverse the left subtree
    postorder(R[x].left)

    # Recursively traverse the right subtree
    postorder(R[x].right)

    # Print the current node x
    print(" %d" % x)

# Main function to read input and call traversal functions
def main():
    i, a, b, c, root = 0, 0, 0, 0, 0

    # Read the number of nodes n
    n = int(input())

    # Initialize all nodes as NIL
    for i in range(n):
        R[i].parent = NIL

    # Read the edges and build the tree
    for i in range(n):
        a, b, c = map(int, input().split())
        R[a].left = b
        R[a].right = c
        if b != NIL:
            R[b].parent = a # Set the parent of left child
        if c != NIL:
            R[c].parent = a # Set the parent of right child

    # Find the root node by searching for the node with no parent
    for i in range(n):
        if R[i].parent == NIL:
            root = i
            break

    # Perform preorder traversal and print the result
    print("Preorder")
    preorder(root)
    print()

    # Perform inorder traversal and print the result
    print("Inorder")
    inorder(root)
    print()

    # Perform postorder traversal and print the result
    print("Postorder")
    postorder(root)
    print()

    # Return 0 to indicate successful execution
    return 0



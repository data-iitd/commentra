#include <stdio.h>
#define NIL -1

# Define a structure to represent a node in the tree
class Node:
    def __init__(self, parent, left, right):
        self.parent = parent
        self.left = left
        self.right = right

# Array to hold the nodes of the tree
R = [Node(NIL, NIL, NIL) for i in range(10000)]
n = 0 # Number of nodes in the tree

# Function prototypes for tree traversal
def preorder(x):
    # Base case: if the current node is NIL, return
    if x == NIL:
        return
    # Print the current node's value
    print(" %d" % x)
    # Recursively traverse the left subtree
    preorder(R[x].left)
    # Recursively traverse the right subtree
    preorder(R[x].right)

def inorder(x):
    # Base case: if the current node is NIL, return
    if x == NIL:
        return
    # Recursively traverse the left subtree
    inorder(R[x].left)
    # Print the current node's value
    print(" %d" % x)
    # Recursively traverse the right subtree
    inorder(R[x].right)

def postorder(x):
    # Base case: if the current node is NIL, return
    if x == NIL:
        return
    # Recursively traverse the left subtree
    postorder(R[x].left)
    # Recursively traverse the right subtree
    postorder(R[x].right)
    # Print the current node's value
    print(" %d" % x)

def main():
    i, a, b, c, root

    # Read the number of nodes in the tree
    scanf("%d", &n)
    
    # Initialize all nodes' parents to NIL
    for i in range(n):
        R[i].parent = NIL

    # Read the tree structure from input
    for i in range(n):
        # Read the current node and its left and right children
        scanf("%d %d %d", &a, &b, &c)
        R[a].left = b # Set left child
        R[a].right = c # Set right child
        # Update the parent of the left child if it is not NIL
        if b != NIL: R[b].parent = a
        # Update the parent of the right child if it is not NIL
        if c != NIL: R[c].parent = a

    # Find the root of the tree (the node with no parent)
    for i in range(n):
        if R[i].parent == NIL:
            root = i # Assign root node

    # Perform and print the results of the tree traversals
    print("Preorder\n")
    preorder(root) # Call preorder traversal
    print("\n")
    
    print("Inorder\n")
    inorder(root) # Call inorder traversal
    print("\n")
    
    print("Postorder\n")
    postorder(root) # Call postorder traversal
    print("\n")

    return 0 # End of the program


class Node:
    def __init__(self):
        self.l = -1  # left child
        self.r = -1  # right child
        self.par = -1  # parent

MAX = 25  # Define the maximum number of nodes in the tree
N = [Node() for _ in range(MAX)]  # Array to hold the nodes of the tree

def init(n):
    for i in range(n):
        N[i].par = N[i].l = N[i].r = -1  # Initialize nodes

def preorder(p):
    if p != -1:  # Check if the node is valid
        print(f" {p}", end='')  # Print the current node
        preorder(N[p].l)  # Recursively traverse the left subtree
        preorder(N[p].r)  # Recursively traverse the right subtree

def inorder(p):
    if p != -1:  # Check if the node is valid
        inorder(N[p].l)  # Recursively traverse the left subtree
        print(f" {p}", end='')  # Print the current node
        inorder(N[p].r)  # Recursively traverse the right subtree

def postorder(p):
    if p != -1:  # Check if the node is valid
        postorder(N[p].l)  # Recursively traverse the left subtree
        postorder(N[p].r)  # Recursively traverse the right subtree
        print(f" {p}", end='')  # Print the current node

if __name__ == "__main__":
    n = int(input())  # Read the number of nodes in the tree
    init(n)  # Initialize the tree nodes

    # Read the tree structure from input
    for _ in range(n):
        id, l, r = map(int, input().split())  # Read node id and its left and right children

        if l != -1:
            N[id].l = l  # Set left child
            N[l].par = id  # Set parent of left child
        if r != -1:
            N[id].r = r  # Set right child
            N[r].par = id  # Set parent of right child

    # Find the root of the tree (the node with no parent)
    p = next(i for i in range(n) if N[i].par == -1)

    # Perform and display the tree traversals
    print("Preorder")
    preorder(p)  # Call Preorder traversal starting from the root
    print("")

    print("Inorder")
    inorder(p)  # Call Inorder traversal starting from the root
    print("")

    print("Postorder")
    postorder(p)  # Call Postorder traversal starting from the root
    print("")

# <END-OF-CODE>

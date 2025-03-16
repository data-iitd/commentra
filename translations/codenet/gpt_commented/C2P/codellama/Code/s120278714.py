#include <stdio.h>

#define MAX 25  # Define the maximum number of nodes in the tree

# Define a structure to represent a node in the tree
class Node:
    def __init__(self, l, r, par):
        self.l = l  # l: left child
        self.r = r  # r: right child
        self.par = par  # par: parent

N = [Node(-1, -1, -1) for i in range(MAX)]  # Array to hold the nodes of the tree

# Function prototypes for tree operations
def init(n):
    for i in range(n):
        N[i].l = -1
        N[i].r = -1
        N[i].par = -1

def Preorder(p):
    if p != -1:  # Check if the node is valid
        print(" %d" % p, end="")  # Print the current node
        Preorder(N[p].l)  # Recursively traverse the left subtree
        Preorder(N[p].r)  # Recursively traverse the right subtree

def Inorder(p):
    if p != -1:  # Check if the node is valid
        Inorder(N[p].l)  # Recursively traverse the left subtree
        print(" %d" % p, end="")  # Print the current node
        Inorder(N[p].r)  # Recursively traverse the right subtree

def Postorder(p):
    if p != -1:  # Check if the node is valid
        Postorder(N[p].l)  # Recursively traverse the left subtree
        Postorder(N[p].r)  # Recursively traverse the right subtree
        print(" %d" % p, end="")  # Print the current node

def main():
    n, i, id, l, r = 0, 0, 0, 0, 0  # Variables for number of nodes, node id, left and right children
    p = 0  # Variable to hold the root node id

    # Read the number of nodes in the tree
    n = int(input())
    init(n)  # Initialize the tree nodes

    # Read the tree structure from input
    for i in range(n):
        id, l, r = map(int, input().split())  # Read node id and its left and right children

        # If left child is not -1, set the left child and parent
        if l != -1:
            N[id].l = l
            N[l].par = id

        # If right child is not -1, set the right child and parent
        if r != -1:
            N[id].r = r
            N[r].par = id

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

    return 0  # Return success


if __name__ == "__main__":
    main()


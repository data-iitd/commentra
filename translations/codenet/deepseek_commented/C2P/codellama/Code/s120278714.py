#include <stdio.h>

#define MAX 25 # Define the maximum number of nodes

# Define the node structure
class Node:
    def __init__(self, l, r, par):
        self.l = l
        self.r = r
        self.par = par

N = [Node(-1, -1, -1) for i in range(MAX)] # Array of nodes

# Function declarations
def init(n):
    for i in range(n):
        N[i].l = -1
        N[i].r = -1
        N[i].par = -1

def Preorder(p):
    if p != -1:
        print(" %d" % p, end="") # Print current node
        Preorder(N[p].l) # Recursively traverse left subtree
        Preorder(N[p].r) # Recursively traverse right subtree

def Inorder(p):
    if p != -1:
        Inorder(N[p].l) # Recursively traverse left subtree
        print(" %d" % p, end="") # Print current node
        Inorder(N[p].r) # Recursively traverse right subtree

def Postorder(p):
    if p != -1:
        Postorder(N[p].l) # Recursively traverse left subtree
        Postorder(N[p].r) # Recursively traverse right subtree
        print(" %d" % p, end="") # Print current node

def main():
    n, i, id, l, r = 0, 0, 0, 0, 0
    p = 0

    scanf("%d", &n) # Read the number of nodes
    init(n) # Initialize the nodes

    # Read each node's id, left child, and right child
    for i in range(n):
        scanf("%d%d%d", &id, &l, &r)

        if l != -1:
            N[id].l = l # Set left child
            N[l].par = id # Set parent of left child
        if r != -1:
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

    return 0



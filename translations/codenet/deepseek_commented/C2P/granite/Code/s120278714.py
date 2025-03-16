
import sys

MAX = 25  # Define the maximum number of nodes

# Define the node structure
class Node:
    def __init__(self, id, l=-1, r=-1, par=-1):
        self.id = id
        self.l = l
        self.r = r
        self.par = par

N = [Node(i) for i in range(MAX)]  # Array of nodes

def init(n):
    for i in range(n):
        N[i].par = N[i].l = N[i].r = -1

def Preorder(p):
    if p!= -1:
        print(f" {p}", end="")  # Print current node
        Preorder(N[p].l)  # Recursively traverse left subtree
        Preorder(N[p].r)  # Recursively traverse right subtree

def Inorder(p):
    if p!= -1:
        Inorder(N[p].l)  # Recursively traverse left subtree
        print(f" {p}", end="")  # Print current node
        Inorder(N[p].r)  # Recursively traverse right subtree

def Postorder(p):
    if p!= -1:
        Postorder(N[p].l)  # Recursively traverse left subtree
        Postorder(N[p].r)  # Recursively traverse right subtree
        print(f" {p}", end="")  # Print current node

if __name__ == "__main__":
    n = int(input())  # Read the number of nodes
    init(n)  # Initialize the nodes

    # Read each node's id, left child, and right child
    for i in range(n):
        id, l, r = map(int, input().split())
        if l!= -1:
            N[id].l = l  # Set left child
            N[l].par = id  # Set parent of left child
        if r!= -1:
            N[id].r = r  # Set right child
            N[r].par = id  # Set parent of right child

    # Find the root node (the node with no parent)
    p = -1
    for i in range(n):
        if N[i].par == -1:
            p = i  # Store the index of the root node
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


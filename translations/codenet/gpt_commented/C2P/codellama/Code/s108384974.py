#include<stdio.h>
#include<stdlib.h>

# Define the structure for a node in the binary search tree
class node:
    def __init__(self, key, p, l, r):
        self.key = key
        self.p = p
        self.l = l
        self.r = r

# Define a type for a pointer to a node
NodePointer = node

# Global variables for the root of the tree and a sentinel NIL node
r = NodePointer(None, None, None, None)
NIL = NodePointer(None, None, None, None)

# Function to find a node with a specific key in the binary search tree
def find(x, k):
    # Traverse the tree until the key is found or a NIL node is reached
    while x != NIL and k != x.key:
        if k < x.key:
            x = x.l
        else:
            x = x.r
    return x  # Return the found node or NIL if not found

# Function to insert a new key into the binary search tree
def insert(k):
    y = NIL  # Parent node of the new node
    x = r  # Start from the root

    # Allocate memory for the new node and initialize its fields
    z = NodePointer(k, None, None, None)

    # Find the appropriate position for the new node
    while x != NIL:
        y = x  # Keep track of the parent node
        if z.key < x.key:
            x = x.l
        else:
            x = x.r
    z.p = y  # Set the parent of the new node

    # Insert the new node in the tree
    if y == NIL:
        r = z  # Tree was empty, new node becomes the root
    elif z.key < y.key:
        y.l = z  # Insert as the left child
    else:
        y.r = z  # Insert as the right child

# Function to perform an inorder traversal of the tree
def inorder(u):
    if u == NIL:
        return  # Base case: if the node is NIL, return
    inorder(u.l)  # Traverse the left subtree
    print(" %d" % u.key)  # Visit the current node
    inorder(u.r)  # Traverse the right subtree

# Function to perform a preorder traversal of the tree
def preorder(u):
    if u == NIL:
        return  # Base case: if the node is NIL, return
    print(" %d" % u.key)  # Visit the current node
    preorder(u.l)  # Traverse the left subtree
    preorder(u.r)  # Traverse the right subtree

# Function to print the tree in both inorder and preorder
def print():
    inorder(r)  # Print the inorder traversal
    print("")  # New line after inorder
    preorder(r)  # Print the preorder traversal
    print("")  # New line after preorder

# Main function to drive the program
def main():
    n = int(input())  # Read the number of operations to perform
    for i in range(n):
        s = input()  # Read the command
        if s[0] == 'f':  # If the command is 'find'
            x = int(input())  # Read the key to find
            t = find(r, x)  # Search for the key
            if t == NIL:
                print("no\n")  # Key not found
            else:
                print("yes\n")  # Key found

        elif s[0] == 'i':  # If the command is 'insert'
            z = int(input())  # Read the key to insert
            insert(z)  # Insert the key into the tree

        else:  # If the command is 'print'
            print()  # Print the tree

# END-OF-CODE

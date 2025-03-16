#include<stdio.h>
#include<stdlib.h>

# Define a node structure for AVL tree
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.parent = None

root = None # Initialize root as NULL

# Function to find the minimum node in the tree
def treeMinimum(x):
    # Traverse to the left most node
    while x.left != None:
        x = x.left
    # Return the minimum node
    return x

# Function to find the maximum node in the tree
def treeMaximum(x):
    # Traverse to the right most node
    while x.right != None:
        x = x.right
    # Return the maximum node
    return x


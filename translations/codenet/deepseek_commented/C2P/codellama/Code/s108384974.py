#include<stdio.h>
#include<stdlib.h>

# Define the structure for a node in the binary search tree
class node:
    def __init__(self, key, p, l, r):
        self.key = key
        self.p = p
        self.l = l
        self.r = r

# Alias for the structure pointer
NodePointer = node

# Global variables for the root of the tree and a NIL pointer
r, NIL = None, None

# Function to find a node with a given key in the binary search tree
def find(x, k):
    while x != NIL and k != x.key:
        if k < x.key:
            x = x.l
        else:
            x = x.r
    return x

# Function to insert a new key into the binary search tree
def insert(k):
    y = NIL
    x = r
    z = NodePointer(k, NIL, NIL, NIL)

    # Find the position to insert the new node
    while x != NIL:
        y = x
        if z.key < x.key:
            x = x.l
        else:
            x = x.r
    z.p = y

    if y == NIL:
        r = z
    elif z.key < y.key:
        y.l = z
    else:
        y.r = z

# Function to perform an inorder traversal of the tree and print the keys
def inorder(u):
    if u == NIL:
        return
    inorder(u.l)
    print(u.key, end=" ")
    inorder(u.r)

# Function to perform a preorder traversal of the tree and print the keys
def preorder(u):
    if u == NIL:
        return
    print(u.key, end=" ")
    preorder(u.l)
    preorder(u.r)

# Function to print the tree in both inorder and preorder traversals
def print():
    inorder(r)
    print()
    preorder(r)
    print()

# Main function to execute the program
def main():
    n, i, j, z, x = 0, 0, 0, 0, 0
    s = ""

    scanf("%d", &n)
    for i in range(n):
        scanf("%s", s)
        if s[0] == 'f':
            scanf("%d", &x)
            t = find(r, x)
            if t == NIL:
                print("no")
            else:
                print("yes")

        elif s[0] == 'i':
            scanf("%d", &z)
            insert(z)

        else:
            print()

    return 0



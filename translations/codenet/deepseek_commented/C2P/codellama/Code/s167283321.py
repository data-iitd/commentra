#include <stdio.h>
#define NIL -1

# Define the structure Node
class Node:
    def __init__(self, parent, left, right):
        self.parent = parent
        self.left = left
        self.right = right

# Declare an array of Node structures and an integer variable n
R = [Node(NIL, NIL, NIL) for i in range(10000)]
n = 0

# Declare the traversal functions
def preorder(x):
    if x == NIL:
        return
    print(" %d" % x)
    preorder(R[x].left)
    preorder(R[x].right)

def inorder(x):
    if x == NIL:
        return
    inorder(R[x].left)
    print(" %d" % x)
    inorder(R[x].right)

def postorder(x):
    if x == NIL:
        return
    postorder(R[x].left)
    postorder(R[x].right)
    print(" %d" % x)

# Implement the main function
def main():
    i, a, b, c, root
    scanf("%d", &n)
    for i in range(n):
        R[i].parent = NIL
    for i in range(n):
        scanf("%d %d %d", &a, &b, &c)
        R[a].left = b
        R[a].right = c
        if b != NIL:
            R[b].parent = a
        if c != NIL:
            R[c].parent = a
    for i in range(n):
        if R[i].parent == NIL:
            root = i
    print("Preorder\n")
    preorder(root)
    print("\n")
    print("Inorder\n")
    inorder(root)
    print("\n")
    print("Postorder\n")
    postorder(root)
    print("\n")
    return 0


#include<stdio.h>
#include<stdlib.h>

# Define a structure for a binary tree node
class BT:
    def __init__(self, parent, right, left):
        self.parent = parent
        self.right = right
        self.left = left

# Array to hold the binary tree nodes
bt = [BT(-1, -1, -1) for i in range(26)]
n = 0 # Number of nodes in the binary tree

# Function to perform preorder traversal of the binary tree
def Preorder(a):
    # Base case: if the node index is -1, return
    if a == -1:
        return

    # Print the current node index
    print(" %d" % a, end="")
    # Recursively traverse the left subtree
    Preorder(bt[a].left)
    # Recursively traverse the right subtree
    Preorder(bt[a].right)

# Function to perform inorder traversal of the binary tree
def Inorder(a):
    # Base case: if the node index is -1, return
    if a == -1:
        return

    # Recursively traverse the left subtree
    Inorder(bt[a].left)
    # Print the current node index
    print(" %d" % a, end="")
    # Recursively traverse the right subtree
    Inorder(bt[a].right)

# Function to perform postorder traversal of the binary tree
def Postorder(a):
    # Base case: if the node index is -1, return
    if a == -1:
        return

    # Recursively traverse the left subtree
    Postorder(bt[a].left)
    # Recursively traverse the right subtree
    Postorder(bt[a].right)
    # Print the current node index
    print(" %d" % a, end="")

def main():
    i, j, num, depth = 0

    # Read the number of nodes in the binary tree
    n = int(input())

    # Initialize the parent of each node to -1 (indicating no parent)
    for i in range(n):
        bt[i].parent = -1

    # Read the tree structure from input
    for i in range(n):
        # Read the current node index
        num = int(input())
        # Read the left and right child indices
        bt[num].left, bt[num].right = map(int, input().split())

        # Update the parent index for the left and right children if they exist
        if bt[num].left != -1 and bt[num].right != -1:
            bt[bt[num].left].parent = num
            bt[bt[num].right].parent = num
        elif bt[num].left != -1:
            bt[bt[num].left].parent = num
        elif bt[num].right != -1:
            bt[bt[num].right].parent = num

    # Find the root of the binary tree (the node with no parent)
    for i in range(n):
        if bt[i].parent == -1:
            break

    # Perform and print preorder traversal
    print("Preorder")
    Preorder(i)
    print()

    # Perform and print inorder traversal
    print("Inorder")
    Inorder(i)
    print()

    # Perform and print postorder traversal
    print("Postorder")
    Postorder(i)
    print()

if __name__ == "__main__":
    main()


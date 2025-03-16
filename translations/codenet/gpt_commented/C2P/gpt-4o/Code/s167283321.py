class Node:
    def __init__(self):
        self.parent = -1
        self.left = -1
        self.right = -1

# Array to hold the nodes of the tree
R = [Node() for _ in range(10000)]
n = 0  # Number of nodes in the tree

# Preorder traversal function
def preorder(x):
    if x == -1:
        return
    print(f" {x}", end="")
    preorder(R[x].left)
    preorder(R[x].right)

# Inorder traversal function
def inorder(x):
    if x == -1:
        return
    inorder(R[x].left)
    print(f" {x}", end="")
    inorder(R[x].right)

# Postorder traversal function
def postorder(x):
    if x == -1:
        return
    postorder(R[x].left)
    postorder(R[x].right)
    print(f" {x}", end="")

def main():
    global n
    # Read the number of nodes in the tree
    n = int(input())
    
    # Initialize all nodes' parents to -1
    for i in range(n):
        R[i].parent = -1

    # Read the tree structure from input
    for i in range(n):
        a, b, c = map(int, input().split())
        R[a].left = b  # Set left child
        R[a].right = c  # Set right child
        # Update the parent of the left child if it is not -1
        if b != -1:
            R[b].parent = a
        # Update the parent of the right child if it is not -1
        if c != -1:
            R[c].parent = a

    # Find the root of the tree (the node with no parent)
    root = -1
    for i in range(n):
        if R[i].parent == -1:
            root = i  # Assign root node
            break

    # Perform and print the results of the tree traversals
    print("Preorder")
    preorder(root)  # Call preorder traversal
    print()

    print("Inorder")
    inorder(root)  # Call inorder traversal
    print()

    print("Postorder")
    postorder(root)  # Call postorder traversal
    print()

if __name__ == "__main__":
    main()  # End of the program

# <END-OF-CODE>

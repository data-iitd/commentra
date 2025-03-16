class Node:
    def __init__(self, parent=-1, left=-1, right=-1):
        self.parent = parent
        self.left = left
        self.right = right

# Array to hold the nodes of the tree
R = []
n = 0  # Number of nodes in the tree

# Function prototypes for tree traversal
def preorder(x):
    if x == -1:
        return
    print(f" {x}", end="")
    preorder(R[x].left)
    preorder(R[x].right)

def inorder(x):
    if x == -1:
        return
    inorder(R[x].left)
    print(f" {x}", end="")
    inorder(R[x].right)

def postorder(x):
    if x == -1:
        return
    postorder(R[x].left)
    postorder(R[x].right)
    print(f" {x}", end="")

# Main function
if __name__ == "__main__":
    global n, R
    # Read the number of nodes in the tree
    n = int(input())
    
    # Initialize all nodes' parents to -1
    for _ in range(n):
        R.append(Node())

    # Read the tree structure from input
    for _ in range(n):
        # Read the current node and its left and right children
        a, b, c = map(int, input().split())
        R[a].left = b
        R[a].right = c
        # Update the parent of the left child if it is not -1
        if b != -1:
            R[b].parent = a
        # Update the parent of the right child if it is not -1
        if c != -1:
            R[c].parent = a

    # Find the root of the tree (the node with no parent)
    for i in range(n):
        if R[i].parent == -1:
            root = i  # Assign root node

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


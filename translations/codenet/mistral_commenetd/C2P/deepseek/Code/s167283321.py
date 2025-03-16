class Node:
    def __init__(self, parent=-1, left=-1, right=-1):
        self.parent = parent
        self.left = left
        self.right = right

# Initialize an array of nodes R with size 10000
R = [Node() for _ in range(10000)]

# Set the number of nodes n
n = 0

# Recursive function to perform preorder traversal
def preorder(x):
    if x == -1:
        return

    # Print the current node x
    print(f" {x}", end="")

    # Recursively traverse the left subtree
    preorder(R[x].left)

    # Recursively traverse the right subtree
    preorder(R[x].right)

# Recursive function to perform inorder traversal
def inorder(x):
    if x == -1:
        return

    # Recursively traverse the left subtree
    inorder(R[x].left)

    # Print the current node x
    print(f" {x}", end="")

    # Recursively traverse the right subtree
    inorder(R[x].right)

# Recursive function to perform postorder traversal
def postorder(x):
    if x == -1:
        return

    # Recursively traverse the left subtree
    postorder(R[x].left)

    # Recursively traverse the right subtree
    postorder(R[x].right)

    # Print the current node x
    print(f" {x}", end="")

# Main function to read input and call traversal functions
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    # Read the number of nodes n
    n = int(data[0])

    # Initialize all nodes as -1
    for i in range(n):
        R[i].parent = -1

    # Read the edges and build the tree
    index = 1
    for i in range(n):
        a = int(data[index])
        b = int(data[index + 1])
        c = int(data[index + 2])
        R[a].left = b
        R[a].right = c
        if b != -1:
            R[b].parent = a  # Set the parent of left child
        if c != -1:
            R[c].parent = a  # Set the parent of right child
        index += 3

    # Find the root node by searching for the node with no parent
    for i in range(n):
        if R[i].parent == -1:
            root = i
            break

    # Perform preorder traversal and print the result
    print("Preorder")
    preorder(root)
    print()

    # Perform inorder traversal and print the result
    print("Inorder")
    inorder(root)
    print()

    # Perform postorder traversal and print the result
    print("Postorder")
    postorder(root)
    print()

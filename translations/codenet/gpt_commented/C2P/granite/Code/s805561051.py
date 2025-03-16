
# Define a class for a binary tree node
class BT:
    def __init__(self, parent, left, right):
        self.parent = parent
        self.left = left
        self.right = right

# Initialize the binary tree nodes
bt = [BT(-1, -1, -1) for _ in range(26)]
n = int(input()) # Read the number of nodes in the binary tree

# Read the tree structure from input
for _ in range(n):
    num = int(input()) # Read the current node index
    left = int(input()) # Read the left child index
    right = int(input()) # Read the right child index

    # Update the parent index for the left and right children if they exist
    if left!= -1 and right!= -1:
        bt[left].parent = num
        bt[right].parent = num
    elif left!= -1:
        bt[left].parent = num
    elif right!= -1:
        bt[right].parent = num

# Find the root of the binary tree (the node with no parent)
root = next(i for i, node in enumerate(bt) if node.parent == -1)

# Define functions to perform preorder, inorder, and postorder traversal
def preorder(node):
    if node == -1: return
    print(f" {node}", end="")
    preorder(bt[node].left)
    preorder(bt[node].right)

def inorder(node):
    if node == -1: return
    inorder(bt[node].left)
    print(f" {node}", end="")
    inorder(bt[node].right)

def postorder(node):
    if node == -1: return
    postorder(bt[node].left)
    postorder(bt[node].right)
    print(f" {node}", end="")

# Perform and print preorder traversal
print("Preorder")
preorder(root)
print()

# Perform and print inorder traversal
print("Inorder")
inorder(root)
print()

# Perform and print postorder traversal
print("Postorder")
postorder(root)
print()


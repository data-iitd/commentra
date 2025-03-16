
class Node:
    def __init__(self, parent, left, right):
        self.parent = parent
        self.left = left
        self.right = right

# Initialize an array of nodes R with size 10000
R = [Node(-1, -1, -1) for _ in range(10000)]

# Set the number of nodes n
n = int(input())

# Read the edges and build the tree
for _ in range(n):
    a, b, c = map(int, input().split())
    R[a].left = b
    R[a].right = c
    if b!= -1:
        R[b].parent = a  # Set the parent of left child
    if c!= -1:
        R[c].parent = a  # Set the parent of right child

# Find the root node by searching for the node with no parent
root = None
for i in range(n):
    if R[i].parent == -1:
        root = i
        break

# Define a recursive function to perform preorder traversal
def preorder(x):
    if x == -1:
        return
    print(f" {x}", end="")
    preorder(R[x].left)
    preorder(R[x].right)

# Define a recursive function to perform inorder traversal
def inorder(x):
    if x == -1:
        return
    inorder(R[x].left)
    print(f" {x}", end="")
    inorder(R[x].right)

# Define a recursive function to perform postorder traversal
def postorder(x):
    if x == -1:
        return
    postorder(R[x].left)
    postorder(R[x].right)
    print(f" {x}", end="")

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


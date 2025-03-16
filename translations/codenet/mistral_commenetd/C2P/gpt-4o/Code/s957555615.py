class Node:
    def __init__(self, key):
        self.right = None  # pointer to the right child
        self.left = None   # pointer to the left child
        self.parent = None  # pointer to the parent node
        self.key = key      # key value of the node

root = None  # Initialize root as None

# Function to find the minimum node in the tree
def tree_minimum(x):
    # Traverse to the left most node
    while x.left is not None:
        x = x.left
    # Return the minimum node
    return x

# Function to find the maximum node in the tree
def tree_maximum(x):
    # Traverse to the right most node
    while x.right is not None:
        x = x.right
    # Return the maximum node
    return x

# <END-OF-CODE>

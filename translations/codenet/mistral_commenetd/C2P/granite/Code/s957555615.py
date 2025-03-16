
class Node:
    def __init__(self, key):
        self.right = None
        self.left = None
        self.parent = None
        self.key = key

root = None

def treeMinimum(x):
    # Traverse to the left most node
    while x.left is not None:
        x = x.left
    # Return the minimum node
    return x

def treeMaximum(x):
    # Traverse to the right most node
    while x.right is not None:
        x = x.right
    # Return the maximum node
    return x


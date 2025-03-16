

import sys

# Represents a Binary Tree Node
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Main function for boundary traversal
def boundaryTraversal(root):
    result = []
    if root is None:
        return result

    # Add root node if it's not a leaf node
    if not isLeaf(root):
        result.append(root.data)

    # Add left boundary
    addLeftBoundary(root, result)

    # Add leaf nodes
    addLeaves(root, result)

    # Add right boundary
    addRightBoundary(root, result)

    return result

# Adds the left boundary, including nodes that have no left child but have a right child
def addLeftBoundary(node, result):
    cur = node.left
    while cur is not None:
        if not isLeaf(cur):
            result.append(cur.data)
        cur = cur.left if cur.left is not None else cur.right

# Adds leaf nodes (nodes without children)
def addLeaves(node, result):
    if node is None:
        return
    if isLeaf(node):
        result.append(node.data)
    else:
        addLeaves(node.left, result)
        addLeaves(node.right, result)

# Adds the right boundary, excluding leaf nodes
def addRightBoundary(node, result):
    cur = node.right
    stack = []
    while cur is not None:
        if not isLeaf(cur):
            stack.append(cur.data)
        cur = cur.right if cur.right is not None else cur.left
    while len(stack) > 0:
        result.append(stack.pop())

# Checks if a node is a leaf node
def isLeaf(node):
    return node.left is None and node.right is None

# Function to build a binary tree from input
def buildTree(scanner):
    n = int(scanner.readline())
    map = {}

    root = None
    for i in range(n):
        parent, direction, child = scanner.readline().split()
        parent = int(parent)
        child = int(child)

        parentNode = map.get(parent, Node(parent))
        childNode = Node(child)

        if direction == "L":
            parentNode.left = childNode
        else:
            parentNode.right = childNode

        map[parent] = parentNode
        map[child] = childNode

        if root is None:
            root = parentNode
    return root

if __name__ == "__main__":
    scanner = sys.stdin
    # Build the tree based on user input
    print("Enter the number of nodes and edges:")
    root = buildTree(scanner)

    # Perform boundary traversal
    print("Boundary traversal:")
    result = boundaryTraversal(root)
    for value in result:
        print(value, end=" ")
    print()
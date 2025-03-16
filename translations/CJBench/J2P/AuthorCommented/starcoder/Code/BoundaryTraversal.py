
import sys
import queue

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
        cur = (cur.left is not None) and cur.left or cur.right

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
    temp = queue.Queue()
    while cur is not None:
        if not isLeaf(cur):
            temp.put(cur.data)
        cur = (cur.right is not None) and cur.right or cur.left
    while not temp.empty():
        result.append(temp.get())

# Checks if a node is a leaf node
def isLeaf(node):
    return node.left is None and node.right is None

# Function to build a binary tree from input
def buildTree(scanner):
    n = scanner.nextInt()
    map = {}

    root = None
    for i in range(n):
        parent = scanner.nextInt()
        direction = scanner.next()
        child = scanner.nextInt()

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
    root = buildTree(scanner)
    result = boundaryTraversal(root)
    for value in result:
        print(value, end=" ")
    print()


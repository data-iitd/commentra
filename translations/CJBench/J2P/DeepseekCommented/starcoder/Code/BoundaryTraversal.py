import sys
import queue

# Represents a node in a binary tree
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Performs a boundary traversal of the binary tree
def boundaryTraversal(root):
    result = []
    if root == None:
        return result # Return an empty list if the root is null
    if not isLeaf(root):
        result.append(root.data) # Add the root data if it's not a leaf
    addLeftBoundary(root, result) # Add the left boundary
    addLeaves(root, result) # Add the leaf nodes
    addRightBoundary(root, result) # Add the right boundary in reverse order
    return result

# Adds the left boundary of the tree to the result list, excluding leaf nodes
def addLeftBoundary(node, result):
    cur = node.left
    while cur!= None:
        if not isLeaf(cur):
            result.append(cur.data) # Add the node data if it's not a leaf
        cur = (cur.left!= None)? cur.left : cur.right # Move to the next node in the left or right subtree

# Adds the leaf nodes of the tree to the result list
def addLeaves(node, result):
    if node == None:
        return # Return if the node is null
    if isLeaf(node):
        result.append(node.data) # Add the node data if it's a leaf
    else:
        addLeaves(node.left, result) # Recursively add left subtree leaves
        addLeaves(node.right, result) # Recursively add right subtree leaves

# Adds the right boundary of the tree to the result list, excluding leaf nodes, in reverse order
def addRightBoundary(node, result):
    cur = node.right
    temp = queue.Queue()
    while cur!= None:
        if not isLeaf(cur):
            temp.put(cur.data) # Add the node data to a queue if it's not a leaf
        cur = (cur.right!= None)? cur.right : cur.left # Move to the next node in the right or left subtree
    while not temp.empty():
        result.append(temp.get()) # Pop nodes from the queue and add to the result list

# Checks if a node is a leaf node
def isLeaf(node):
    return node.left == None and node.right == None # Return true if both left and right children are null

# Builds a binary tree from user input
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
            parentNode.left = childNode # Set the left child
        else:
            parentNode.right = childNode # Set the right child
        map[parent] = parentNode # Update the map with the parent node
        map[child] = childNode # Update the map with the child node
        if root == None:
            root = parentNode # Set the root if it's the first node
    return root

# Main method to run the program
def main():
    scanner = sys.stdin
    root = buildTree(scanner)
    print("Boundary traversal:")
    result = boundaryTraversal(root)
    for value in result:
        print(value, end=" ") # Print the boundary nodes
    print()
    scanner.close()

if __name__ == "__main__":
    main()



import sys

# Define a static inner class Node to represent a tree node
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Define a method to perform boundary traversal of a binary tree
def boundaryTraversal(root):
    # Initialize an empty list to store the result
    result = []

    # Base case: if the root is null, return an empty list
    if root == None:
        return result

    # If the root is not a leaf node, add its data to the result
    if not isLeaf(root):
        result.append(root.data)

    # Recursively add left boundary nodes to the result
    addLeftBoundary(root, result)

    # Recursively add leaf nodes to the result
    addLeaves(root, result)

    # Recursively add right boundary nodes to the result
    addRightBoundary(root, result)

    # Return the result
    return result

# A private helper method to check if a node is a leaf node
def isLeaf(node):
    return node.left == None and node.right == None

# A private helper method to traverse and add left boundary nodes to the result
def addLeftBoundary(node, result):
    cur = node.left
    # Initialize an empty stack to store nodes for right boundary traversal
    temp = []

    # Traverse the left subtree and add non-leaf nodes to the result
    while cur!= None:
        if not isLeaf(cur):
            result.append(cur.data)
        # Traverse the left subtree further
        cur = (cur.left!= None)? cur.left : cur.right

# A private helper method to traverse and add leaf nodes to the result
def addLeaves(node, result):
    # Base case: if the node is null, return
    if node == None:
        return

    # If the node is a leaf node, add its data to the result
    if isLeaf(node):
        result.append(node.data)
    else:
        # Recursively traverse the left and right subtrees to add their leaf nodes to the result
        addLeaves(node.left, result)
        addLeaves(node.right, result)

# A private helper method to traverse and add right boundary nodes to the result
def addRightBoundary(node, result):
    cur = node.right
    # Traverse the right subtree using a stack to handle nodes without left children
    while cur!= None:
        if not isLeaf(cur):
            # Push non-leaf nodes to the stack for later processing
            temp.append(cur.data)
        # Traverse the right subtree further
        cur = (cur.right!= None)? cur.right : cur.left

    # Pop and add all non-leaf nodes from the stack to the result
    while len(temp) > 0:
        result.append(temp.pop())

# Define a method to build a binary tree from input
def buildTree(scanner):
    n = scanner.nextInt() # Read the number of nodes in the tree

    # Initialize an empty HashMap to store nodes for faster lookup
    map = {}

    root = None # Initialize the root to null

    # Read and build each node in the tree
    for i in range(n):
        parent = scanner.nextInt() # Read the parent node's data
        direction = scanner.next() # Read the direction ("L" or "R")
        child = scanner.nextInt() # Read the child node's data

        # Create a new node for the child
        childNode = Node(child)

        # If the parent node is null, set it as the root
        if root == None:
            root = parent

        # Look up the parent node in the map and set the child as its left or right child
        parentNode = map.get(parent, Node(parent))
        if direction == "L":
            parentNode.left = childNode
        else:
            parentNode.right = childNode

        # Add both nodes to the map for faster lookup
        map[parent] = parentNode
        map[child] = childNode

    # Return the root node
    return root

# Main method to run the program
def main():
    scanner = sys.stdin # Initialize a Scanner to read input

    root = buildTree(scanner) # Build the binary tree from input

    result = boundaryTraversal(root) # Perform boundary traversal and store the result in a list

    print("Boundary traversal:") # Print the title of the output
    for value in result: # Iterate through the list and print each value
        print(value, end=" ")
    print() # Print a newline character after the output

    scanner.close() # Close the Scanner to free up resources

if __name__ == "__main__":
    main()


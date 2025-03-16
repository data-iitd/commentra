# Constants representing the colors of the nodes
RED = 0
BLACK = 1

# Inner class representing a node in the Red-Black Tree
class Node:
    def __init__(self, key):
        self.key = key
        self.color = BLACK
        self.left = None
        self.right = None
        self.p = None

# Sentinel node representing the nil node (leaf node)
nil = Node(-1)
root = nil

# Method to print the tree in-order
def printTree(node):
    if node == nil: return # Base case: if the node is nil, return
    printTree(node.left) # Recursively print the left subtree
    # Print the current node with its color
    print(((node.color == RED) and "R " or "B ") + str(node.key) + " ", end="")
    printTree(node.right) # Recursively print the right subtree

# Method to insert a new key into the Red-Black Tree
def insert(key):
    node = Node(key) # Create a new node for the key
    temp = root # Start from the root

    # If the tree is empty, set the new node as the root and color it black
    if root == nil:
        root = node
        node.color = BLACK
    else:
        node.color = RED # New nodes are always red
        while True:
            # Traverse the tree to find the correct position for the new node
            if key < temp.key:
                if temp.left == nil:
                    temp.left = node # Insert as left child
                    node.p = temp # Set parent
                    break
                temp = temp.left # Move to left child
            else:
                if temp.right == nil:
                    temp.right = node # Insert as right child
                    node.p = temp # Set parent
                    break
                temp = temp.right # Move to right child
        # Fix the tree to maintain Red-Black properties
        fixTree(node)

# Method to fix the tree after insertion to maintain Red-Black properties
def fixTree(node):
    while node.p.color == RED: # While the parent is red
        if node.p == node.p.p.left: # If the parent is a left child
            y = node.p.p.right # Uncle node
            if y.color == RED: # Case 1: Uncle is red
                # Recoloring
                node.p.color = BLACK
                y.color = BLACK
                node.p.p.color = RED
                node = node.p.p # Move up the tree
            else:
                # Case 2: Node is a right child
                if node == node.p.right:
                    node = node.p # Move node up
                    rotateLeft(node) # Perform left rotation
                # Case 3: Node is a left child
                node.p.color = BLACK
                node.p.p.color = RED
                rotateRight(node.p.p) # Perform right rotation
        else: # If the parent is a right child
            y = node.p.p.left # Uncle node
            if y.color == RED: # Case 1: Uncle is red
                # Recoloring
                node.p.color = BLACK
                y.color = BLACK
                node.p.p.color = RED
                node = node.p.p # Move up the tree
            else:
                # Case 2: Node is a left child
                if node == node.p.left:
                    node = node.p # Move node up
                    rotateRight(node) # Perform right rotation
                # Case 3: Node is a right child
                node.p.color = BLACK
                node.p.p.color = RED
                rotateLeft(node.p.p) # Perform left rotation
    root.color = BLACK # Ensure the root is always black

# Method to perform a left rotation on a given node
def rotateLeft(node):
    temp = node.right # Store the right child
    node.right = temp.left # Move the left child of right to the right of the node
    if temp.left!= nil: temp.left.p = node # Update parent pointer if not nil
    temp.p = node.p # Update parent of temp
    if node.p == nil: root = temp # If node is root, update root
    else if node == node.p.left: node.p.left = temp # Update parent's left child
    else node.p.right = temp # Update parent's right child
    temp.left = node # Make node the left child of temp
    node.p = temp # Update parent pointer of node

# Method to perform a right rotation on a given node
def rotateRight(node):
    temp = node.left # Store the left child
    node.left = temp.right # Move the right child of left to the left of the node
    if temp.right!= nil: temp.right.p = node # Update parent pointer if not nil
    temp.p = node.p # Update parent of temp
    if node.p == nil: root = temp # If node is root, update root
    else if node == node.p.right: node.p.right = temp # Update parent's right child
    else node.p.left = temp # Update parent's left child
    temp.right = node # Make node the right child of temp
    node.p = temp # Update parent pointer of node

# Method to print the tree in-order
def printInOrder():
    printTree(root) # Call the printTree method starting from the root
    print() # Print a new line after traversal

# Main method to execute the program
if __name__ == "__main__":
    import sys
    scanner = sys.stdin # Create a scanner for input
    rbTree = Main() # Create an instance of the Red-Black Tree
    n = int(scanner.readline()) # Read the number of keys to insert
    for i in range(n):
        key = int(scanner.readline()) # Read each key
        rbTree.insert(key) # Insert the key into the tree
    print("In-order traversal:") # Print message before traversal
    rbTree.printInOrder() # Print the tree in-order
    scanner.close() # Close the scanner


import sys

# Definition of the Node class representing each node in the binary tree
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Method to perform boundary traversal of the binary tree
def boundaryTraversal(root):
    result = [] # List to store the boundary traversal result
    
    # If the tree is empty, return an empty result
    if root == None:
        return result
    
    # Add the root node if it is not a leaf
    if not isLeaf(root):
        result.append(root.data)
    
    # Add the left boundary nodes (excluding leaf nodes)
    addLeftBoundary(root, result)
    
    # Add all leaf nodes
    addLeaves(root, result)
    
    # Add the right boundary nodes (excluding leaf nodes)
    addRightBoundary(root, result)
    
    return result # Return the final result of boundary traversal

# Helper method to add left boundary nodes to the result list
def addLeftBoundary(node, result):
    cur = node.left # Start from the left child
    while cur!= None:
        # Add the node data if it is not a leaf
        if not isLeaf(cur):
            result.append(cur.data)
        # Move to the next boundary node (prefer left child, then right child)
        cur = (cur.left!= None)? cur.left : cur.right

# Helper method to add leaf nodes to the result list
def addLeaves(node, result):
    # Base case: if the node is null, return
    if node == None:
        return
    
    # If the node is a leaf, add its data to the result
    if isLeaf(node):
        result.append(node.data)
    else:
        # Recursively add leaves from the left and right subtrees
        addLeaves(node.left, result)
        addLeaves(node.right, result)

# Helper method to add right boundary nodes to the result list
def addRightBoundary(node, result):
    cur = node.right # Start from the right child
    temp = [] # Temporary stack to reverse the order
    
    while cur!= None:
        # Add the node data if it is not a leaf
        if not isLeaf(cur):
            temp.append(cur.data)
        # Move to the next boundary node (prefer right child, then left child)
        cur = (cur.right!= None)? cur.right : cur.left
    
    # Pop from the stack to add the right boundary in reverse order
    while len(temp) > 0:
        result.append(temp.pop())

# Helper method to check if a node is a leaf node
def isLeaf(node):
    return node.left == None and node.right == None # A node is a leaf if it has no children

# Method to build the binary tree from user input
def buildTree(scanner):
    n = scanner.nextInt() # Read the number of edges
    map = {} # Map to store nodes by their values
    root = None # Initialize root node
    
    # Loop to read edges and construct the tree
    for i in range(n):
        parent = scanner.nextInt() # Read parent node value
        direction = scanner.next() # Read direction (L or R)
        child = scanner.nextInt() # Read child node value
        
        # Get or create the parent node
        parentNode = map.get(parent, Node(parent))
        childNode = Node(child) # Create the child node
        
        # Link the child to the parent based on the direction
        if direction == "L":
            parentNode.left = childNode # Set left child
        else:
            parentNode.right = childNode # Set right child
        
        # Update the map with the parent and child nodes
        map[parent] = parentNode
        map[child] = childNode
        
        # Set the root node if it is not already set
        if root == None:
            root = parentNode
    
    return root # Return the constructed tree's root

# Main method to execute the program
def main():
    scanner = sys.stdin # Create a scanner for input
    root = buildTree(scanner) # Build the tree from input
    print("Boundary traversal:") # Print message for boundary traversal
    result = boundaryTraversal(root) # Perform boundary traversal
    
    # Print the result of boundary traversal
    for value in result:
        print(value, end=" ")
    print() # Print a new line

# Entry point of the program
if __name__ == "__main__":
    main()


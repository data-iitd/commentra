
import sys

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def boundary_traversal(root):
    result = [] # List to store the boundary traversal result
    
    if root is None:
        return result # Return an empty result if the tree is empty
    
    result.append(root.data) # Add the root node if it is not a leaf
    
    add_left_boundary(root, result) # Add the left boundary nodes (excluding leaf nodes)
    
    add_leaves(root, result) # Add all leaf nodes
    
    add_right_boundary(root, result) # Add the right boundary nodes (excluding leaf nodes)
    
    return result # Return the final result of boundary traversal

def add_left_boundary(node, result):
    cur = node.left # Start from the left child
    
    while cur is not None:
        if not is_leaf(cur):
            result.append(cur.data) # Add the node data if it is not a leaf
        cur = cur.left if cur.left is not None else cur.right # Move to the next boundary node (prefer left child, then right child)

def add_leaves(node, result):
    if node is None:
        return # Return if the node is null
    
    if is_leaf(node):
        result.append(node.data) # Add the node data if it is a leaf
    else:
        add_leaves(node.left, result) # Recursively add leaves from the left subtree
        add_leaves(node.right, result) # Recursively add leaves from the right subtree

def add_right_boundary(node, result):
    cur = node.right # Start from the right child
    temp = [] # Temporary list to reverse the order
    
    while cur is not None:
        if not is_leaf(cur):
            temp.append(cur.data) # Add the node data if it is not a leaf
        cur = cur.right if cur.right is not None else cur.left # Move to the next boundary node (prefer right child, then left child)
    
    result.extend(reversed(temp)) # Add the right boundary in reverse order

def is_leaf(node):
    return node.left is None and node.right is None # A node is a leaf if it has no children

def build_tree(scanner):
    n = int(scanner.readline()) # Read the number of edges
    map = {} # Map to store nodes by their values
    root = None # Initialize root node
    
    for i in range(n):
        parent, direction, child = scanner.readline().split() # Read parent, direction, and child node values
        parent = int(parent)
        child = int(child)
        
        # Get or create the parent node
        parent_node = map.get(parent, Node(parent))
        child_node = Node(child) # Create the child node
        
        # Link the child to the parent based on the direction
        if direction == "L":
            parent_node.left = child_node # Set left child
        else:
            parent_node.right = child_node # Set right child
        
        # Update the map with the parent and child nodes
        map[parent] = parent_node
        map[child] = child_node
        
        # Set the root node if it is not already set
        if root is None:
            root = parent_node
    
    return root # Return the constructed tree's root

if __name__ == "__main__":
    scanner = sys.stdin # Use stdin as the input source
    
    root = build_tree(scanner) # Build the tree from input
    print("Boundary traversal:") # Print message for boundary traversal
    result = boundary_traversal(root) # Perform boundary traversal
    
    # Print the result of boundary traversal
    print(" ".join(map(str, result))) # Print the result with spaces between values
    print() # Print a new line
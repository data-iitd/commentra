
# Definition of the Node class representing each node in the binary tree
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Method to perform boundary traversal of the binary tree
def boundary_traversal(root):
    result = [] # List to store the boundary traversal result

    # If the tree is empty, return an empty result
    if root is None:
        return result

    # Add the root node if it is not a leaf
    if not is_leaf(root):
        result.append(root.data)

    # Add the left boundary nodes (excluding leaf nodes)
    add_left_boundary(root, result)

    # Add all leaf nodes
    add_leaves(root, result)

    # Add the right boundary nodes (excluding leaf nodes)
    add_right_boundary(root, result)

    return result # Return the final result of boundary traversal

# Helper method to add left boundary nodes to the result list
def add_left_boundary(node, result):
    cur = node.left # Start from the left child
    while cur is not None:
        # Add the node data if it is not a leaf
        if not is_leaf(cur):
            result.append(cur.data)
        # Move to the next boundary node (prefer left child, then right child)
        cur = cur.left if cur.left is not None else cur.right

# Helper method to add leaf nodes to the result list
def add_leaves(node, result):
    # Base case: if the node is None, return
    if node is None:
        return

    # If the node is a leaf, add its data to the result
    if is_leaf(node):
        result.append(node.data)
    else:
        # Recursively add leaves from the left and right subtrees
        add_leaves(node.left, result)
        add_leaves(node.right, result)

# Helper method to add right boundary nodes to the result list
def add_right_boundary(node, result):
    cur = node.right # Start from the right child
    temp = [] # Temporary list to reverse the order

    while cur is not None:
        # Add the node data if it is not a leaf
        if not is_leaf(cur):
            temp.append(cur.data)
        # Move to the next boundary node (prefer right child, then left child)
        cur = cur.right if cur.right is not None else cur.left

    # Reverse the order of the right boundary nodes
    result.extend(temp[::-1])

# Helper method to check if a node is a leaf node
def is_leaf(node):
    return node.left is None and node.right is None # A node is a leaf if it has no children

# Method to build the binary tree from user input
def build_tree(scanner):
    n = scanner.nextInt() # Read the number of edges
    map = {} # Map to store nodes by their values
    root = None # Initialize root node

    # Loop to read edges and construct the tree
    for i in range(n):
        parent = scanner.nextInt() # Read parent node value
        direction = scanner.next() # Read direction (L or R)
        child = scanner.nextInt() # Read child node value

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

# Main method to execute the program
def main():
    scanner = Scanner(System.in) # Create a scanner for input
    root = build_tree(scanner) # Build the tree from input
    print("Boundary traversal:") # Print message for boundary traversal
    result = boundary_traversal(root) # Perform boundary traversal

    # Print the result of boundary traversal
    for value in result:
        print(value, end=" ")
    print() # Print a new line
    scanner.close() # Close the scanner

if __name__ == "__main__":
    main()

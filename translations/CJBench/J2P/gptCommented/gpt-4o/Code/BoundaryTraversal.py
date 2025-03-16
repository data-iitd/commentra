class Node:
    # Definition of the Node class representing each node in the binary tree
    def __init__(self, data):
        self.data = data  # Value of the node
        self.left = None  # Left child of the node
        self.right = None  # Right child of the node

def boundary_traversal(root):
    result = []  # List to store the boundary traversal result

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

    return result  # Return the final result of boundary traversal

# Helper method to add left boundary nodes to the result list
def add_left_boundary(node, result):
    cur = node.left  # Start from the left child
    while cur is not None:
        # Add the node data if it is not a leaf
        if not is_leaf(cur):
            result.append(cur.data)
        # Move to the next boundary node (prefer left child, then right child)
        cur = cur.left if cur.left is not None else cur.right

# Helper method to add leaf nodes to the result list
def add_leaves(node, result):
    # Base case: if the node is null, return
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
    cur = node.right  # Start from the right child
    temp = []  # Temporary list to reverse the order

    while cur is not None:
        # Add the node data if it is not a leaf
        if not is_leaf(cur):
            temp.append(cur.data)
        # Move to the next boundary node (prefer right child, then left child)
        cur = cur.right if cur.right is not None else cur.left

    # Add the right boundary in reverse order
    result.extend(reversed(temp))

# Helper method to check if a node is a leaf node
def is_leaf(node):
    return node.left is None and node.right is None  # A node is a leaf if it has no children

# Method to build the binary tree from user input
def build_tree():
    n = int(input("Enter the number of edges: "))  # Read the number of edges
    nodes = {}  # Dictionary to store nodes by their values
    root = None  # Initialize root node

    # Loop to read edges and construct the tree
    for _ in range(n):
        parent, direction, child = input("Enter parent, direction (L or R), and child: ").split()
        parent = int(parent)
        child = int(child)

        # Get or create the parent node
        parent_node = nodes.get(parent, Node(parent))
        child_node = Node(child)  # Create the child node

        # Link the child to the parent based on the direction
        if direction == "L":
            parent_node.left = child_node  # Set left child
        elif direction == "R":
            parent_node.right = child_node  # Set right child

        # Update the dictionary with the parent and child nodes
        nodes[parent] = parent_node
        nodes[child] = child_node

        # Set the root node if it is not already set
        if root is None:
            root = parent_node

    return root  # Return the constructed tree's root

# Main method to execute the program
if __name__ == "__main__":
    root = build_tree()  # Build the tree from input
    print("Boundary traversal:")  # Print message for boundary traversal
    result = boundary_traversal(root)  # Perform boundary traversal

    # Print the result of boundary traversal
    print(" ".join(map(str, result)))  # Print the result as space-separated values

# <END-OF-CODE>

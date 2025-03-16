class Node:
    # Define a class to represent a tree node
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def boundary_traversal(root):
    # Initialize an empty list to store the result
    result = []

    # Base case: if the root is None, return an empty list
    if root is None:
        return result

    # If the root is not a leaf node, add its data to the result
    if not is_leaf(root):
        result.append(root.data)

    # Recursively add left boundary nodes to the result
    add_left_boundary(root, result)

    # Recursively add leaf nodes to the result
    add_leaves(root, result)

    # Recursively add right boundary nodes to the result
    add_right_boundary(root, result)

    # Return the result
    return result

def is_leaf(node):
    # A helper method to check if a node is a leaf node
    return node.left is None and node.right is None

def add_left_boundary(node, result):
    cur = node.left
    # Traverse the left subtree and add non-leaf nodes to the result
    while cur is not None:
        if not is_leaf(cur):
            result.append(cur.data)
        # Traverse the left subtree further
        cur = cur.left if cur.left is not None else cur.right

def add_leaves(node, result):
    # A helper method to traverse and add leaf nodes to the result
    if node is None:
        return

    # If the node is a leaf node, add its data to the result
    if is_leaf(node):
        result.append(node.data)
    else:
        # Recursively traverse the left and right subtrees to add their leaf nodes to the result
        add_leaves(node.left, result)
        add_leaves(node.right, result)

def add_right_boundary(node, result):
    cur = node.right
    # Initialize an empty list to store nodes for right boundary traversal
    temp = []

    # Traverse the right subtree using a list to handle nodes without left children
    while cur is not None:
        if not is_leaf(cur):
            temp.append(cur.data)
        # Traverse the right subtree further
        cur = cur.right if cur.right is not None else cur.left

    # Add all non-leaf nodes from the list to the result in reverse order
    while temp:
        result.append(temp.pop())

def build_tree():
    n = int(input("Enter the number of nodes in the tree: "))  # Read the number of nodes in the tree

    # Initialize an empty dictionary to store nodes for faster lookup
    node_map = {}

    root = None  # Initialize the root to None

    # Read and build each node in the tree
    for _ in range(n):
        parent = int(input("Enter parent node's data: "))  # Read the parent node's data
        direction = input("Enter direction (L or R): ")  # Read the direction ("L" or "R")
        child = int(input("Enter child node's data: "))  # Read the child node's data

        # Create a new node for the child
        child_node = Node(child)

        # If the parent node is None, set it as the root
        if root is None:
            root = Node(parent)

        # Look up the parent node in the map and set the child as its left or right child
        parent_node = node_map.get(parent, Node(parent))
        if direction == "L":
            parent_node.left = child_node
        elif direction == "R":
            parent_node.right = child_node

        # Add both nodes to the map for faster lookup
        node_map[parent] = parent_node
        node_map[child] = child_node

    # Return the root node
    return root

# Main method to run the program
if __name__ == "__main__":
    root = build_tree()  # Build the binary tree from input

    result = boundary_traversal(root)  # Perform boundary traversal and store the result in a list

    print("Boundary traversal:")  # Print the title of the output
    print(" ".join(map(str, result)))  # Print each value in the result list


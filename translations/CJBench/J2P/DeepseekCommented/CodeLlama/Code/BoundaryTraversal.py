
# Represents a node in a binary tree
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Performs a boundary traversal of the binary tree
def boundary_traversal(root):
    result = []
    if root is None:
        return result # Return an empty list if the root is None
    if not is_leaf(root):
        result.append(root.data) # Add the root data if it's not a leaf
    add_left_boundary(root, result) # Add the left boundary
    add_leaves(root, result) # Add the leaf nodes
    add_right_boundary(root, result) # Add the right boundary in reverse order
    return result

# Adds the left boundary of the tree to the result list, excluding leaf nodes
def add_left_boundary(node, result):
    cur = node.left
    while cur is not None:
        if not is_leaf(cur):
            result.append(cur.data) # Add the node data if it's not a leaf
        cur = cur.left or cur.right # Move to the next node in the left or right subtree

# Adds the leaf nodes of the tree to the result list
def add_leaves(node, result):
    if node is None:
        return # Return if the node is None
    if is_leaf(node):
        result.append(node.data) # Add the node data if it's a leaf
    else:
        add_leaves(node.left, result) # Recursively add left subtree leaves
        add_leaves(node.right, result) # Recursively add right subtree leaves

# Adds the right boundary of the tree to the result list, excluding leaf nodes, in reverse order
def add_right_boundary(node, result):
    cur = node.right
    temp = []
    while cur is not None:
        if not is_leaf(cur):
            temp.append(cur.data) # Add the node data to a list if it's not a leaf
        cur = cur.right or cur.left # Move to the next node in the right or left subtree
    while temp:
        result.append(temp.pop()) # Pop nodes from the list and add to the result list

# Checks if a node is a leaf node
def is_leaf(node):
    return node.left is None and node.right is None # Return True if both left and right children are None

# Builds a binary tree from user input
def build_tree(scanner):
    n = scanner.nextInt()
    map = {}
    root = None
    for i in range(n):
        parent = scanner.nextInt()
        direction = scanner.next()
        child = scanner.nextInt()
        parent_node = map.get(parent, Node(parent))
        child_node = Node(child)
        if direction == "L":
            parent_node.left = child_node # Set the left child
        elif direction == "R":
            parent_node.right = child_node # Set the right child
        map[parent] = parent_node # Update the map with the parent node
        map[child] = child_node # Update the map with the child node
        if root is None:
            root = parent_node # Set the root if it's the first node
    return root

# Main method to run the program
def main():
    scanner = Scanner(System.in)
    root = build_tree(scanner)
    print("Boundary traversal:")
    result = boundary_traversal(root)
    for value in result:
        print(value, end=" ") # Print the boundary nodes
    print()
    scanner.close()

if __name__ == "__main__":
    main()


import sys
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

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

def add_left_boundary(node, result):
    cur = node.left
    while cur is not None:
        if not is_leaf(cur):
            result.append(cur.data) # Add the node data if it's not a leaf
        cur = cur.left if cur.left is not None else cur.right # Move to the next node in the left or right subtree

def add_leaves(node, result):
    if node is None:
        return # Return if the node is None
    if is_leaf(node):
        result.append(node.data) # Add the node data if it's a leaf
    else:
        add_leaves(node.left, result) # Recursively add left subtree leaves
        add_leaves(node.right, result) # Recursively add right subtree leaves

def add_right_boundary(node, result):
    cur = node.right
    stack = []
    while cur is not None:
        if not is_leaf(cur):
            stack.append(cur.data) # Add the node data to a stack if it's not a leaf
        cur = cur.right if cur.right is not None else cur.left # Move to the next node in the right or left subtree
    while stack:
        result.append(stack.pop()) # Pop nodes from the stack and add to the result list

def is_leaf(node):
    return node.left is None and node.right is None # Return true if both left and right children are None

def build_tree(scanner):
    n = int(scanner.readline())
    map = {}
    root = None
    for i in range(n):
        parent, direction, child = scanner.readline().split()
        parentNode = map.get(parent, Node(parent))
        childNode = Node(child)
        if direction == "L":
            parentNode.left = childNode # Set the left child
        elif direction == "R":
            parentNode.right = childNode # Set the right child
        map[parent] = parentNode # Update the map with the parent node
        map[child] = childNode # Update the map with the child node
        if root is None:
            root = parentNode # Set the root if it's the first node
    return root

def main():
    scanner = sys.stdin
    root = build_tree(scanner)
    print("Boundary traversal:")
    result = boundary_traversal(root)
    for value in result:
        print(value, end=" ") # Print the boundary nodes
    print()

if __name__ == "__main__":
    main()


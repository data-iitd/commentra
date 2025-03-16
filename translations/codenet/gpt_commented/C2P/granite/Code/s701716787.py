
import sys

COMMAND_LENGTH = 10  # Length of command input

class ST_NODE:
    def __init__(self, key):
        self.parent = None  # Pointer to the parent node
        self.left = None    # Pointer to the left child node
        self.right = None   # Pointer to the right child node
        self.key = key  # Key value of the node

def d_insert(root, key):
    parent = None  # Pointer to track the parent node
    index_node = root  # Pointer for traversal
    insert_node = ST_NODE(key)  # New node to be inserted

    # Traverse the tree to find the correct insertion point
    while index_node is not None:
        parent = index_node
        if insert_node.key < index_node.key:
            index_node = index_node.left  # Go left
        else:
            index_node = index_node.right  # Go right

    insert_node.parent = parent  # Set parent for the new node

    # Insert the new node in the tree
    if parent is None:
        root = insert_node  # Tree was empty, new node becomes root
    elif insert_node.key < parent.key:
        parent.left = insert_node  # Insert as left child
    else:
        parent.right = insert_node  # Insert as right child

def d_print(root):
    s_printInOrder(root)  # Print in-order
    print()
    s_printPreOrder(root)  # Print pre-order
    print()

def s_printPreOrder(node):
    if node is None:
        return  # Base case: if the node is None, return

    print(f" {node.key}", end="")  # Print the key of the current node
    s_printPreOrder(node.left)  # Recursively print left subtree
    s_printPreOrder(node.right)  # Recursively print right subtree

def s_printInOrder(node):
    static printed_num_node = 0  # Static variable to count printed nodes

    if node is None:
        return  # Base case: if the node is None, return

    s_printInOrder(node.left)  # Recursively print left subtree
    print(f" {node.key}", end="")  # Print the key of the current node
    s_printInOrder(node.right)  # Recursively print right subtree

def dp_newST_NODE(key):
    node = ST_NODE(key)  # Create a new node with the given key
    return node  # Return the new node

if __name__ == "__main__":
    root = None  # Initialize root to None

    num_command = int(input())  # Read the number of commands from user input

    for i in range(num_command):
        command = input()  # Read the command (insert or print)

        if command == "insert":
            key = int(input())  # Read the key value to insert
            d_insert(root, key)  # Insert the key into the tree
        else:
            d_print(root)  # Print the current state of the tree

print("
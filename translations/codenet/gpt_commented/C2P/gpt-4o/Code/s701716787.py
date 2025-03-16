class STNode:
    def __init__(self, key):
        self.parent = None  # Pointer to the parent node
        self.left = None    # Pointer to the left child node
        self.right = None   # Pointer to the right child node
        self.key = key      # Key value of the node


def insert(root, key):
    new_node = STNode(key)  # Create a new node with the given key
    parent_node = None      # Pointer to track the parent node
    index_node = root       # Start from the root

    # Traverse the tree to find the correct insertion point
    while index_node is not None:
        parent_node = index_node  # Update parent node
        if new_node.key < index_node.key:
            index_node = index_node.left  # Go left
        else:
            index_node = index_node.right  # Go right

    new_node.parent = parent_node  # Set parent for the new node

    # Insert the new node in the tree
    if parent_node is None:
        return new_node  # Tree was empty, new node becomes root
    elif key < parent_node.key:
        parent_node.left = new_node  # Insert as left child
    else:
        parent_node.right = new_node  # Insert as right child

    return root  # Return the root of the tree


def print_tree(root):
    print_in_order(root)  # Print in-order
    print()               # New line
    print_pre_order(root) # Print pre-order
    print()               # New line


def print_pre_order(node):
    if node is None:
        return  # Base case: if the node is None, return

    print(node.key, end=' ')  # Print the key of the current node
    print_pre_order(node.left)  # Recursively print left subtree
    print_pre_order(node.right)  # Recursively print right subtree


def print_in_order(node):
    if node is None:
        return  # Base case: if the node is None, return

    print_in_order(node.left)  # Recursively print left subtree
    print(node.key, end=' ')    # Print the key of the current node
    print_in_order(node.right)  # Recursively print right subtree


def main():
    root = None  # Root of the binary search tree
    num_commands = int(input("Enter number of commands: "))  # Read the number of commands

    for _ in range(num_commands):
        command = input().strip()  # Read the command (insert or print)

        if command == "insert":
            key = int(input("Enter key to insert: "))  # Read the key value to insert
            root = insert(root, key)  # Insert the key into the tree
        else:
            print_tree(root)  # Print the current state of the tree


if __name__ == "__main__":
    main()

# <END-OF-CODE>


# Import the Scanner class from the java.util package
from java.util import Scanner

# Define a class to represent an AVL tree
class AVLTree:
    # Define a class to represent a node in the AVL tree
    class Node:
        # Define the attributes of a node
        def __init__(self, key, parent):
            self.key = key
            self.parent = parent
            self.left = None
            self.right = None
            self.balance = 0
            self.height = 0

    # Define the attributes of the AVL tree
    def __init__(self):
        self.root = None

    # Method to insert a new key into the AVL tree
    def insert(self, key):
        # If the tree is empty, create the root node
        if self.root is None:
            self.root = self.Node(key, None)
        else:
            node = self.root
            parent = self.root
            while True:
                # Check for duplicate keys
                if node.key == key:
                    return False  # Key already exists
                parent = node
                # Determine whether to go left or right in the tree
                go_left = node.key > key
                node = node.left if go_left else node.right
                # If the child node is None, insert the new node
                if node is None:
                    if go_left:
                        parent.left = self.Node(key, parent)
                    else:
                        parent.right = self.Node(key, parent)
                    # Rebalance the tree after insertion
                    self.rebalance(parent)
                    break

        return True  # Insertion successful

    # Method to delete a key from the AVL tree
    def delete(self, del_key):
        # If the tree is empty, there's nothing to delete
        if self.root is None:
            return
        node = self.root
        child = self.root
        # Traverse the tree to find the node to delete
        while child is not None:
            node = child
            child = del_key >= node.key if node.key is not None else None
            # If the key is found, delete the node
            if del_key == node.key:
                self.delete_node(node)
                return

    # Helper method to delete a specific node from the tree
    def delete_node(self, node):
        # Case 1: Node has no children (leaf node)
        if node.left is None and node.right is None:
            # If it's the root node, set root to None
            if node.parent is None:
                self.root = None
            else:
                parent = node.parent
                # Remove the node from its parent's child reference
                if parent.left == node:
                    parent.left = None
                else:
                    parent.right = None
                # Rebalance the tree after deletion
                self.rebalance(parent)
            return

        # Case 2: Node has one child
        child = None
        if node.left is not None:
            # Find the maximum node in the left subtree
            child = node.left
            while child.right is not None:
                child = child.right
        else:
            # Find the minimum node in the right subtree
            child = node.right
            while child.left is not None:
                child = child.left
        # Replace the key of the node to be deleted with the found child's key
        node.key = child.key
        # Recursively delete the child node
        self.delete_node(child)

    # Method to search for a key in the AVL tree
    def search(self, key):
        result = self.search_helper(self.root, key)
        return result is not None  # Return True if found, False otherwise

    # Helper method to perform the actual search
    def search_helper(self, root, key):
        # Base case: if root is None or key is found
        if root is None or root.key == key:
            return root
        # Recursively search left or right subtree based on key comparison
        return key < root.key if root.key is not None else None if root.left is None else self.search_helper(root.left, key) else self.search_helper(root.right, key)

    # Method to display the keys in the AVL tree in sorted order
    def display(self):
        self.display_helper(self.root)
        print()  # Print a newline after displaying all keys

    # Helper method to perform in-order traversal of the tree
    def display_helper(self, node):
        if node is not None:
            self.display_helper(node.left)  # Visit left subtree
            print(node.key, end=" ")  # Print the key
            self.display_helper(node.right)  # Visit right subtree

    # Method to rebalance the AVL tree after insertion or deletion
    def rebalance(self, n):
        self.set_balance(n)  # Update balance factors
        # Perform rotations based on balance factor
        if n.balance == -2:
            if self.height(n.left.left) >= self.height(n.left.right):
                n = self.rotate_right(n)  # Right rotation
            else:
                n = self.rotate_left_then_right(n)  # Left-Right rotation
        elif n.balance == 2:
            if self.height(n.right.right) >= self.height(n.right.left):
                n = self.rotate_left(n)  # Left rotation
            else:
                n = self.rotate_right_then_left(n)  # Right-Left rotation
        # Rebalance the parent node if it exists
        if n.parent is not None:
            self.rebalance(n.parent)
        else:
            self.root = n  # Update root if necessary

    # Method to perform a left rotation on a given node
    def rotate_left(self, a):
        b = a.right  # Right child becomes the new root
        b.parent = a.parent  # Update parent reference
        a.right = b.left  # Move left child of b to be the right child of a
        if a.right is not None:
            a.right.parent = a  # Update parent reference of the new right child
        b.left = a  # Set a as the left child of b
        a.parent = b  # Update parent reference of a
        self.set_balance(a, b)  # Update balance factors
        return b  # Return the new root

    # Method to perform a right rotation on a given node
    def rotate_right(self, a):
        b = a.left  # Left child becomes the new root
        b.parent = a.parent  # Update parent reference
        a.left = b.right  # Move right child of b to be the left child of a
        if a.left is not None:
            a.left.parent = a  # Update parent reference of the new left child
        b.right = a  # Set a as the right child of b
        a.parent = b  # Update parent reference of a
        self.set_balance(a, b)  # Update balance factors
        return b  # Return the new root

    # Method to perform a left rotation followed by a right rotation
    def rotate_left_then_right(self, n):
        n.left = self.rotate_left(n.left)  # Perform left rotation on left child
        return self.rotate_right(n)  # Perform right rotation on n

    # Method to perform a right rotation followed by a left rotation
    def rotate_right_then_left(self, n):
        n.right = self.rotate_right(n.right)  # Perform right rotation on right child
        return self.rotate_left(n)  # Perform left rotation on n

    # Method to get the height of a node
    def height(self, n):
        return n.height if n is not None else -1  # Return -1 for None, otherwise return height

    # Method to set the balance factors for given nodes
    def set_balance(self, *nodes):
        for n in nodes:
            self.reheight(n)  # Update height
            n.balance = self.height(n.right) - self.height(n.left)  # Calculate balance factor

    # Method to update the height of a node
    def reheight(self, node):
        if node is not None:
            node.height = 1 + max(self.height(node.left), self.height(node.right))  # Update height based on children


# Main method to run the AVL tree operations
def main():
    tree = AVLTree()  # Create an instance of the AVL tree
    scanner = Scanner(System.in)  # Create a scanner for user input
    # Loop to continuously accept commands until "exit" is entered
    while scanner.hasNextLine():
        command = scanner.nextLine().strip()  # Read user command
        if command.lower() == "exit":
            break  # Exit the loop if the command is "exit"
        parts = command.split(" ")  # Split command into parts
        try:
            # Process commands for insert, delete, search, and display
            match command.lower():
                case "insert":
                    value_to_insert = int(parts[1])  # Parse the value to insert
                    tree.insert(value_to_insert)  # Insert the value into the tree
                    print(f"Inserted: {value_to_insert}")
                case "delete":
                    value_to_delete = int(parts[1])  # Parse the value to delete
                    tree.delete(value_to_delete)  # Delete the value from the tree
                    print(f"Deleted: {value_to_delete}")
                case "search":
                    value_to_search = int(parts[1])  # Parse the value to search
                    print(tree.search(value_to_search) and "Found" or "Not Found")  # Search and print result
                case "display":
                    tree.display()  # Display the tree
                case _:
                    print("Unknown command")  # Handle unknown commands
        except Exception as e:
            print("Invalid command or input")  # Handle invalid input

    scanner.close()  # Close the scanner


if __name__ == "__main__":
    main()



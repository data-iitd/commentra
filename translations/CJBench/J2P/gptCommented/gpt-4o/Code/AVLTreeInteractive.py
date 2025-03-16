class Node:
    def __init__(self, key, parent=None):
        self.key = key  # Key value of the node
        self.balance = 0  # Balance factor of the node
        self.height = 0  # Height of the node
        self.left = None  # Left child of the node
        self.right = None  # Right child of the node
        self.parent = parent  # Parent of the node


class AVLTree:
    def __init__(self):
        self.root = None  # Root node of the AVL tree

    def insert(self, key):
        if self.root is None:
            self.root = Node(key)
        else:
            n = self.root
            parent = None
            while True:
                if n.key == key:
                    return False  # Key already exists
                parent = n
                go_left = n.key > key
                n = n.left if go_left else n.right
                if n is None:
                    if go_left:
                        parent.left = Node(key, parent)
                    else:
                        parent.right = Node(key, parent)
                    self.rebalance(parent)
                    break
        return True  # Insertion successful

    def delete(self, del_key):
        if self.root is None:
            return
        node = self.root
        child = self.root
        while child is not None:
            node = child
            child = node.right if del_key >= node.key else node.left
            if del_key == node.key:
                self.delete_node(node)
                return

    def delete_node(self, node):
        if node.left is None and node.right is None:  # Case 1: Leaf node
            if node.parent is None:
                self.root = None
            else:
                parent = node.parent
                if parent.left == node:
                    parent.left = None
                else:
                    parent.right = None
                self.rebalance(parent)
            return

        # Case 2: Node with one child
        child = node.left if node.left else node.right
        if node.left is not None:
            child = node.left
            while child.right is not None:
                child = child.right
        else:
            child = node.right
            while child.left is not None:
                child = child.left

        node.key = child.key
        self.delete_node(child)

    def search(self, key):
        result = self.search_helper(self.root, key)
        return result is not None  # Return true if found, false otherwise

    def search_helper(self, root, key):
        if root is None or root.key == key:
            return root
        return self.search_helper(root.left, key) if key < root.key else self.search_helper(root.right, key)

    def display(self):
        self.display_helper(self.root)
        print()  # Print a newline after displaying all keys

    def display_helper(self, node):
        if node is not None:
            self.display_helper(node.left)  # Visit left subtree
            print(node.key, end=" ")  # Print the key
            self.display_helper(node.right)  # Visit right subtree

    def rebalance(self, n):
        self.set_balance(n)  # Update balance factors
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
        if n.parent is not None:
            self.rebalance(n.parent)
        else:
            self.root = n  # Update root if necessary

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

    def rotate_left_then_right(self, n):
        n.left = self.rotate_left(n.left)  # Perform left rotation on left child
        return self.rotate_right(n)  # Perform right rotation on n

    def rotate_right_then_left(self, n):
        n.right = self.rotate_right(n.right)  # Perform right rotation on right child
        return self.rotate_left(n)  # Perform left rotation on n

    def height(self, n):
        return -1 if n is None else n.height  # Return -1 for null, otherwise return height

    def set_balance(self, *nodes):
        for n in nodes:
            self.reheight(n)  # Update height
            n.balance = self.height(n.right) - self.height(n.left)  # Calculate balance factor

    def reheight(self, node):
        if node is not None:
            node.height = 1 + max(self.height(node.left), self.height(node.right))  # Update height based on children


def main():
    tree = AVLTree()  # Create an instance of the AVL tree
    while True:
        command = input().strip()  # Read user command
        if command.lower() == "exit":
            break  # Exit the loop if the command is "exit"
        parts = command.split()  # Split command into parts
        try:
            # Process commands for insert, delete, search, and display
            if parts[0] == "insert":
                value_to_insert = int(parts[1])  # Parse the value to insert
                tree.insert(value_to_insert)  # Insert the value into the tree
                print(f"Inserted: {value_to_insert}")
            elif parts[0] == "delete":
                value_to_delete = int(parts[1])  # Parse the value to delete
                tree.delete(value_to_delete)  # Delete the value from the tree
                print(f"Deleted: {value_to_delete}")
            elif parts[0] == "search":
                value_to_search = int(parts[1])  # Parse the value to search
                print("Found" if tree.search(value_to_search) else "Not Found")  # Search and print result
            elif parts[0] == "display":
                tree.display()  # Display the tree
            else:
                print("Unknown command")  # Handle unknown commands
        except Exception:
            print("Invalid command or input")  # Handle invalid input


if __name__ == "__main__":
    main()

# <END-OF-CODE>

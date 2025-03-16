class Node:
    def __init__(self, data):
        self.data = data  # Value of the node
        self.left = None  # Pointer to left child
        self.right = None  # Pointer to right child


class BinarySearchTree:
    def __init__(self):
        self.root = None  # Root node of the binary search tree

    def add(self, data):
        parent = None  # Parent node of the current node
        temp = self.root  # Temporary node for traversal
        direction = -1  # Direction to indicate where to add the new node

        # Traverse the tree to find the correct position for the new node
        while temp is not None:
            if data < temp.data:
                parent = temp  # Update parent to current node
                temp = temp.left  # Move to the left child
                direction = 0  # Set direction to left
            elif data > temp.data:
                parent = temp  # Update parent to current node
                temp = temp.right  # Move to the right child
                direction = 1  # Set direction to right
            else:
                print(f"{data} is already present in BST.")
                return

        # Create a new node for the data
        new_node = Node(data)
        # If the tree was empty, set the new node as the root
        if parent is None:
            self.root = new_node
        elif direction == 0:
            parent.left = new_node  # Add to the left of the parent
        else:
            parent.right = new_node  # Add to the right of the parent

    def remove(self, data):
        parent = None  # Parent node of the current node
        temp = self.root  # Temporary node for traversal
        direction = -1  # Direction to indicate where the node is located

        # Traverse the tree to find the node to be removed
        while temp is not None:
            if temp.data == data:
                break  # Node found
            elif data < temp.data:
                parent = temp  # Update parent to current node
                temp = temp.left  # Move to the left child
                direction = 0  # Set direction to left
            else:
                parent = temp  # Update parent to current node
                temp = temp.right  # Move to the right child
                direction = 1  # Set direction to right

        # If the node to be removed is found
        if temp is not None:
            replacement = None  # Node to replace the removed node

            # Case 1: Node has no children
            if temp.left is None and temp.right is None:
                replacement = None
            # Case 2: Node has only right child
            elif temp.left is None:
                replacement = temp.right
            # Case 3: Node has only left child
            elif temp.right is None:
                replacement = temp.left
            # Case 4: Node has two children
            else:
                successor_parent = temp  # Parent of the successor node
                successor = temp.right  # Start with the right child

                # Find the leftmost child of the right subtree (successor)
                while successor.left is not None:
                    successor_parent = successor
                    successor = successor.left

                # Replace the data of the node to be removed with the successor's data
                temp.data = successor.data
                # Adjust the successor's parent's child pointer
                if successor_parent != temp:
                    successor_parent.left = successor.right
                else:
                    successor_parent.right = successor.right
                return

            # Adjust the parent's child pointer to bypass the removed node
            if parent is None:
                self.root = replacement  # If the node to remove is root
            elif direction == 0:
                parent.left = replacement  # If the node is a left child
            else:
                parent.right = replacement  # If the node is a right child

    def find(self, data):
        temp = self.root  # Temporary node for traversal

        # Traverse the tree to find the value
        while temp is not None:
            if data == temp.data:
                print(f"{data} is present in the BST.")
                return True  # Value found
            elif data < temp.data:
                temp = temp.left  # Move to the left child
            else:
                temp = temp.right  # Move to the right child

        print(f"{data} not found.")
        return False  # Value not found

    def display(self):
        self.display_helper(self.root)  # Call helper method to display values
        print()  # Print a new line after displaying

    def display_helper(self, node):
        if node is not None:
            self.display_helper(node.left)  # Traverse left subtree
            print(node.data, end=" ")  # Print current node's data
            self.display_helper(node.right)  # Traverse right subtree


if __name__ == "__main__":
    bst = BinarySearchTree()  # Create a new instance of the BST

    # Loop to accept commands from the user
    while True:
        command = input().strip()  # Read user input
        if command.lower() == "exit":
            break  # Exit the loop if the command is "exit"

        parts = command.split()  # Split the command into parts
        try:
            # Process the command based on the first part
            if parts[0] == "add":
                bst.add(int(parts[1]))  # Add a new value
                print(f"Added: {parts[1]}")
            elif parts[0] == "remove":
                bst.remove(int(parts[1]))  # Remove a value
                print(f"Removed: {parts[1]}")
            elif parts[0] == "find":
                bst.find(int(parts[1]))  # Find a value
            elif parts[0] == "display":
                bst.display()  # Display the BST
            else:
                print(f"Unknown command: {parts[0]}")  # Handle unknown commands
        except Exception:
            print("Error: Invalid command or input.")  # Handle invalid input

# <END-OF-CODE>

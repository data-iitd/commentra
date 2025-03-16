class Node:
    def __init__(self, data):
        self.data = data  # Value of the node
        self.height = 1  # New node is initially added at height 1
        self.left = None  # Left child of the node
        self.right = None  # Right child of the node


class AVLTree:
    def __init__(self):
        self.root = None  # Root node of the AVL tree

    def insert(self, data):
        self.root = self._insert(self.root, data)  # Start the recursive insertion

    def _insert(self, node, item):
        if node is None:
            return Node(item)  # If the current node is null, create a new node

        # Recursively insert the item in the left or right subtree
        if item < node.data:
            node.left = self._insert(node.left, item)
        elif item > node.data:
            node.right = self._insert(node.right, item)

        # Update the height of the current node
        node.height = max(self._height(node.left), self._height(node.right)) + 1

        # Get the balance factor of the current node
        bf = self._balance_factor(node)

        # Perform rotations to maintain AVL tree balance
        if bf > 1 and item < node.left.data:
            return self._right_rotate(node)  # Left Left Case
        if bf < -1 and item > node.right.data:
            return self._left_rotate(node)  # Right Right Case
        if bf < -1 and item < node.right.data:
            node.right = self._right_rotate(node.right)  # Right Left Case
            return self._left_rotate(node)
        if bf > 1 and item > node.left.data:
            node.left = self._left_rotate(node.left)  # Left Right Case
            return self._right_rotate(node)

        return node  # Return the (potentially) new root of the subtree

    def display(self):
        self._display(self.root)  # Start displaying from the root
        print("Tree Height:", self.root.height if self.root else 0)  # Print the height of the tree

    def _display(self, node):
        if node is None:
            return  # Base case: if the node is null, return

        # Prepare the string representation of the current node
        str_repr = ""
        if node.left is not None:
            str_repr += str(node.left.data) + " => "
        else:
            str_repr += "END => "
        str_repr += str(node.data)
        if node.right is not None:
            str_repr += " <= " + str(node.right.data)
        else:
            str_repr += " <= END"
        print(str_repr)  # Print the current node

        # Recursively display the left and right subtrees
        if node.left is not None:
            self._display(node.left)
        if node.right is not None:
            self._display(node.right)

    def _height(self, node):
        if node is None:
            return 0  # Height of null node is 0
        return node.height  # Return the height of the node

    def _balance_factor(self, node):
        if node is None:
            return 0  # Balance factor of null node is 0
        return self._height(node.left) - self._height(node.right)  # Balance factor calculation

    def _right_rotate(self, c):
        b = c.left  # Set b as the left child of c
        t3 = b.right  # Store the right child of b
        b.right = c  # Perform rotation
        c.left = t3  # Update the left child of c

        # Update heights of the nodes after rotation
        c.height = max(self._height(c.left), self._height(c.right)) + 1
        b.height = max(self._height(b.left), self._height(b.right)) + 1
        return b  # Return the new root of the subtree

    def _left_rotate(self, c):
        b = c.right  # Set b as the right child of c
        t3 = b.left  # Store the left child of b
        b.left = c  # Perform rotation
        c.right = t3  # Update the right child of c

        # Update heights of the nodes after rotation
        c.height = max(self._height(c.left), self._height(c.right)) + 1
        b.height = max(self._height(b.left), self._height(b.right)) + 1
        return b  # Return the new root of the subtree


def main():
    tree = AVLTree()  # Create an instance of the AVL tree

    while True:
        command = input().strip()  # Read user input
        if command.lower() == "exit":
            break  # Exit the loop if "exit" command is given
        parts = command.split()  # Split the command into parts
        try:
            # Process the command based on the first part
            if parts[0] == "insert":
                if len(parts) < 2:
                    print("Error: Missing value for insert")  # Error for missing value
                else:
                    value = int(parts[1])  # Parse the value to insert
                    tree.insert(value)  # Insert the value into the tree
                    print("Inserted:", value)  # Confirmation message
            elif parts[0] == "display":
                tree.display()  # Display the tree structure
            else:
                print("Unknown command:", parts[0])  # Error for unknown command
        except Exception as e:
            print("Error:", e)  # Handle exceptions and print error message


if __name__ == "__main__":
    main()  # Run the main function

# <END-OF-CODE>


class Node:
    def __init__(self, data):
        self.data = data
        self.height = 1  # New node is initially added at height 1

    def insert(self, data):
        # If the current node is null, create a new node
        if self is None:
            return Node(data)

        # Recursively insert the item in the left or right subtree
        if data < self.data:
            self.left = self.left.insert(data) if self.left else Node(data)
        else:
            self.right = self.right.insert(data) if self.right else Node(data)

        # Update the height of the current node
        self.height = max(self.left.height if self.left else 0, self.right.height if self.right else 0) + 1

        # Get the balance factor of the current node
        bf = self.get_bf()

        # Perform rotations to maintain AVL tree balance
        if bf > 1 and data < self.left.data:
            return self.right_rotate()  # Left Left Case
        if bf < -1 and data > self.right.data:
            return self.left_rotate()  # Right Right Case
        if bf < -1 and data < self.right.data:
            self.right = self.right.right_rotate()  # Right Left Case
            return self.left_rotate()
        if bf > 1 and data > self.left.data:
            self.left = self.left.left_rotate()  # Left Right Case
            return self.right_rotate()

        return self  # Return the (potentially) new root of the subtree

    def display(self):
        self.display_node(self)
        print("Tree Height:", self.height)  # Print the height of the tree

    def display_node(self, node):
        if node is None:
            return  # Base case: if the node is null, return

        str = ""
        # Prepare the string representation of the current node
        if node.left:
            str += str(node.left.data) + " => "
        else:
            str += "END => "
        str += str(node.data)
        if node.right:
            str += " <= " + str(node.right.data)
        else:
            str += " <= END"
        print(str)  # Print the current node

        # Recursively display the left and right subtrees
        if node.left:
            self.display_node(node.left)
        if node.right:
            self.display_node(node.right)

    def get_bf(self):
        if self is None:
            return 0  # Balance factor of null node is 0
        return self.left.height if self.left else 0 - self.right.height if self.right else 0

    def right_rotate(self):
        b = self.left
        t3 = b.right
        b.right = self
        self.left = t3

        # Update heights of the nodes after rotation
        self.height = max(self.left.height if self.left else 0, self.right.height if self.right else 0) + 1
        b.height = max(b.left.height if b.left else 0, b.right.height if b.right else 0) + 1
        return b  # Return the new root of the subtree

    def left_rotate(self):
        b = self.right
        t3 = b.left
        b.left = self
        self.right = t3

        # Update heights of the nodes after rotation
        self.height = max(self.left.height if self.left else 0, self.right.height if self.right else 0) + 1
        b.height = max(b.left.height if b.left else 0, b.right.height if b.right else 0) + 1
        return b  # Return the new root of the subtree

# Main method to run the program
if __name__ == "__main__":
    tree = Node(None)  # Create an instance of the AVL tree
    while True:
        command = input("Enter command (exit to quit): ")  # Read user input
        if command.lower() == "exit":
            break  # Exit the loop if "exit" command is given
        parts = command.split()  # Split the command into parts
        try:
            # Process the command based on the first part
            if parts[0].lower() == "insert":
                if len(parts) < 2:
                    print("Error: Missing value for insert")  # Error for missing value
                else:
                    value = int(parts[1])  # Parse the value to insert
                    tree = tree.insert(value)  # Insert the value into the tree
                    print("Inserted:", value)  # Confirmation message
            elif parts[0].lower() == "display":
                tree.display()  # Display the tree structure
            else:
                print("Unknown command:", parts[0])  # Error for unknown command
        except Exception as e:
            print("Error:", e)  # Handle exceptions and print error message


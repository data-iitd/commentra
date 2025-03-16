
# Initialize an empty BST
class Main:
    def __init__(self):
        self.root = None

    # Add a new node with given data to the BST
    def add(self, data):
        parent = None # Keep track of the parent node
        temp = self.root # Initialize a temporary node to traverse the tree

        direction = -1 # Direction to move: 0 for left, 1 for right

        # Traverse the tree to find the location to insert the new node
        while temp!= None:
            if data < temp.data:
                parent = temp # Move left
                temp = temp.left
                direction = 0
            elif data > temp.data:
                parent = temp # Move right
                temp = temp.right
                direction = 1
            else: # Data already exists in the tree
                print(data, "is already present in BST.")
                return

        # Create a new node with the given data
        newNode = Node(data)

        # Insert the new node at the appropriate location in the tree
        if parent == None:
            self.root = newNode # If the tree is empty, the new node is the root
        elif direction == 0:
            parent.left = newNode # If the new node is to be inserted as a left child
        else:
            parent.right = newNode # If the new node is to be inserted as a right child

    # Remove a node with given data from the BST
    def remove(self, data):
        parent = None # Keep track of the parent node
        temp = self.root # Initialize a temporary node to traverse the tree

        direction = -1 # Direction to move: 0 for left, 1 for right

        # Traverse the tree to find the node to be removed
        while temp!= None:
            if temp.data == data:
                break # Node found
            elif data < temp.data:
                parent = temp # Move left
                temp = temp.left
                direction = 0
            else:
                parent = temp # Move right
                temp = temp.right
                direction = 1

        # Check if the node was found
        if temp == None:
            print(data, "not found.")
            return

        # Determine the replacement node
        replacement = None
        if temp.left == None and temp.right == None:
            replacement = None # Leaf node: no replacement needed
        elif temp.left == None:
            replacement = temp.right # Replace with the right child
        elif temp.right == None:
            replacement = temp.left # Replace with the left child
        else:
            successorParent = temp # Traverse to find the successor node
            successor = temp.right

            while successor.left!= None:
                successorParent = successor
                successor = successor.left

            temp.data = successor.data # Replace the data of the node to be removed with the data of the successor node

            if successorParent!= temp: # If the successor node is not the right child of the node to be removed
                successorParent.left = successor.right # Update the left child of the successor's parent
            else:
                successorParent.right = successor.right # Update the right child of the node to be removed

        # Update the tree based on the replacement node
        if parent == None:
            self.root = replacement # If the node to be removed was the root
        elif direction == 0:
            parent.left = replacement # If the node to be removed was a left child
        else:
            parent.right = replacement # If the node to be removed was a right child

    # Search for a node with given data in the BST
    def find(self, data):
        temp = self.root # Initialize a temporary node to traverse the tree

        # Traverse the tree to find the node with the given data
        while temp!= None:
            if data == temp.data:
                print(data, "is present in the BST.")
                return True
            elif data < temp.data:
                temp = temp.left
            else:
                temp = temp.right

        # If the node was not found
        print(data, "not found.")
        return False

    # Display the contents of the BST in-order
    def display(self):
        self.displayHelper(self.root) # Recursively traverse the tree and print the nodes in-order

    # Helper function to display the contents of the BST in-order
    def displayHelper(self, node):
        if node!= None:
            self.displayHelper(node.left) # Display the left subtree
            print(node.data, end=" ") # Display the current node
            self.displayHelper(node.right) # Display the right subtree

# Main method to read user input and perform operations on the BST
if __name__ == "__main__":
    bst = Main() # Initialize an empty BST

    while True:
        command = input().strip() # Read a user command

        if command.lower() == "exit": # Exit the program if the command is "exit"
            break

        parts = command.split(" ") # Split the command into parts based on whitespace

        try:
            if parts[0].lower() == "add":
                bst.add(int(parts[1])) # Add a new node with the given data
                print("Added:", parts[1])
            elif parts[0].lower() == "remove":
                bst.remove(int(parts[1])) # Remove a node with the given data
                print("Removed:", parts[1])
            elif parts[0].lower() == "find":
                bst.find(int(parts[1])) # Search for a node with the given data
            elif parts[0].lower() == "display":
                bst.display() # Display the contents of the BST
            else:
                print("Unknown command:", parts[0]) # Print an error message for an unknown command
        except Exception: # Handle any exceptions that might occur during command execution
            print("Error: Invalid command or input.")


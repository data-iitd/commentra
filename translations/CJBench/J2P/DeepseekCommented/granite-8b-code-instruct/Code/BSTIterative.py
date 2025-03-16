
class Node: # Inner class representing a node in the BST
    def __init__(self, data): # Constructor to initialize the node
        self.data = data
        self.left = None
        self.right = None

class Main: # Main class to implement the BST
    def __init__(self): # Constructor to initialize the BST
        self.root = None # Sets the root to null

    def add(self, data): # Method to add a new node with the given data to the BST
        parent = None # Parent node to keep track of the current node's parent
        temp = self.root # Temporary node to traverse the tree
        direction = -1 # Direction indicator (0 for left, 1 for right)
        while temp is not None: # Traverse the tree to find the correct position
            if data < temp.data:
                parent = temp
                temp = temp.left
                direction = 0
            elif data > temp.data:
                parent = temp
                temp = temp.right
                direction = 1
            else:
                print(data, "is already present in BST.") # Data already exists
                return
        newNode = Node(data) # Create a new node with the given data
        if parent is None:
            self.root = newNode # If the tree is empty, set the root to the new node
        elif direction == 0:
            parent.left = newNode # Set the left child of the parent to the new node
        else:
            parent.right = newNode # Set the right child of the parent to the new node

    def remove(self, data): # Method to remove a node with the given data from the BST
        parent = None # Parent node to keep track of the current node's parent
        temp = self.root # Temporary node to traverse the tree
        direction = -1 # Direction indicator (0 for left, 1 for right)
        while temp is not None: # Traverse the tree to find the node to remove
            if temp.data == data:
                break
            elif data < temp.data:
                parent = temp
                temp = temp.left
                direction = 0
            else:
                parent = temp
                temp = temp.right
                direction = 1
        if temp is not None: # If the node is found
            replacement = None # Node to replace the removed node
            if temp.left is None and temp.right is None:
                replacement = None # No children, set replacement to null
            elif temp.left is None:
                replacement = temp.right # Only right child, set replacement to right child
            elif temp.right is None:
                replacement = temp.left # Only left child, set replacement to left child
            else:
                successorParent = temp
                successor = temp.right
                while successor.left is not None:
                    successorParent = successor
                    successor = successor.left
                temp.data = successor.data # Replace the data with the successor's data
                if successorParent!= temp:
                    successorParent.left = successor.right # Set the left child of successor's parent to successor's right child
                else:
                    successorParent.right = successor.right # Set the right child of successor's parent to successor's right child
            if parent is None:
                self.root = replacement # If the node to remove is the root, set the root to the replacement
            elif direction == 0:
                parent.left = replacement # Set the left child of the parent to the replacement
            else:
                parent.right = replacement # Set the right child of the parent to the replacement

    def find(self, data): # Method to check if a node with the given data is present in the BST
        temp = self.root # Temporary node to traverse the tree
        while temp is not None: # Traverse the tree to find the node
            if data == temp.data:
                print(data, "is present in the BST.") # Data found
                return True
            elif data < temp.data:
                temp = temp.left # Move to the left child
            else:
                temp = temp.right # Move to the right child
        print(data, "not found.") # Data not found
        return False

    def display(self): # Method to display the elements of the BST in an in-order traversal
        self.displayHelper(self.root) # Call the helper method with the root node
        print()

    def displayHelper(self, node): # Helper method for the display method
        if node is not None: # Recursively traverse the tree in-order
            self.displayHelper(node.left)
            print(node.data, end=" ")
            self.displayHelper(node.right)

if __name__ == "__main__": # Main method to provide a command-line interface for the BST
    bst = Main() # Create a new instance of the BST
    while True: # Continuously read commands from the user
        command = input().strip()
        if command.lower() == "exit":
            break
        parts = command.split() # Split the command into parts
        try:
            if parts[0].lower() == "add":
                bst.add(int(parts[1])) # Add the given data to the BST
                print("Added:", parts[1])
            elif parts[0].lower() == "remove":
                bst.remove(int(parts[1])) # Remove the given data from the BST
                print("Removed:", parts[1])
            elif parts[0].lower() == "find":
                bst.find(int(parts[1])) # Find the given data in the BST
            elif parts[0].lower() == "display":
                bst.display() # Display the elements of the BST
            else:
                print("Unknown command:", parts[0]) # Unknown command
        except Exception as e:
            print("Error:", e) # Invalid command or input


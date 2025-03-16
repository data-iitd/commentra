
# Node class representing each node in the AVL tree
class Node:
    def __init__(self, data):
        self.data = data
        self.height = 1 # New node is initially added at height 1
        self.left = None
        self.right = None

class Main:
    def __init__(self):
        self.root = None

    # Public method to insert a new value into the AVL tree
    def insert(self, data):
        self.root = self.insert(self.root, data) # Start the recursive insertion

    # Private method to insert a new value into the tree rooted at 'node'
    def insert(self, node, item):
        # If the current node is null, create a new node
        if node == None:
            return Node(item)

        # Recursively insert the item in the left or right subtree
        if node.data > item:
            node.left = self.insert(node.left, item)
        elif node.data < item:
            node.right = self.insert(node.right, item)

        # Update the height of the current node
        node.height = max(self.height(node.left), self.height(node.right)) + 1

        # Get the balance factor of the current node
        bf = self.bf(node)

        # Perform rotations to maintain AVL tree balance
        if bf > 1 and item < node.left.data:
            return self.rightRotate(node) # Left Left Case
        if bf < -1 and item > node.right.data:
            return self.leftRotate(node) # Right Right Case
        if bf < -1 and item < node.right.data:
            node.right = self.rightRotate(node.right) # Right Left Case
            return self.leftRotate(node)
        if bf > 1 and item > node.left.data:
            node.left = self.leftRotate(node.left) # Left Right Case
            return self.rightRotate(node)

        return node # Return the (potentially) new root of the subtree

    # Public method to display the AVL tree
    def display(self):
        self.display(self.root) # Start displaying from the root
        print("Tree Height: " + str(self.root.height)) # Print the height of the tree

    # Private method to display the tree in a structured format
    def display(self, node):
        if node == None: return # Base case: if the node is null, return

        str = ""
        # Prepare the string representation of the current node
        if node.left!= None:
            str += str(node.left.data) + " => "
        else:
            str += "END => "
        str += str(node.data)
        if node.right!= None:
            str += " <= " + str(node.right.data)
        else:
            str += " <= END"
        print(str) # Print the current node

        # Recursively display the left and right subtrees
        if node.left!= None:
            self.display(node.left)
        if node.right!= None:
            self.display(node.right)

    # Method to get the height of a node
    def height(self, node):
        if node == None:
            return 0 # Height of null node is 0
        return node.height # Return the height of the node

    # Method to calculate the balance factor of a node
    def bf(self, node):
        if node == None:
            return 0 # Balance factor of null node is 0
        return self.height(node.left) - self.height(node.right) # Balance factor calculation

    # Method to perform a right rotation on a subtree rooted with 'c'
    def rightRotate(self, c):
        b = c.left # Set b as the left child of c
        t3 = b.right # Store the right child of b
        b.right = c # Perform rotation
        c.left = t3 # Update the left child of c

        # Update heights of the nodes after rotation
        c.height = max(self.height(c.left), self.height(c.right)) + 1
        b.height = max(self.height(b.left), self.height(b.right)) + 1
        return b # Return the new root of the subtree

    # Method to perform a left rotation on a subtree rooted with 'c'
    def leftRotate(self, c):
        b = c.right # Set b as the right child of c
        t3 = b.left # Store the left child of b
        b.left = c # Perform rotation
        c.right = t3 # Update the right child of c

        # Update heights of the nodes after rotation
        c.height = max(self.height(c.left), self.height(c.right)) + 1
        b.height = max(self.height(b.left), self.height(b.right)) + 1
        return b # Return the new root of the subtree

# Main method to run the program
if __name__ == "__main__":
    tree = Main() # Create an instance of the AVL tree
    scanner = Scanner(System.in) # Create a scanner for user input

    # Loop to accept commands until "exit" is entered
    while scanner.hasNextLine():
        command = scanner.nextLine().trim() # Read user input
        if command.equalsIgnoreCase("exit"):
            break # Exit the loop if "exit" command is given
        parts = command.split(" ") # Split the command into parts
        try:
            # Process the command based on the first part
            if parts[0] == "insert":
                if len(parts) < 2:
                    print("Error: Missing value for insert") # Error for missing value
                else:
                    value = int(parts[1]) # Parse the value to insert
                    tree.insert(value) # Insert the value into the tree
                    print("Inserted: " + str(value)) # Confirmation message
            elif parts[0] == "display":
                tree.display() # Display the tree structure
            else:
                print("Unknown command: " + parts[0]) # Error for unknown command
        except Exception as e:
            print("Error: " + e.getMessage()) # Handle exceptions and print error message
    scanner.close() # Close the scanner


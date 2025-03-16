
# Node class representing each node in the binary search tree (BST)
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Main:
    def __init__(self):
        self.root = None # Initially, the tree is empty

    # Getter method to retrieve the root of the BST
    def getRoot(self):
        return self.root

    # Recursive method to insert a new value into the BST
    def insert(self, node, data):
        # If the current node is null, create a new node
        if node == None:
            node = Node(data)
        # If the data is less than the current node's data, insert in the left subtree
        elif data < node.data:
            node.left = self.insert(node.left, data)
        # If the data is greater than the current node's data, insert in the right subtree
        elif data > node.data:
            node.right = self.insert(node.right, data)
        return node # Return the (potentially new) node

    # Public method to add a new value to the BST
    def add(self, data):
        self.root = self.insert(self.root, data) # Start the insertion from the root

    # Recursive method to delete a value from the BST
    def delete(self, node, data):
        # If the node is null, the data is not found
        if node == None:
            print("No such data present in BST.")
            return None
        # If the data is less than the current node's data, search in the left subtree
        if data < node.data:
            node.left = self.delete(node.left, data)
        # If the data is greater than the current node's data, search in the right subtree
        elif data > node.data:
            node.right = self.delete(node.right, data)
        # Node with the data found
        else:
            # Case 1: Node has no children
            if node.left == None and node.right == None:
                return None # Remove the node
            # Case 2: Node has only right child
            elif node.left == None:
                return node.right # Bypass the node
            # Case 3: Node has only left child
            elif node.right == None:
                return node.left # Bypass the node
            # Case 4: Node has two children
            else:
                # Find the minimum value in the right subtree
                temp = self.findMin(node.right)
                node.data = temp.data # Replace with the minimum value
                node.right = self.delete(node.right, temp.data) # Delete the minimum node
        return node # Return the (potentially modified) node

    # Public method to remove a value from the BST
    def remove(self, data):
        self.root = self.delete(self.root, data) # Start the deletion from the root

    # Helper method to find the minimum value node in a subtree
    def findMin(self, node):
        # Traverse to the leftmost node
        while node.left!= None:
            node = node.left
        return node # Return the minimum node

    # Recursive method to search for a value in the BST
    def search(self, node, data):
        # If the node is null, the value is not found
        if node == None:
            return False
        # If the data is less than the current node's data, search in the left subtree
        elif data < node.data:
            return self.search(node.left, data)
        # If the data is greater than the current node's data, search in the right subtree
        elif data > node.data:
            return self.search(node.right, data)
        # Value found
        else:
            return True

    # Public method to find a value in the BST and print the result
    def find(self, data):
        result = self.search(self.root, data) # Search for the value
        # Print whether the value is found or not
        if result:
            print(data, "is present in the BST.")
        else:
            print(data, "is not found.")
        return result # Return the result of the search

    # Method to perform in-order traversal of the BST
    def inOrderTraversal(self, node):
        # If the node is not null, traverse the left subtree, print the node, and traverse the right subtree
        if node!= None:
            self.inOrderTraversal(node.left)
            print(node.data, end=" ") # Print the current node's data
            self.inOrderTraversal(node.right)

    # Main method to run the program
    def main(self):
        scanner = Scanner(System.in) # Create a scanner for user input
        n = scanner.nextInt() # Read the number of operations to perform

        # Loop to perform operations based on user input
        for i in range(n):
            choice = scanner.nextInt() # Read the user's choice of operation
            if choice == 1: # Insert operation
                insertValue = scanner.nextInt() # Read the value to insert
                self.add(insertValue) # Add the value to the BST
            elif choice == 2: # Delete operation
                deleteValue = scanner.nextInt() # Read the value to delete
                self.remove(deleteValue) # Remove the value from the BST
            elif choice == 3: # Search operation
                searchValue = scanner.nextInt() # Read the value to search for
                self.find(searchValue) # Find the value in the BST
            elif choice == 4: # In-order traversal operation
                self.inOrderTraversal(self.getRoot()) # Print the values in in-order
                print() # Print a new line after traversal
            else: # Invalid choice
                print("Invalid choice. Try again.") # Prompt for a valid choice
        scanner.close() # Close the scanner

# 
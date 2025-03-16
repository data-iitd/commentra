class Node:
    # Node class representing each node in the binary search tree (BST)
    def __init__(self, data):
        self.data = data  # Value of the node
        self.left = None  # Left child of the node
        self.right = None  # Right child of the node


class BST:
    def __init__(self):
        self.root = None  # Initially, the tree is empty

    # Recursive method to insert a new value into the BST
    def insert(self, node, data):
        if node is None:
            return Node(data)  # Create a new node
        elif data < node.data:
            node.left = self.insert(node.left, data)  # Insert in the left subtree
        elif data > node.data:
            node.right = self.insert(node.right, data)  # Insert in the right subtree
        return node  # Return the (potentially new) node

    # Public method to add a new value to the BST
    def add(self, data):
        self.root = self.insert(self.root, data)  # Start the insertion from the root

    # Recursive method to delete a value from the BST
    def delete(self, node, data):
        if node is None:
            print("No such data present in BST.")
            return None  # Data not found
        if data < node.data:
            node.left = self.delete(node.left, data)  # Search in the left subtree
        elif data > node.data:
            node.right = self.delete(node.right, data)  # Search in the right subtree
        else:
            # Node with the data found
            if node.left is None and node.right is None:  # Case 1: No children
                return None  # Remove the node
            elif node.left is None:  # Case 2: Only right child
                return node.right  # Bypass the node
            elif node.right is None:  # Case 3: Only left child
                return node.left  # Bypass the node
            else:  # Case 4: Two children
                temp = self.find_min(node.right)  # Find the minimum value in the right subtree
                node.data = temp.data  # Replace with the minimum value
                node.right = self.delete(node.right, temp.data)  # Delete the minimum node
        return node  # Return the (potentially modified) node

    # Public method to remove a value from the BST
    def remove(self, data):
        self.root = self.delete(self.root, data)  # Start the deletion from the root

    # Helper method to find the minimum value node in a subtree
    def find_min(self, node):
        while node.left is not None:
            node = node.left  # Traverse to the leftmost node
        return node  # Return the minimum node

    # Recursive method to search for a value in the BST
    def search(self, node, data):
        if node is None:
            return False  # Value not found
        if data < node.data:
            return self.search(node.left, data)  # Search in the left subtree
        elif data > node.data:
            return self.search(node.right, data)  # Search in the right subtree
        else:
            return True  # Value found

    # Public method to find a value in the BST and print the result
    def find(self, data):
        result = self.search(self.root, data)  # Search for the value
        if result:
            print(f"{data} is present in the BST.")
        else:
            print(f"{data} is not found.")
        return result  # Return the result of the search

    # Method to perform in-order traversal of the BST
    def in_order_traversal(self, node):
        if node is not None:
            self.in_order_traversal(node.left)  # Traverse the left subtree
            print(node.data, end=" ")  # Print the current node's data
            self.in_order_traversal(node.right)  # Traverse the right subtree


# Main method to run the program
if __name__ == "__main__":
    import sys

    bst = BST()  # Create a new instance of the BST
    n = int(input())  # Read the number of operations to perform

    # Loop to perform operations based on user input
    for _ in range(n):
        choice = int(input())  # Read the user's choice of operation
        if choice == 1:  # Insert operation
            insert_value = int(input())  # Read the value to insert
            bst.add(insert_value)  # Add the value to the BST
        elif choice == 2:  # Delete operation
            delete_value = int(input())  # Read the value to delete
            bst.remove(delete_value)  # Remove the value from the BST
        elif choice == 3:  # Search operation
            search_value = int(input())  # Read the value to search for
            bst.find(search_value)  # Find the value in the BST
        elif choice == 4:  # In-order traversal operation
            bst.in_order_traversal(bst.root)  # Print the values in in-order
            print()  # Print a new line after traversal
        else:  # Invalid choice
            print("Invalid choice. Try again.")  # Prompt for a valid choice

# <END-OF-CODE>

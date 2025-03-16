
# Define a Node class for BST node
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


# Main class with a private Node reference to the root of BST
class Main:
    def __init__(self):
        self.root = None  # Initialize root to null

    # Getter method for root reference
    def getRoot(self):
        return self.root

    # Method to insert a new node in the BST
    def insert(self, node, data):
        # If the tree is empty, return a new node
        if node is None:
            node = Node(data)

        # If the new data is smaller than the current node, traverse left
        elif data < node.data:
            node.left = self.insert(node.left, data)

        # If the new data is greater than the current node, traverse right
        elif data > node.data:
            node.right = self.insert(node.right, data)

        # Return the current node
        return node

    # Method to add a new node to the BST
    def add(self, data):
        self.root = self.insert(self.root, data)  # Insert the new node in the BST

    # Method to delete a node from the BST
    def delete(self, node, data):
        # If the tree is empty, return null
        if node is None:
            print("No such data present in BST.")
            return None

        # If the data to be deleted is smaller than the current node, traverse left
        if data < node.data:
            node.left = self.delete(node.left, data)

        # If the data to be deleted is greater than the current node, traverse right
        elif data > node.data:
            node.right = self.delete(node.right, data)

        # If the data to be deleted is equal to the current node, perform deletion
        else:
            # If the current node has no children
            if node.left is None and node.right is None:
                return None

            # If the current node has only one child or no children
            elif node.left is None:
                return node.right

            elif node.right is None:
                return node.left

            # If the current node has two children, find the minimum node in the right subtree
            else:
                temp = self.findMin(node.right)
                node.data = temp.data
                node.right = self.delete(node.right, temp.data)

        # Return the modified node
        return node

    # Method to remove a node from the BST
    def remove(self, data):
        self.root = self.delete(self.root, data)  # Delete the node from the BST

    # Method to find the minimum node in the BST
    def findMin(self, node):
        # Traverse left until we reach the minimum node
        while node.left is not None:
            node = node.left
        return node

    # Method to search for a node in the BST
    def search(self, node, data):
        # If the tree is empty, return false
        if node is None:
            return False

        # If the data to be searched is smaller than the current node, traverse left
        if data < node.data:
            return self.search(node.left, data)

        # If the data to be searched is greater than the current node, traverse right
        elif data > node.data:
            return self.search(node.right, data)

        # If the data to be searched is equal to the current node, return true
        else:
            return True

    # Method to search for a node in the BST and print the result
    def find(self, data):
        result = self.search(self.root, data)  # Search for the node in the BST
        if result:
            print(data, "is present in the BST.")
        else:
            print(data, "is not found.")
        return result

    # Method to perform inorder traversal of the BST and print the elements
    def inOrderTraversal(self, node):
        # If the node is not null, traverse left, print the data, and traverse right
        if node is not None:
            self.inOrderTraversal(node.left)
            print(node.data, end=" ")
            self.inOrderTraversal(node.right)

    # Main method to take user input and perform the required operations on the BST
    def main(self):
        # Create a Scanner object to read user input
        scanner = Scanner(System.in)

        # Read the number of nodes to be inserted in the BST
        n = scanner.nextInt()

        # Perform the required operations based on user input
        for i in range(n):
            choice = scanner.nextInt()
            if choice == 1:  # Insert a new node
                insertValue = scanner.nextInt()
                self.add(insertValue)
            elif choice == 2:  # Delete a node
                deleteValue = scanner.nextInt()
                self.remove(deleteValue)
            elif choice == 3:  # Search for a node
                searchValue = scanner.nextInt()
                self.find(searchValue)
            elif choice == 4:  # Perform inorder traversal and print the elements
                self.inOrderTraversal(self.getRoot())
                print()
            else:
                print("Invalid choice. Try again.")

        # Close the Scanner object
        scanner.close()


# 
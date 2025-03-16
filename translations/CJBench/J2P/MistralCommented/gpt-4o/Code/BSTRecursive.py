class Node:
    def __init__(self, data):
        self.data = data  # Data to be stored in the node
        self.left = None  # Reference to left child
        self.right = None  # Reference to right child


class BST:
    def __init__(self):
        self.root = None  # Initialize root to None

    def insert(self, node, data):
        # If the tree is empty, return a new node
        if node is None:
            return Node(data)

        # If the new data is smaller than the current node, traverse left
        if data < node.data:
            node.left = self.insert(node.left, data)
        # If the new data is greater than the current node, traverse right
        elif data > node.data:
            node.right = self.insert(node.right, data)

        # Return the current node
        return node

    def add(self, data):
        self.root = self.insert(self.root, data)  # Insert the new node in the BST

    def delete(self, node, data):
        # If the tree is empty, return None
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
            # If the current node has only one child
            elif node.left is None:
                return node.right
            elif node.right is None:
                return node.left
            # If the current node has two children, find the minimum node in the right subtree
            else:
                temp = self.find_min(node.right)
                node.data = temp.data
                node.right = self.delete(node.right, temp.data)

        # Return the modified node
        return node

    def remove(self, data):
        self.root = self.delete(self.root, data)  # Delete the node from the BST

    def find_min(self, node):
        # Traverse left until we reach the minimum node
        while node.left is not None:
            node = node.left
        return node

    def search(self, node, data):
        # If the tree is empty, return False
        if node is None:
            return False

        # If the data to be searched is smaller than the current node, traverse left
        if data < node.data:
            return self.search(node.left, data)
        # If the data to be searched is greater than the current node, traverse right
        elif data > node.data:
            return self.search(node.right, data)
        # If the data to be searched is equal to the current node, return True
        else:
            return True

    def find(self, data):
        result = self.search(self.root, data)  # Search for the node in the BST
        if result:
            print(f"{data} is present in the BST.")
        else:
            print(f"{data} is not found.")
        return result

    def in_order_traversal(self, node):
        # If the node is not None, traverse left, print the data, and traverse right
        if node is not None:
            self.in_order_traversal(node.left)
            print(node.data, end=" ")
            self.in_order_traversal(node.right)

# Main function to take user input and perform the required operations on the BST
if __name__ == "__main__":
    bst = BST()  # Create an instance of the BST class

    # Read the number of nodes to be inserted in the BST
    n = int(input("Enter number of operations: "))

    # Perform the required operations based on user input
    for _ in range(n):
        choice = int(input("Enter choice (1: insert, 2: delete, 3: search, 4: in-order traversal): "))
        if choice == 1:  # Insert a new node
            insert_value = int(input("Enter value to insert: "))
            bst.add(insert_value)
        elif choice == 2:  # Delete a node
            delete_value = int(input("Enter value to delete: "))
            bst.remove(delete_value)
        elif choice == 3:  # Search for a node
            search_value = int(input("Enter value to search: "))
            bst.find(search_value)
        elif choice == 4:  # Perform in-order traversal and print the elements
            bst.in_order_traversal(bst.root)
            print()
        else:
            print("Invalid choice. Try again.")

# <END-OF-CODE>

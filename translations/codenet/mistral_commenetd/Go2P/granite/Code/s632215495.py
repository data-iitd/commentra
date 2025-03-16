
# Importing necessary packages
import sys

# Defining node and tree structures
class Node:
    def __init__(self, key):
        self.key = key
        self.parent = None
        self.left = None
        self.right = None

class Tree:
    def __init__(self):
        self.root = None

    # Method to insert a new node into the tree
    def insert(self, key):
        # Base case: If the tree is empty, create a new root node
        if self.root is None:
            self.root = Node(key)
            return

        # Variables to keep track of current and previous nodes
        current_node = self.root
        prev_node = None

        # Traverse the tree to find the correct position for the new node
        while current_node is not None:
            prev_node = current_node
            if current_node.key < key:
                current_node = current_node.right
            else:
                current_node = current_node.left

        # Create a new node with the given key
        new_node = Node(key)

        # Set the new node's parent to the previous node
        new_node.parent = prev_node

        # If the previous node's key is less than the new node's key,
        # set the previous node's right child to the new node
        if prev_node.key < key:
            prev_node.right = new_node
        else:
            # Otherwise, set the previous node's left child to the new node
            prev_node.left = new_node

    # Method to print the tree in inorder and preorder traversals
    def print(self):
        # Base case: If the tree is empty, print an empty tree
        if self.root is None:
            print("")
            print("")
            return

        # Variable to store the visited nodes in inorder traversal
        acc = []

        # Print the tree in inorder and preorder traversals
        print("Inorder traversal: ", end=" ")
        self.inorder(self.root, acc)
        print("")
        print("Preorder traversal: ", end=" ")
        self.preorder(self.root, acc)
        print("")

    # Helper functions for depth-first traversals of the tree
    def preorder(self, node, acc):
        # Base case: If the node is None, return the accumulator array
        if node is None:
            return acc

        # Add the current node's key to the accumulator array
        acc.append(node.key)

        # Recursively traverse the left and right subtrees
        if node.left is not None:
            acc = self.preorder(node.left, acc)
        if node.right is not None:
            acc = self.preorder(node.right, acc)

        # Return the updated accumulator array
        return acc

    def inorder(self, node, acc):
        # Base case: If the node is None, return the accumulator array
        if node is None:
            return acc

        # Recursively traverse the left subtree and add its keys to the accumulator array
        if node.left is not None:
            acc = self.inorder(node.left, acc)

        # Add the current node's key to the accumulator array
        acc.append(node.key)

        # Recursively traverse the right subtree and add its keys to the accumulator array
        if node.right is not None:
            acc = self.inorder(node.right, acc)

        # Return the updated accumulator array
        return acc

# Main function to read input and call the appropriate methods
def main():
    # Creating a new scanner to read input from stdin
    sc = sys.stdin

    # Reading the number of nodes in the tree
    n = int(sc.readline())

    # Creating a new tree object
    tree = Tree()

    # Reading the commands and calling the appropriate methods
    for i in range(n):
        command = sc.readline().strip()
        if command == "insert":
            key = int(sc.readline())
            tree.insert(key)
        elif command == "print":
            tree.print()
        else:
            raise ValueError("unknown command: " + command)

# Call the main function
if __name__ == "__main__":
    main()

Translate the above Python code to C++ and end with comment "
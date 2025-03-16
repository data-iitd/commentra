# Importing necessary packages
import sys

# Defining node and tree classes
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
        new_node.parent = prev_node

        # Set the new node's parent to the previous node
        if prev_node.key < key:
            prev_node.right = new_node
        else:
            prev_node.left = new_node

    # Method to print the tree in inorder and preorder traversals
    def print_tree(self):
        # Base case: If the tree is empty, print an empty tree
        if self.root is None:
            print("")
            print("")
            return

        # Print the tree in inorder and preorder traversals
        print("Inorder traversal: ", " ".join(map(str, self.visit_inorder(self.root, []))))
        print("Preorder traversal: ", " ".join(map(str, self.visit_preorder(self.root, []))))

    # Helper functions for depth-first traversals of the tree
    def visit_preorder(self, node, acc):
        # Base case: If the node is None, return the accumulator array
        if node is None:
            return acc

        # Add the current node's key to the accumulator array
        acc.append(node.key)

        # Recursively traverse the left and right subtrees
        if node.left is not None:
            self.visit_preorder(node.left, acc)
        if node.right is not None:
            self.visit_preorder(node.right, acc)

        # Return the updated accumulator array
        return acc

    def visit_inorder(self, node, acc):
        # Base case: If the node is None, return the accumulator array
        if node is None:
            return acc

        # Recursively traverse the left subtree and add its keys to the accumulator array
        if node.left is not None:
            self.visit_inorder(node.left, acc)

        # Add the current node's key to the accumulator array
        acc.append(node.key)

        # Recursively traverse the right subtree and add its keys to the accumulator array
        if node.right is not None:
            self.visit_inorder(node.right, acc)

        # Return the updated accumulator array
        return acc

# Main function to read input and call the appropriate methods
def main():
    # Creating a new tree object
    tree = Tree()

    # Reading the number of nodes in the tree
    n = int(sys.stdin.readline().strip())

    # Reading the commands and calling the appropriate methods
    for _ in range(n):
        command = sys.stdin.readline().strip()
        if command.startswith("insert"):
            _, key = command.split()
            tree.insert(int(key))
        elif command == "print":
            tree.print_tree()
        else:
            raise ValueError("unknown command: " + command)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

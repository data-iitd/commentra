
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
        currentNode = self.root
        prevNode = None

        # Traverse the tree to find the correct position for the new node
        while currentNode is not None:
            prevNode = currentNode
            if currentNode.key < key:
                currentNode = currentNode.right
            else:
                currentNode = currentNode.left

        # Create a new node with the given key
        newNode = Node(key)

        # Set the new node's parent to the previous node
        newNode.parent = prevNode

        # If the previous node's key is less than the new node's key,
        # set the previous node's right child to the new node
        if prevNode.key < key:
            prevNode.right = newNode
        else:
            # Otherwise, set the previous node's left child to the new node
            prevNode.left = newNode

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
        print("Inorder traversal: ", " ".join(map(str, visitInorder(self.root, acc))))
        print("Preorder traversal: ", " ".join(map(str, visitPreorder(self.root, acc))))

# Helper functions for depth-first traversals of the tree
def visitPreorder(node, acc):
    # Base case: If the node is None, return the accumulator array
    if node is None:
        return acc

    # Add the current node's key to the accumulator array
    acc.append(node.key)

    # Recursively traverse the left and right subtrees
    if node.left is not None:
        acc = visitPreorder(node.left, acc)
    if node.right is not None:
        acc = visitPreorder(node.right, acc)

    # Return the updated accumulator array
    return acc

def visitInorder(node, acc):
    # Base case: If the node is None, return the accumulator array
    if node is None:
        return acc

    # Recursively traverse the left subtree and add its keys to the accumulator array
    if node.left is not None:
        acc = visitInorder(node.left, acc)

    # Add the current node's key to the accumulator array
    acc.append(node.key)

    # Recursively traverse the right subtree and add its keys to the accumulator array
    if node.right is not None:
        acc = visitInorder(node.right, acc)

    # Return the updated accumulator array
    return acc

# Main function to read input and call the appropriate methods
def main():
    # Creating a new scanner to read input from stdin
    sc = sys.stdin

    # Reading the number of nodes in the tree
    n = int(sc.readline().strip())

    # Creating a new tree object
    tree = Tree()

    # Reading the commands and calling the appropriate methods
    for i in range(n):
        command = sc.readline().strip()
        if command == "insert":
            key = int(sc.readline().strip())
            tree.insert(key)
        elif command == "print":
            tree.print()
        else:
            raise ValueError("unknown command: " + command)

if __name__ == "__main__":
    main()


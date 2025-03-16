
import sys

class Main: # Generic class definition
    def __init__(self, data):
        self.data = data # Data stored in the node
        self.leftNode = None # Reference to the left child node
        self.rightNode = None # Reference to the right child node

    # Getter for the data stored in the node
    def getData(self):
        return self.data

    # Setter for the left child node
    def setLeftNode(self, leftNode):
        self.leftNode = leftNode

    # Setter for the right child node
    def setRightNode(self, rightNode):
        self.rightNode = rightNode

    # Getter for the left child node
    def getLeftNode(self):
        return self.leftNode

    # Getter for the right child node
    def getRightNode(self):
        return self.rightNode

    # Method to check if the node is a leaf node (i.e., has no children)
    def isLeafNode(self):
        return self.leftNode is None and self.rightNode is None

# Main method to run the program
if __name__ == "__main__":
    n = int(input()) # Read the number of nodes
    nodes = [Main(i) for i in range(1, n + 1)] # Create an array of Main nodes
    for i in range(n - 1):
        parent = int(input()) # Read the parent node index
        child = int(input()) # Read the child node index
        direction = input() # Read the direction (L or R)
        if direction == "L":
            nodes[parent - 1].setLeftNode(nodes[child - 1]) # Set the left child
        elif direction == "R":
            nodes[parent - 1].setRightNode(nodes[child - 1]) # Set the right child
    preOrderTraversal(nodes[0]) # Start pre-order traversal from the root node

# Private static method to perform pre-order traversal and print the data
def preOrderTraversal(root):
    if root is None:
        return # Base case: if the node is null, return
    print(root.getData(), end=" ") # Print the data of the current node
    preOrderTraversal(root.getLeftNode()) # Recursively traverse the left subtree
    preOrderTraversal(root.getRightNode()) # Recursively traverse the right subtree

print("
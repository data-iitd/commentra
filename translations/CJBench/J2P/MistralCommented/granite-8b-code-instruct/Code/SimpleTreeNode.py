

import sys

class Main: # Defining a generic class named Main with type parameter E
    def __init__(self, data): # Constructor for initializing a new node with given data
        self.data = data
        self.leftNode = None # Initializing the left child node as None
        self.rightNode = None # Initializing the right child node as None

    def getData(self): # Method for getting the data of the current node
        return self.data

    def setLeftNode(self, leftNode): # Method for setting the left child node
        self.leftNode = leftNode

    def setRightNode(self, rightNode): # Method for setting the right child node
        self.rightNode = rightNode

    def getLeftNode(self): # Method for getting the left child node
        return self.leftNode

    def getRightNode(self): # Method for getting the right child node
        return self.rightNode

    def isLeafNode(self): # Method for checking if the current node is a leaf node (has no children)
        return self.leftNode is None and self.rightNode is None

if __name__ == "__main__": # Main block for reading input and performing tree construction
    n = int(input()) # Reading the number of nodes in the tree from the console
    nodes = [Main(i) for i in range(1, n + 1)] # Creating a list of size n+1 to store the tree nodes

    for i in range(n - 1): # Loop for reading the parent-child relationships and connecting the nodes
        parent = int(input()) # Reading the parent node index from the console
        child = int(input()) # Reading the child node index from the console
        direction = input() # Reading the direction of the relationship (L for left or R for right)

        if direction == "L": # If the relationship is left, set the left child of the parent node
            nodes[parent - 1].setLeftNode(nodes[child - 1])
        elif direction == "R": # If the relationship is right, set the right child of the parent node
            nodes[parent - 1].setRightNode(nodes[child - 1])

    def preOrderTraversal(root): # Recursive method for performing pre-order traversal of the tree
        if root is None: # Base case: if the root is None, return
            return
        print(root.getData(), end=" ") # Printing the data of the current node
        preOrderTraversal(root.getLeftNode()) # Recursively traversing the left subtree
        preOrderTraversal(root.getRightNode()) # Recursively traversing the right subtree

    preOrderTraversal(nodes[0]) # Performing pre-order traversal of the tree starting from the root node


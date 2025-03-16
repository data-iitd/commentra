
class Node:
    # Node data
    def __init__(self, data):
        self.data = data
        # References to left and right child nodes
        self.leftNode = None
        self.rightNode = None

    # Getter method for node data
    def getData(self):
        return self.data

    # Setter method for the left child node
    def setLeftNode(self, leftNode):
        self.leftNode = leftNode

    # Setter method for the right child node
    def setRightNode(self, rightNode):
        self.rightNode = rightNode

    # Getter method for the left child node
    def getLeftNode(self):
        return self.leftNode

    # Getter method for the right child node
    def getRightNode(self):
        return self.rightNode

    # Method to check if the current node is a leaf node
    def isLeafNode(self):
        return self.leftNode is None and self.rightNode is None

# Main method to execute the program
def main():
    # Create a scanner object for user input
    scanner = Scanner(System.in)
    
    # Read the number of nodes
    n = scanner.nextInt()
    # Create an array to hold the nodes
    nodes = [None] * (n + 1)
    
    # Initialize the nodes with their respective data
    for i in range(1, n + 1):
        nodes[i] = Node(i)
    
    # Read parent-child relationships and set the left or right child accordingly
    for i in range(n - 1):
        parent = scanner.nextInt()
        child = scanner.nextInt()
        direction = scanner.next()
        if direction == "L":
            # Set the left child node
            nodes[parent].setLeftNode(nodes[child])
        elif direction == "R":
            # Set the right child node
            nodes[parent].setRightNode(nodes[child])
    
    # Perform a pre-order traversal starting from the root node
    preOrderTraversal(nodes[1])
    # Close the scanner to prevent resource leaks
    scanner.close()

# Method to perform pre-order traversal of the binary tree
def preOrderTraversal(root):
    # Base case: if the current node is null, return
    if root is None:
        return
    # Print the data of the current node
    print(root.getData(), end=" ")
    # Recursively traverse the left subtree
    preOrderTraversal(root.getLeftNode())
    # Recursively traverse the right subtree
    preOrderTraversal(root.getRightNode())

# Call the main method to start the program
if __name__ == "__main__":
    main()


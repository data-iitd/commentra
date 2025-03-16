import sys

# Node data
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Method to perform pre-order traversal of the binary tree
def preOrderTraversal(root):
    # Base case: if the current node is null, return
    if root == None:
        return
    # Print the data of the current node
    print(root.data, end=" ")
    # Recursively traverse the left subtree
    preOrderTraversal(root.left)
    # Recursively traverse the right subtree
    preOrderTraversal(root.right)

# Main method to execute the program
def main():
    # Read the number of nodes
    n = int(input())
    # Create an array to hold the nodes
    nodes = [None] * (n + 1)
    
    # Initialize the nodes with their respective data
    for i in range(1, n + 1):
        nodes[i] = Node(i)
    
    # Read parent-child relationships and set the left or right child accordingly
    for i in range(0, n - 1):
        parent = int(input())
        child = int(input())
        direction = input()
        if direction == "L":
            # Set the left child node
            nodes[parent].left = nodes[child]
        elif direction == "R":
            # Set the right child node
            nodes[parent].right = nodes[child]
    
    # Perform a pre-order traversal starting from the root node
    preOrderTraversal(nodes[1])

# Entry point of the program
if __name__ == "__main__":
    main()

# 
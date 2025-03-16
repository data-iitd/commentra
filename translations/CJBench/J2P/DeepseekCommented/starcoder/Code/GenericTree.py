import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;
class Main:
    # Define the Node class which represents a node in the tree
    class Node:
        def __init__(self, data):
            self.data = data
            self.child = []

    # Root node of the tree
    root = None

    # Constructor to build the tree using user input
    def __init__(self, scn):
        self.root = self.createTree(None, 0, scn) # Create the tree starting with a null parent

    # Recursive method to create the tree
    def createTree(self, parent, childIndex, scanner):
        if parent == None:
            print("Enter root's data:") # Prompt for root's data
        else:
            print("Enter data for child " + str(childIndex + 1) + " of " + parent.data + ":") # Prompt for child's data
        node = Node(scanner.nextInt()) # Read the data for the node
        print("Enter the number of children for " + str(node.data) + ":") # Prompt for number of children
        numChildren = scanner.nextInt()
        for i in range(numChildren):
            child = self.createTree(node, i, scanner) # Recursively create each child
            node.child.append(child) # Add the child to the list of children
        return node

    # Method to display the tree structure
    def display(self):
        self.displayTree(self.root) # Start displaying from the root

    # Recursive method to display the tree structure
    def displayTree(self, node):
        print(node.data, "=>", end=" ") # Print the current node's data
        for child in node.child:
            print(child.data, end=" ") # Print each child's data
        print(".") # End of the current node's children
        for child in node.child:
            self.displayTree(child) # Recursively display each child's subtree

    # Method to calculate the size of the tree
    def size(self):
        return self.sizeHelper(self.root) # Start size calculation from the root

    # Recursive method to calculate the size of the tree
    def sizeHelper(self, node):
        size = 0
        for child in node.child:
            size += self.sizeHelper(child) # Sum the size of all children and their subtrees
        return size + 1 # Add the current node

    # Method to find the maximum value in the tree
    def max(self):
        return self.maxHelper(self.root) # Start max calculation from the root

    # Recursive method to find the maximum value in the tree
    def maxHelper(self, node):
        max = node.data # Initialize max with the current node's data
        for child in node.child:
            max = max if max > self.maxHelper(child) else self.maxHelper(child) # Compare with each child's max and update max
        return max

    # Method to calculate the height of the tree
    def height(self):
        return self.heightHelper(self.root) - 1 # Start height calculation from the root and subtract 1 for zero-based indexing

    # Recursive method to calculate the height of the tree
    def heightHelper(self, node):
        height = 0
        for child in node.child:
            height = max(height, self.heightHelper(child)) # Find the max height among all children
        return height + 1 # Add the current level

    # Method to check if a value exists in the tree
    def find(self, value):
        return self.findHelper(self.root, value) # Start search from the root

    # Recursive method to search for a value in the tree
    def findHelper(self, node, value):
        if node.data == value:
            return True # If the current node's data matches the value, return true
        for child in node.child:
            if self.findHelper(child, value):
                return True # If the value is found in any child, return true
        return False # If the value is not found, return false

    # Method to perform level order traversal of the tree
    def levelOrder(self):
        queue = LinkedList()
        queue.add(self.root) # Add the root to the queue
        while not queue.isEmpty():
            current = queue.poll() # Remove the current node from the queue
            print(current.data, end=" ") # Print the current node's data
            queue.addAll(current.child) # Add all children to the queue
        print() # End of the level order traversal

# Main method to run the program
if __name__ == "__main__":
    scn = Scanner(System.in)
    tree = Main(scn)
    print("\nTree Display:")
    tree.display()
    print("\nSize of the tree: " + str(tree.size()))
    print("Maximum value in the tree: " + str(tree.max()))
    print("Height of the tree: " + str(tree.height()))
    print("\nEnter a value to search:")
    searchValue = scn.nextInt()
    print("Is value present: " + str(tree.find(searchValue)))
    print("\nLevel Order Traversal:")
    tree.levelOrder()


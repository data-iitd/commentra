
import math

# Define the Node class which represents a node in the tree
class Node:
    def __init__(self, data=None, child=None):
        self.data = data
        self.child = child

# Root node of the tree
root = None

# Constructor to build the tree using user input
def createTree(parent, childIndex, scanner):
    global root
    if parent is None:
        print("Enter root's data:") # Prompt for root's data
    else:
        print("Enter data for child " + str(childIndex + 1) + " of " + str(parent.data) + ":") # Prompt for child's data
    node = Node()
    node.data = int(scanner.next()) # Read the data for the node
    print("Enter the number of children for " + str(node.data) + ":") # Prompt for number of children
    numChildren = int(scanner.next())
    for i in range(numChildren):
        child = createTree(node, i, scanner) # Recursively create each child
        node.child.append(child) # Add the child to the list of children
    if parent is None:
        root = node # Set the root node
    return node

# Method to display the tree structure
def displayTree(node):
    print(node.data + " => ", end="") # Print the current node's data
    for child in node.child:
        print(child.data + " ", end="") # Print each child's data
    print(".") # End of the current node's children
    for child in node.child:
        displayTree(child) # Recursively display each child's subtree

# Method to calculate the size of the tree
def size(node):
    size = 0
    for child in node.child:
        size += size(child) # Sum the size of all children and their subtrees
    return size + 1 # Add the current node

# Method to find the maximum value in the tree
def max(node):
    max = node.data # Initialize max with the current node's data
    for child in node.child:
        max = max(max, max(child)) # Compare with each child's max and update max
    return max

# Method to calculate the height of the tree
def height(node):
    height = 0
    for child in node.child:
        height = max(height, height(child)) # Find the max height among all children
    return height + 1 # Add the current level

# Method to check if a value exists in the tree
def find(node, value):
    if node.data == value:
        return True # If the current node's data matches the value, return true
    for child in node.child:
        if find(child, value):
            return True # If the value is found in any child, return true
    return False # If the value is not found, return false

# Method to perform level order traversal of the tree
def levelOrder(node):
    queue = []
    queue.append(node) # Add the root to the queue
    while len(queue) > 0:
        current = queue.pop(0) # Remove the current node from the queue
        print(current.data + " ", end="") # Print the current node's data
        queue.extend(current.child) # Add all children to the queue
    print() # End of the level order traversal

# Main method to run the program
def main():
    scanner = input
    createTree(None, 0, scanner) # Create the tree starting with a null parent
    print("\nTree Display:")
    displayTree(root)
    print("\nSize of the tree: " + str(size(root)))
    print("Maximum value in the tree: " + str(max(root)))
    print("Height of the tree: " + str(height(root)))
    print("\nEnter a value to search:")
    searchValue = int(scanner())
    print("Is value present: " + str(find(root, searchValue)))
    print("\nLevel Order Traversal:")
    levelOrder(root)

if __name__ == "__main__":
    main()


import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

class Main:
    # Node class representing each node in the tree
    class Node:
        def __init__(self, data):
            self.data = data
            self.child = []

    def __init__(self, scn):
        self.root = self.createTree(None, 0, scn)

    # Recursive method to create the tree structure
    def createTree(self, parent, childIndex, scanner):
        # Prompt for root data or child data based on the parent node
        if parent == None:
            print("Enter root's data:")
        else:
            print("Enter data for child " + str(childIndex + 1) + " of " + parent.data + ":")

        # Create a new node and set its data
        node = Node(scanner.nextInt())

        # Prompt for the number of children for the current node
        print("Enter the number of children for " + str(node.data) + ":")
        numChildren = scanner.nextInt()

        # Recursively create child nodes
        for i in range(numChildren):
            child = self.createTree(node, i, scanner) # Create child node
            node.child.append(child) # Add child to the current node
        return node

    # Method to display the tree structure
    def display(self):
        self.displayTree(self.root)

    # Recursive method to display each node and its children
    def displayTree(self, node):
        print(node.data, end=" => ") # Print current node's data
        for child in node.child:
            print(child.data, end=" ") # Print each child's data
        print(".") # End of current node's children

        # Recursively display each child node
        for child in node.child:
            self.displayTree(child)

    # Method to calculate the size of the tree
    def size(self):
        return self.sizeHelper(self.root)

    # Recursive helper method to calculate the size of the tree
    def sizeHelper(self, node):
        size = 0
        for child in node.child:
            size += self.sizeHelper(child)
        return size + 1

    # Method to find the maximum value in the tree
    def max(self):
        return self.maxHelper(self.root)

    # Recursive helper method to find the maximum value in the tree
    def maxHelper(self, node):
        max = node.data
        for child in node.child:
            max = max if max > self.maxHelper(child) else self.maxHelper(child)
        return max

    # Method to calculate the height of the tree
    def height(self):
        return self.heightHelper(self.root) - 1

    # Recursive helper method to calculate the height of the tree
    def heightHelper(self, node):
        height = 0
        for child in node.child:
            height = max(height, self.heightHelper(child))
        return height + 1

    # Method to find a specific value in the tree
    def find(self, value):
        return self.findHelper(self.root, value)

    # Recursive helper method to search for a value in the tree
    def findHelper(self, node, value):
        if node.data == value:
            return True
        # Recursively search in each child
        for child in node.child:
            if self.findHelper(child, value):
                return True
        return False

    # Method for level order traversal of the tree
    def levelOrder(self):
        queue = LinkedList()
        queue.add(self.root)
        while not queue.isEmpty():
            current = queue.poll()
            print(current.data, end=" ")
            queue.addAll(current.child)
        print()

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



import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

class Main:
    # Declare a private static final class Node with its properties
    class Node:
        def __init__(self, data):
            self.data = data
            self.child = []

    # Initialize root node
    def __init__(self, scanner):
        self.root = self.createTree(None, 0, scanner)

    # Method to create a tree recursively
    def createTree(self, parent, childIndex, scanner):
        # If parent is null, it means we are creating the root node
        if parent == None:
            print("Enter root's data:")
        else:
            print("Enter data for child " + str(childIndex + 1) + " of " + parent.data + ":")

        node = self.Node(scanner.nextInt())

        # Ask user for number of children for the current node
        print("Enter the number of children for " + str(node.data) + ":")
        numChildren = scanner.nextInt()

        # Create children for the current node
        for i in range(numChildren):
            child = self.createTree(node, i, scanner)
            node.child.append(child)

        return node

    # Method to display the tree in a pre-order traversal manner
    def display(self):
        self.displayTree(self.root)

    # Recursive method to display the tree
    def displayTree(self, node):
        print(node.data, end=" => ")
        for child in node.child:
            print(child.data, end=" ")
        print(".")
        for child in node.child:
            self.displayTree(child)

    # Method to find the size of the tree
    def size(self):
        return self.sizeHelper(self.root)

    # Recursive helper method to find the size of the tree
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

    # Method to find the height of the tree
    def height(self):
        return self.heightHelper(self.root) - 1

    # Recursive helper method to find the height of the tree
    def heightHelper(self, node):
        height = 0
        for child in node.child:
            height = height if height > self.heightHelper(child) else self.heightHelper(child)
        return height + 1

    # Method to check if a value exists in the tree
    def find(self, value):
        return self.findHelper(self.root, value)

    # Recursive helper method to check if a value exists in the tree
    def findHelper(self, node, value):
        if node.data == value:
            return True
        for child in node.child:
            if self.findHelper(child, value):
                return True
        return False

    # Method to perform level order traversal of the tree
    def levelOrder(self):
        queue = LinkedList()
        queue.add(self.root)
        while not queue.isEmpty():
            current = queue.poll()
            print(current.data, end=" ")
            queue.addAll(current.child)
        print()

if __name__ == "__main__":
    scanner = Scanner(System.in)
    tree = Main(scanner)

    # Display tree, size, max, height, and perform search and level order traversal
    print("\nTree Display:")
    tree.display()
    print("\nSize of the tree: " + str(tree.size()))
    print("Maximum value in the tree: " + str(tree.max()))
    print("Height of the tree: " + str(tree.height()))
    print("\nEnter a value to search:")
    searchValue = scanner.nextInt()
    print("Is value present: " + str(tree.find(searchValue)))
    print("\nLevel Order Traversal:")
    tree.levelOrder()


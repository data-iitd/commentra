import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Main:
    # Node class representing each node in the Binary Search Tree (BST)
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

    # Binary Search Tree class
    class BST:
        def __init__(self):
            self.root = None

        # Public method to add data to the BST
        def add(self, data):
            self.root = self.addRecursive(self.root, data)

        # Private recursive method to add data to the BST
        def addRecursive(self, node, data):
            # If the current node is null, create a new node
            if node == None:
                return Node(data)
            # Compare data and decide to go left or right
            if data < node.data:
                node.left = self.addRecursive(node.left, data)
            else:
                node.right = self.addRecursive(node.right, data)
            return node

        # Method to perform in-order traversal of the BST
        def inOrderTraversal(self):
            result = [] # List to hold the traversal result
            self.inOrderTraversal(self.root, result) # Start the traversal from the root
            return result

        # Private recursive method for in-order traversal
        def inOrderTraversal(self, node, result):
            if node!= None:
                self.inOrderTraversal(node.left, result) # Traverse left subtree
                result.append(node.data) # Visit the node
                self.inOrderTraversal(node.right, result) # Traverse right subtree

    # Method to sort an array using BST
    def sort(self, unsortedArray):
        tree = BST() # Create a new BST instance
        for element in unsortedArray:
            tree.add(element) # Add each element to the BST
        return tree.inOrderTraversal() # Return the sorted elements as a list

    # Method to sort a list using BST
    def sort(self, unsortedList):
        tree = BST() # Create a new BST instance
        for element in unsortedList:
            tree.add(element) # Add each element to the BST
        return tree.inOrderTraversal() # Return the sorted elements as a list

    # Main method to execute the program
    def main(self):
        scanner = Scanner(System.in) # Create a scanner for input
        treeSort = Main() # Create an instance of Main
        type = scanner.nextInt() # Read the type of input (1 for array, 2 for list)
        scanner.nextLine() # Consume the newline character
        n = scanner.nextInt() # Read the number of elements
        scanner.nextLine() # Consume the newline character

        # Check if the input type is for an Integer array
        if type == 1:
            array = [0] * n # Create an array to hold integers
            for i in range(n):
                array[i] = scanner.nextInt() # Read integers from input
            array = treeSort.sort(array) # Sort the array using BST
            print("Sorted Array:") # Print sorted array
            for num in array:
                print(num, end=" ") # Print each sorted integer
        # Check if the input type is for a String array
        elif type == 2:
            array = [0] * n # Create an array to hold strings
            for i in range(n):
                array[i] = scanner.nextLine() # Read strings from input
            array = treeSort.sort(array) # Sort the array using BST
            print("Sorted Array:") # Print sorted array
            for str in array:
                print(str, end=" ") # Print each sorted string
        # Handle invalid input type
        else:
            print("Invalid type entered.") # Print error message
        scanner.close() # Close the scanner

# 
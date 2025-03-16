
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Main:
    # Define a static inner class Node for Binary Search Tree
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

    # Define a static inner class BST for Binary Search Tree
    class BST:
        def __init__(self):
            self.root = None

        # Method to add an element to the BST
        def add(self, data):
            self.root = self.addRecursive(self.root, data)

        # Recursive method to add an element to the BST
        def addRecursive(self, node, data):
            if node is None:
                return Node(data)

            # If the data to be added is smaller than the current node,
            # then it should be added to the left subtree
            if data < node.data:
                node.left = self.addRecursive(node.left, data)
            else:
                # Otherwise, it should be added to the right subtree
                node.right = self.addRecursive(node.right, data)
            return node

        # Method to perform in-order traversal of the BST and return a List
        def inOrderTraversal(self):
            result = []
            self.inOrderTraversal(self.root, result)
            return result

        # Recursive method to perform in-order traversal of the BST
        def inOrderTraversal(self, node, result):
            if node is not None:
                # Perform in-order traversal of the left subtree
                self.inOrderTraversal(node.left, result)

                # Add the current node's data to the result List
                result.append(node.data)

                # Perform in-order traversal of the right subtree
                self.inOrderTraversal(node.right, result)

    # Method to sort an Integer array using the BST
    def sort(self, unsortedArray):
        tree = BST()

        # Add all elements of the array to the BST
        for element in unsortedArray:
            tree.add(element)

        # Perform in-order traversal of the BST to get the sorted elements
        sortedList = tree.inOrderTraversal()

        # Return the sorted array
        return sortedList

    # Method to sort a List using the BST
    def sort(self, unsortedList):
        tree = BST()

        # Add all elements of the List to the BST
        for element in unsortedList:
            tree.add(element)

        # Perform in-order traversal of the BST to get the sorted elements
        return tree.inOrderTraversal()

    # Main method to read user input and call the sorting methods
    def main(self):
        scanner = Scanner(System.in)
        treeSort = Main()

        # Read the type of input (Array or List)
        type = scanner.nextInt()
        scanner.nextLine() # Consume the newline character

        # Read the size of the input
        n = scanner.nextInt()
        scanner.nextLine() # Consume the newline character

        # Based on the type of input, create an appropriate data structure
        if type == 1:
            array = [0] * n

            # Read the elements of the array and store them in the Main class's array
            for i in range(n):
                array[i] = scanner.nextInt()

            # Call the sorting method for the array
            array = treeSort.sort(array)

            # Print the sorted array
            print("Sorted Array:")
            for num in array:
                print(num, end=" ")
        elif type == 2:
            array = [0] * n

            # Read the elements of the array and store them in the Main class's array
            for i in range(n):
                array[i] = scanner.nextLine()

            # Call the sorting method for the array
            array = treeSort.sort(array)

            # Print the sorted array
            print("Sorted Array:")
            for str in array:
                print(str, end=" ")
        else:
            # If an invalid type is entered, print an error message
            print("Invalid type entered.")

        # Close the Scanner
        scanner.close()


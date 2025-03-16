import java.util.ArrayList;
import java.util.Scanner;

class Main:
    # Node class representing each element in the heap
    class Node:
        def __init__(self, element):
            self.element = element; # The value of the node
            self.npl = 0; # Null Path Length (NPL) for heap property
            self.left = None; # Left child node
            self.right = None; # Right child node

    def __init__(self):
        self.root = None; # Root node of the heap

    # Method to check if the heap is empty
    def isEmpty(self):
        return self.root == None; # Returns true if root is null

    # Method to clear the heap
    def clear(self):
        self.root = None; # Set root to null to clear the heap

    # Method to merge two heaps
    def merge(self, h1):
        self.root = self.merge(self.root, h1.root); # Merge the current heap with h1
        h1.root = None; # Clear h1 after merging

    # Recursive method to merge two nodes
    def merge(self, a, b):
        # Base cases for merging
        if a == None: return b; # If a is null, return b
        if b == None: return a; # If b is null, return a

        # Ensure that 'a' is the smaller element
        if a.element > b.element:
            temp = a; # Swap a and b
            a = b;
            b = temp;

        # Recursively merge the right child of 'a' with 'b'
        a.right = self.merge(a.right, b);

        # Adjust the left and right children based on NPL
        if a.left == None:
            a.left = a.right; # If left is null, make left point to right
            a.right = None; # Set right to null
        elif a.left.npl < a.right.npl:
            temp = a.left; # Swap left and right if left's NPL is less
            a.left = a.right;
            a.right = temp;

        # Update the NPL of the current node
        a.npl = a.right == None? 0 : a.right.npl + 1;
        return a; # Return the merged node

    # Method to insert a new element into the heap
    def insert(self, a):
        self.root = self.merge(Node(a), self.root); # Merge the new node with the current heap

    # Method to extract the minimum element from the heap
    def extractMin(self):
        if self.isEmpty(): return -1; # Return -1 if the heap is empty
        min = self.root.element; # Store the minimum element
        self.root = self.merge(self.root.left, self.root.right); # Merge left and right children to maintain heap
        return min; # Return the minimum element

    # Method to perform in-order traversal of the heap
    def inOrder(self):
        lst = ArrayList(); # List to store in-order elements
        self.inOrderAux(self.root, lst); # Call auxiliary method for traversal
        return lst; # Return the list of elements

    # Auxiliary method for in-order traversal
    def inOrderAux(self, n, lst):
        if n == None: return; # Base case: if node is null, return
        self.inOrderAux(n.left, lst); # Traverse left subtree
        lst.add(n.element); # Add current node's element to the list
        self.inOrderAux(n.right, lst); # Traverse right subtree

    # Main method to execute the program
    @staticmethod
    def main(args):
        scanner = Scanner(System.in); # Scanner for user input
        heap = Main(); # Create a new heap instance

        # Loop to process user commands
        while scanner.hasNextLine():
            command = scanner.nextLine().trim(); # Read user command
            if command.isEmpty(): break; # Exit loop if command is empty
            parts = command.split(" "); # Split command into parts
            operation = parts[0]; # Get the operation type

            try:
                # Switch case to handle different operations
                if operation == "insert": 
                    value = int(parts[1]); # Parse the value to insert
                    heap.insert(value); # Insert the value into the heap
                    print("Inserted: " + value); # Confirmation message
                elif operation == "extractMin": 
                    min = heap.extractMin(); # Extract the minimum value
                    print(min == -1? "Heap is empty" : "Extracted Min: " + min); # Output result
                elif operation == "inOrder": 
                    inOrderList = heap.inOrder(); # Get in-order traversal
                    print("In-Order: " + inOrderList); # Output the in-order list
                elif operation == "clear": 
                    heap.clear(); # Clear the heap
                    print("Heap cleared"); # Confirmation message
                elif operation == "isEmpty": 
                    print("Is Empty: " + heap.isEmpty()); # Check if heap is empty
                else:
                    print("Unknown operation: " + operation); # Handle unknown commands
            except Exception as e:
                print("Error: " + e.getMessage()); # Handle exceptions
        scanner.close(); # Close the scanner

# 
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Main:
    # Define a constant for in-order traversal strategy
    IN_ORDER = TreeTraversal()

    def __init__(self):
        self.root = None # Root node of the splay tree

    # Check if the tree is empty
    def isEmpty(self):
        return self.root == None

    # Insert a new key into the splay tree
    def insert(self, key):
        self.root = self.insertRec(self.root, key) # Insert the key recursively
        self.root = self.splay(self.root, key) # Splay the tree to bring the inserted key to the root

    # Search for a key in the splay tree
    def search(self, key):
        self.root = self.splay(self.root, key) # Splay the tree to bring the searched key to the root
        return self.root!= None and self.root.key == key # Return true if the key is found

    # Delete a key from the splay tree
    def delete(self, key):
        if self.isEmpty():
            raise EmptyTreeException("Cannot delete from an empty tree") # Handle deletion from an empty tree
        self.root = self.splay(self.root, key) # Splay the tree to bring the key to the root
        if self.root.key!= key:
            return # If the key is not found, do nothing
        # If the node to be deleted has no left child
        if self.root.left == None:
            self.root = self.root.right # Replace root with its right child
        else:
            temp = self.root # Temporarily store the root
            self.root = self.splay(self.root.left, self.findMax(self.root.left).key) # Splay the left subtree and find the max node
            self.root.right = temp.right # Attach the right subtree

    # Traverse the tree using the specified traversal strategy
    def traverse(self, traversal):
        result = [] # List to hold the traversal result
        traversal.traverse(self.root, result) # Perform the traversal
        return result # Return the result list

    # Find the maximum node in a subtree
    def findMax(self, root):
        while root.right!= None:
            root = root.right # Traverse to the rightmost node
        return root # Return the maximum node

    # Perform a right rotation on a subtree
    def rotateRight(self, x):
        y = x.left # Identify the left child
        x.left = y.right # Move the right child of y to be the left child of x
        y.right = x # Perform the rotation
        return y # Return the new root of the subtree

    # Perform a left rotation on a subtree
    def rotateLeft(self, x):
        y = x.right # Identify the right child
        x.right = y.left # Move the left child of y to be the right child of x
        y.left = x # Perform the rotation
        return y # Return the new root of the subtree

    # Splay the tree to bring the specified key to the root
    def splay(self, root, key):
        if root == None or root.key == key:
            return root # Return if root is null or key is found
        if root.key > key:
            if root.left == None:
                return root # If there's no left child, return root
            if root.left.key > key:
                root.left.left = self.splay(root.left.left, key) # Recursively splay the left-left subtree
                root = self.rotateRight(root) # Rotate right
            else:
                root.left.right = self.splay(root.left.right, key) # Recursively splay the left-right subtree
                if root.left.right!= None:
                    root.left = self.rotateLeft(root.left) # Rotate left
            return (root.left == None)? root : self.rotateRight(root) # Final rotation if necessary
        else:
            if root.right == None:
                return root # If there's no right child, return root
            if root.right.key > key:
                root.right.left = self.splay(root.right.left, key) # Recursively splay the right-left subtree
                if root.right.left!= None:
                    root.right = self.rotateRight(root.right) # Rotate right
            else:
                root.right.right = self.splay(root.right.right, key) # Recursively splay the right-right subtree
                root = self.rotateLeft(root) # Rotate left
            return (root.right == None)? root : self.rotateLeft(root) # Final rotation if necessary

    # Recursive method to insert a key into the tree
    def insertRec(self, root, key):
        if root == None:
            return Node(key) # Create a new node if the position is empty
        if key < root.key:
            root.left = self.insertRec(root.left, key) # Insert in the left subtree
        elif key > root.key:
            root.right = self.insertRec(root.right, key) # Insert in the right subtree
        else:
            raise DuplicateKeyException("Duplicate key: " + key) # Handle duplicate keys
        return root # Return the unchanged root

    # Main method to run the program
    @staticmethod
    def main(args):
        scanner = Scanner(System.in) # Create a scanner for user input
        splayTree = Main() # Create an instance of the splay tree
        n = scanner.nextInt() # Read the number of operations
        for i in range(n):
            choice = scanner.nextInt() # Read the operation choice
            if choice == 1: # Insert operation
                valueToInsert = scanner.nextInt() # Read the value to insert
                splayTree.insert(valueToInsert) # Insert the value
                print("Inserted " + valueToInsert) # Confirm insertion
            elif choice == 2: # Delete operation
                valueToDelete = scanner.nextInt() # Read the value to delete
                try:
                    splayTree.delete(valueToDelete) # Attempt to delete the value
                    print("Deleted " + valueToDelete) # Confirm deletion
                except EmptyTreeException as e:
                    print(e.getMessage()) # Handle exception if tree is empty
            elif choice == 3: # Search operation
                valueToSearch = scanner.nextInt() # Read the value to search
                found = splayTree.search(valueToSearch) # Search for the value
                print(found? "Found " + valueToSearch : "Not found") # Print result
            elif choice == 4: # In-order traversal operation
                print("In-order traversal:")
                print(splayTree.traverse(splayTree.IN_ORDER)) # Perform in-order traversal and print result
            else: # Handle invalid operation
                print("Invalid operation.")
        scanner.close() # Close the scanner

class Node:
    def __init__(self, key):
        self.key = key # Initialize the key
        self.left = None # Initialize left child to null
        self.right = None # Initialize right child to null

class EmptyTreeException(Exception):
    def __init__(self, message):
        super(message) # Pass the message to the superclass

class DuplicateKeyException(Exception):
    def __init__(self, message):
        super(message) # Pass the message to the superclass

class TreeTraversal:
    def traverse(self, root, result):
        if root!= None:
            self.traverse(root.left, result) # Traverse left subtree
            result.add(root.key) # Add the root key to the result
            self.traverse(root.right, result) # Traverse right subtree

# 
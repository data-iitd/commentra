import java.util.HashMap;
import java.util.Scanner;
import java.util.Stack;

class BinaryTree:
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

    # Root of the binary tree
    root = None

    # Method to create the binary tree by taking input from the user
    def createTree(self):
        sc = Scanner(System.in)
        self.root = Node(sc.nextInt()) # Create the root node
        self.createTreeRecursive(self.root, sc) # Recursively create the tree

    # Recursive method to create the tree by taking input for each node
    def createTreeRecursive(self, node, sc):
        if node == None: return # Base case for recursion
        leftData = sc.nextInt()
        if leftData!= -1:
            node.left = Node(leftData) # Create left child
            self.createTreeRecursive(node.left, sc) # Recursively create left subtree
        rightData = sc.nextInt()
        if rightData!= -1:
            node.right = Node(rightData) # Create right child
            self.createTreeRecursive(node.right, sc) # Recursively create right subtree

    # Method to check if the binary tree is balanced using recursion
    def isBalancedRecursive(self):
        if self.root == None: return True # An empty tree is balanced
        isBalanced = [True] # Use an array to pass boolean by reference
        self.isBalancedRecursiveHelper(self.root, isBalanced) # Call the helper method
        return isBalanced[0] # Return the balance status

    # Helper method to recursively check the balance of the tree
    def isBalancedRecursiveHelper(self, node, isBalanced):
        if node == None or not isBalanced[0]: return 0 # Base case for recursion
        leftHeight = self.isBalancedRecursiveHelper(node.left, isBalanced) # Get left subtree height
        rightHeight = self.isBalancedRecursiveHelper(node.right, isBalanced) # Get right subtree height
        if Math.abs(leftHeight - rightHeight) > 1: isBalanced[0] = False # Check balance condition
        return Math.max(leftHeight, rightHeight) + 1 # Return the height of the current subtree

    # Method to check if the binary tree is balanced using iteration
    def isBalancedIterative(self):
        if self.root == None: return True # An empty tree is balanced
        isBalanced = True # Initialize the balance status
        stack = Stack() # Use a stack to traverse the tree
        subtreeHeights = HashMap() # Map to store subtree heights
        lastVisited = None # Keep track of the last visited node
        node = self.root # Start from the root
        while not stack.isEmpty() or node!= None:
            if node!= None:
                stack.push(node) # Push the current node onto the stack
                node = node.left # Move to the left child
            else:
                node = stack.peek() # Get the top node from the stack
                if node.right == None or node.right == lastVisited:
                    leftHeight = subtreeHeights.getOrDefault(node.left, 0) # Get left subtree height
                    rightHeight = subtreeHeights.getOrDefault(node.right, 0) # Get right subtree height
                    if Math.abs(leftHeight - rightHeight) > 1: isBalanced = False # Check balance condition
                    subtreeHeights.put(node, Math.max(leftHeight, rightHeight) + 1) # Update the subtree height
                    lastVisited = node # Update the last visited node
                    stack.pop() # Pop the current node from the stack
                    node = None # Set the current node to null to move to the right subtree
                else:
                    node = node.right # Move to the right child
        return isBalanced # Return the balance status

if __name__ == '__main__':
    tree = BinaryTree()
    tree.createTree() # Create the binary tree
    print("Is tree balanced (recursive): " + str(tree.isBalancedRecursive())) # Check balance recursively
    print("Is tree balanced (iterative): " + str(tree.isBalancedIterative())) # Check balance iteratively


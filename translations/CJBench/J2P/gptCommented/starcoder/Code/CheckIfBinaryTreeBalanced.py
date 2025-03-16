import java.util.HashMap;
import java.util.Scanner;
import java.util.Stack;

class BinaryTree:
    # Node class representing each node in the binary tree
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

    def __init__(self):
        self.root = None

    # Method to create a binary tree from user input
    def createTree(self):
        sc = Scanner(System.in)
        self.root = Node(sc.nextInt()) # Create root node
        self.createTreeRecursive(self.root, sc) # Recursively create the tree

    # Recursive helper method to create the tree
    def createTreeRecursive(self, node, sc):
        if node == None: return # Base case: if node is null, return

        # Read left child data and create left subtree
        leftData = sc.nextInt()
        if leftData!= -1: # -1 indicates no child
            node.left = Node(leftData)
            self.createTreeRecursive(node.left, sc) # Recursive call for left child

        # Read right child data and create right subtree
        rightData = sc.nextInt()
        if rightData!= -1: # -1 indicates no child
            node.right = Node(rightData)
            self.createTreeRecursive(node.right, sc) # Recursive call for right child

    # Method to check if the binary tree is balanced using recursion
    def isBalancedRecursive(self):
        if self.root == None: return True # An empty tree is balanced
        isBalanced = [True] # Array to hold balanced status
        self.isBalancedRecursiveHelper(self.root, isBalanced) # Start recursive check
        return isBalanced[0] # Return the balanced status

    # Helper method to calculate height and check balance recursively
    def isBalancedRecursiveHelper(self, node, isBalanced):
        if node == None or not isBalanced[0]: return 0 # Base case

        # Recursively get heights of left and right subtrees
        leftHeight = self.isBalancedRecursiveHelper(node.left, isBalanced)
        rightHeight = self.isBalancedRecursiveHelper(node.right, isBalanced)

        # Check if current node is balanced
        if Math.abs(leftHeight - rightHeight) > 1: isBalanced[0] = False

        # Return height of the current node
        return Math.max(leftHeight, rightHeight) + 1

    # Method to check if the binary tree is balanced using iteration
    def isBalancedIterative(self):
        if self.root == None: return True # An empty tree is balanced

        isBalanced = True # Initialize as balanced
        stack = Stack() # Stack for traversal
        subtreeHeights = HashMap() # Map to store heights
        lastVisited = None # Track the last visited node
        node = self.root # Start from the root

        # Iterative traversal using stack
        while not stack.isEmpty() or node!= None:
            if node!= None:
                stack.push(node) # Push current node to stack
                node = node.left # Move to left child
            else:
                node = stack.peek() # Peek the top node in the stack
                # Check if we can process the current node
                if node.right == None or node.right == lastVisited:
                    # Get heights of left and right subtrees
                    leftHeight = subtreeHeights.getOrDefault(node.left, 0)
                    rightHeight = subtreeHeights.getOrDefault(node.right, 0)
                    # Check if current node is balanced
                    if Math.abs(leftHeight - rightHeight) > 1: isBalanced = False

                    # Store the height of the current node
                    subtreeHeights.put(node, Math.max(leftHeight, rightHeight) + 1)
                    lastVisited = node # Update last visited node
                    stack.pop() # Remove current node from stack
                    node = None # Set node to null to process next node
                else:
                    node = node.right # Move to right child
        return isBalanced # Return the balanced status

if __name__ == '__main__':
    tree = BinaryTree() # Create a new binary tree
    tree.createTree() # Create the tree from user input
    # Check and print if the tree is balanced using recursive method
    print("Is tree balanced (recursive): " + str(tree.isBalancedRecursive()))
    # Check and print if the tree is balanced using iterative method
    print("Is tree balanced (iterative): " + str(tree.isBalancedIterative()))


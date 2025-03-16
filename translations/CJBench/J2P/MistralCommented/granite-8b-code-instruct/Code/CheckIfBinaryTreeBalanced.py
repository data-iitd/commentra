

class BinaryTree:
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None
    
    def __init__(self):
        self.root = None
    
    # Method to create a Binary Tree from user input
    def createTree(self):
        self.root = BinaryTree.Node(int(input())) # Create root node with user input
        self.createTreeRecursive(self.root) # Recursively create left and right subtrees
    
    # Recursive method to create left and right subtrees for a given node
    def createTreeRecursive(self, node):
        if node is None: return # Base case: if node is None, return
        
        leftData = int(input()) # Read left child data from user input
        
        # If left child exists, create a new Node and recursively create its left and right subtrees
        if leftData!= -1:
            node.left = BinaryTree.Node(leftData)
            self.createTreeRecursive(node.left)
        
        rightData = int(input()) # Read right child data from user input
        
        # If right child exists, create a new Node and recursively create its left and right subtrees
        if rightData!= -1:
            node.right = BinaryTree.Node(rightData)
            self.createTreeRecursive(node.right)

# Method to check if a given BinaryTree node is balanced
def isBalanced(root):
    if root is None: return True # Base case: if root is None, return True
    
    # Use a Stack to store nodes and a HashMap to store heights of subtrees
    stack = []
    subtreeHeights = {}
    
    # Initialize two pointers: current node and previous node
    node = root
    lastVisited = None
    
    # Use a while loop to traverse the tree and check balance at each node
    while stack or node:
        if node:
            # Push the current node into the stack and update the previous node
            stack.append(node)
            node = node.left
            
            # If the left child is null or the same as the previous node, check balance and update the flag and heights in HashMap
            if node is None or node == lastVisited:
                leftHeight = subtreeHeights.get(node.left, 0)
                rightHeight = subtreeHeights.get(node.right, 0)
                
                if abs(leftHeight - rightHeight) > 1:
                    return False
                
                subtreeHeights[node] = max(leftHeight, rightHeight) + 1
                lastVisited = node
                
                node = None
        else:
            # Move to the right child
            node = stack.pop().right
    
    # Return the final result
    return True

# Main function to test the isBalanced method
if __name__ == "__main__":
    tree = BinaryTree() # Create a new instance of BinaryTree class
    
    # Call the createTree method to build the tree from user input
    tree.createTree()
    
    # Call the isBalanced method to check if the tree is balanced
    print("Is tree balanced (recursive):", isBalanced(tree.root))
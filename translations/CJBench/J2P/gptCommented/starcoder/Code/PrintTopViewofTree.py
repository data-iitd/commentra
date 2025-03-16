import sys

# Class representing a node in the binary tree
class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

# Class representing an item in the queue for level order traversal
class QItem:
    def __init__(self, node, hd):
        self.node = node
        self.hd = hd

# Class representing the binary tree
class Tree:
    def __init__(self, root):
        self.root = root

    # Method to print the top view of the binary tree
    def printTopView(self):
        # If the tree is empty, return
        if self.root == None:
            return

        # Set to keep track of horizontal distances that have been printed
        set = set()
        # Queue for level order traversal
        queue = []
        # Start with the root node at horizontal distance 0
        queue.append(QItem(self.root, 0))

        # Process nodes in the queue until it's empty
        while len(queue) > 0:
            qi = queue.pop(0) # Get the front item from the queue
            hd = qi.hd # Get the horizontal distance
            n = qi.node # Get the tree node

            # If this horizontal distance has not been printed yet, print the node's key
            if hd not in set:
                set.add(hd) # Mark this horizontal distance as printed
                print(n.key, end=" ") # Print the node's key

            # If there is a left child, add it to the queue with horizontal distance -1
            if n.left!= None:
                queue.append(QItem(n.left, hd - 1))
            # If there is a right child, add it to the queue with horizontal distance +1
            if n.right!= None:
                queue.append(QItem(n.right, hd + 1))

# Main class to execute the program
if __name__ == "__main__":
    # Read the number of nodes
    n = int(input())

    # Map to store nodes by their keys
    nodeMap = {}
    
    # Read each node's key and its children
    for i in range(n):
        key = int(input()) # Read the node key
        left = int(input()) # Read the left child key
        right = int(input()) # Read the right child key
        
        # Create the current node if it does not exist in the map
        if key not in nodeMap:
            nodeMap[key] = TreeNode(key)
        currentNode = nodeMap[key] # Get the current node
        
        # If there is a left child, create it and link it to the current node
        if left!= -1:
            if left not in nodeMap:
                nodeMap[left] = TreeNode(left)
            currentNode.left = nodeMap[left]
        # If there is a right child, create it and link it to the current node
        if right!= -1:
            if right not in nodeMap:
                nodeMap[right] = TreeNode(right)
            currentNode.right = nodeMap[right]

    # Read the key of the root node
    rootKey = int(input())
    # Create the tree with the specified root
    t = Tree(nodeMap[rootKey])

    # Print the top view of the binary tree
    print("Top view of the binary tree:")
    t.printTopView() # Call the method to print the top view

# 
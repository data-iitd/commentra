
import sys
from collections import deque

# Class representing a node in the binary tree
class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

# Class representing the binary tree
class Tree:
    def __init__(self, root):
        self.root = root

    # Method to print the top view of the binary tree
    def printTopView(self):
        # If the tree is empty, return
        if self.root is None:
            return

        # Dictionary to keep track of horizontal distances that have been printed
        hd_dict = {}
        # Queue for level order traversal
        queue = deque()
        # Start with the root node at horizontal distance 0
        queue.append((self.root, 0))

        # Process nodes in the queue until it's empty
        while queue:
            node, hd = queue.popleft() # Get the front item from the queue
            # If this horizontal distance has not been printed yet, print the node's key
            if hd not in hd_dict:
                hd_dict[hd] = node.key
                print(node.key, end=" ") # Print the node's key
            # If there is a left child, add it to the queue with horizontal distance -1
            if node.left is not None:
                queue.append((node.left, hd - 1))
            # If there is a right child, add it to the queue with horizontal distance +1
            if node.right is not None:
                queue.append((node.right, hd + 1))

# Main function to execute the program
def main():
    # Read the number of nodes
    n = int(input())

    # Map to store nodes by their keys
    node_map = {}
    
    # Read each node's key and its children
    for i in range(n):
        key, left, right = map(int, input().split()) # Read the node key and its children
        # Create the current node if it does not exist in the map
        if key not in node_map:
            node_map[key] = TreeNode(key)
        currentNode = node_map[key] # Get the current node
        
        # If there is a left child, create it and link it to the current node
        if left!= -1:
            if left not in node_map:
                node_map[left] = TreeNode(left)
            currentNode.left = node_map[left]
        # If there is a right child, create it and link it to the current node
        if right!= -1:
            if right not in node_map:
                node_map[right] = TreeNode(right)
            currentNode.right = node_map[right]

    # Read the key of the root node
    root_key = int(input())
    # Create the tree with the specified root
    t = Tree(node_map[root_key])

    # Print the top view of the binary tree
    print("Top view of the binary tree:")
    t.printTopView() # Call the method to print the top view

if __name__ == "__main__":
    main()


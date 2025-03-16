
import sys

# Create a TreeNode class with key, left and right references
class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

# Create a QItem class with node and horizontal distance references
class QItem:
    def __init__(self, node, hd):
        self.node = node
        self.hd = hd

# Create a Tree class with root reference
class Tree:
    def __init__(self, root):
        self.root = root

    # Method to print the top view of the binary tree
    def printTopView(self):
        if self.root is None:  # Check if the root is None, if yes then return
            return

        # Create an empty set and queue
        set = set()
        queue = []

        # Add root node to the queue with horizontal distance 0
        queue.append(QItem(self.root, 0))

        # Traverse the tree level by level and print the nodes at the same horizontal distance
        while queue:
            qi = queue.pop(0)  # Dequeue a QItem from the queue
            hd = qi.hd  # Get the horizontal distance of the current node
            n = qi.node  # Get the current node

            # If the node is not already present in the set, print its key and add it to the set
            if hd not in set:
                set.add(hd)
                print(n.key, end=" ")

            # If the left child of the current node is not None, add it to the queue with horizontal distance decreased by 1
            if n.left is not None:
                queue.append(QItem(n.left, hd - 1))

            # If the right child of the current node is not None, add it to the queue with horizontal distance increased by 1
            if n.right is not None:
                queue.append(QItem(n.right, hd + 1))

# Main function to read input and call the printTopView method
def main():
    # Read the number of nodes in the binary tree
    n = int(sys.stdin.readline())

    # Create a dictionary to store TreeNodes with their keys as keys
    nodeMap = {}

    # Read the nodes of the binary tree and create TreeNodes, add them to the dictionary and link them together
    for i in range(n):
        key, left, right = map(int, sys.stdin.readline().split())

        # Create a new TreeNode with the given key and add it to the dictionary with the key as its key
        nodeMap[key] = TreeNode(key)
        currentNode = nodeMap[key]

        # If the left child is not None, create a new TreeNode with the given left key and add it to the dictionary, then link the current node with its left child
        if left != -1:
            nodeMap[left] = TreeNode(left)
            currentNode.left = nodeMap[left]

        # If the right child is not None, create a new TreeNode with the given right key and add it to the dictionary, then link the current node with its right child
        if right != -1:
            nodeMap[right] = TreeNode(right)
            currentNode.right = nodeMap[right]

    # Read the root key and create a Tree object with the root node
    rootKey = int(sys.stdin.readline())
    t = Tree(nodeMap[rootKey])

    # Call the printTopView method of the Tree object to print the top view of the binary tree
    t.printTopView()

# Main function to call the main function
if __name__ == "__main__":
    main()

# END-OF-CODE

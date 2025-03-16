
# Python program to print top view of a binary tree

# A class to represent a node in binary tree
class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

# A class to represent a queue item for level order traversal
class QItem:
    def __init__(self, node, hd):
        self.node = node
        self.hd = hd

# A class to represent the binary tree
class Tree:
    def __init__(self, root):
        self.root = root

    # Method to print the top view of the binary tree
    def printTopView(self):
        # If the tree is empty, return
        if self.root is None:
            return

        # Set to keep track of horizontal distances that have been printed
        set = set()
        # Queue for level order traversal
        queue = []
        # Start with the root node at horizontal distance 0
        queue.append(QItem(self.root, 0))

        # Process nodes in the queue until it's empty
        while queue:
            qi = queue.pop(0) # Get the front item from the queue
            hd = qi.hd # Get the horizontal distance
            n = qi.node # Get the tree node

            # If this horizontal distance has not been printed yet, print the node's key
            if hd not in set:
                set.add(hd) # Mark this horizontal distance as printed
                print(n.key, end=" ") # Print the node's key

            # If there is a left child, add it to the queue with horizontal distance -1
            if n.left is not None:
                queue.append(QItem(n.left, hd - 1))
            # If there is a right child, add it to the queue with horizontal distance +1
            if n.right is not None:
                queue.append(QItem(n.right, hd + 1))

# Driver code to test the above program
if __name__ == "__main__":
    # Let us create the tree shown in the above diagram
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(7)
    root.left.left.left = TreeNode(8)
    root.left.left.right = TreeNode(9)
    root.left.right.left = TreeNode(10)
    root.left.right.right = TreeNode(11)
    root.right.left.left = TreeNode(12)
    root.right.left.right = TreeNode(13)
    root.right.right.left = TreeNode(14)
    root.right.right.right = TreeNode(15)

    # Create the binary tree with the root node and print the top view
    t = Tree(root)
    t.printTopView()


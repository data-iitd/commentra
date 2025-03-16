
import sys

# Class for a tree node
class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

# Class for a queue item. The queue is used to do Level
# order traversal. Every Queue item contains node and horizontal
# distance of node from root
class QItem:
    def __init__(self, node, hd):
        self.node = node
        self.hd = hd

# Class for a Binary Tree
class Tree:
    def __init__(self, root):
        self.root = root

    # This method prints nodes in top view of binary tree
    def printTopView(self):
        # base case
        if self.root is None:
            return

        # Creates an empty hashset
        set = set()

        # Create a queue and add root to it
        queue = []
        queue.append(QItem(self.root, 0))

        # Standard BFS or level order traversal loop
        while len(queue) > 0:
            # Remove the front item and get its details
            qi = queue.pop(0)
            hd = qi.hd
            n = qi.node

            # If this is the first node at its horizontal distance,
            # then this node is in top view
            if hd not in set:
                set.add(hd)
                print(n.key, end=" ")

            # Enqueue left and right children of current node
            if n.left is not None:
                queue.append(QItem(n.left, hd - 1))
            if n.right is not None:
                queue.append(QItem(n.right, hd + 1))

# Driver class to test above methods
if __name__ == "__main__":
    scanner = sys.stdin

    n = int(scanner.readline().strip())
    nodeMap = {}

    for i in range(n):
        key, left, right = list(map(int, scanner.readline().strip().split()))

        nodeMap[key] = TreeNode(key)
        currentNode = nodeMap[key]

        if left != -1:
            nodeMap[left] = TreeNode(left)
            currentNode.left = nodeMap[left]

        if right != -1:
            nodeMap[right] = TreeNode(right)
            currentNode.right = nodeMap[right]

    rootKey = int(scanner.readline().strip())
    t = Tree(nodeMap[rootKey])
    print("Top view of the binary tree:")
    t.printTopView()

    scanner.close()


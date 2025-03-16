
# A class to represent a tree node
class Node:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None


# A class to represent a queue item. The queue is used to do Level
# order traversal. Every Queue item contains node and horizontal
# distance of node from root
class QueueItem:
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
        queue.append(QueueItem(self.root, 0))

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
                print(n.data, end=" ")

            # Enqueue left and right children of current node
            if n.left is not None:
                queue.append(QueueItem(n.left, hd - 1))
            if n.right is not None:
                queue.append(QueueItem(n.right, hd + 1))


# Driver class to test above methods
if __name__ == "__main__":
    import sys

    # Read the tree data from stdin
    n = int(sys.stdin.readline().strip())
    nodeMap = {}

    for i in range(n):
        data = int(sys.stdin.readline().strip())
        left = int(sys.stdin.readline().strip())
        right = int(sys.stdin.readline().strip())

        nodeMap[data] = Node(data)
        currentNode = nodeMap[data]

        if left!= -1:
            nodeMap[left] = Node(left)
            currentNode.left = nodeMap[left]

        if right!= -1:
            nodeMap[right] = Node(right)
            currentNode.right = nodeMap[right]

    root = int(sys.stdin.readline().strip())
    t = Tree(nodeMap[root])
    print("Top view of the binary tree:")
    t.printTopView()


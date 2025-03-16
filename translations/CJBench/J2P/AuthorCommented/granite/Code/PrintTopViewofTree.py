

import sys
from collections import deque

class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class Tree:
    def __init__(self, root):
        self.root = root

    def printTopView(self):
        if self.root is None:
            return

        # Creates an empty hashset
        set = set()

        # Create a queue and add root to it
        queue = deque()
        queue.append((self.root, 0))

        while len(queue) > 0:
            # Remove the front item and get its details
            n = queue.popleft()
            hd = n[1]
            node = n[0]

            # If this is the first node at its horizontal distance,
            # then this node is in top view
            if hd not in set:
                set.add(hd)
                print(node.key, end=" ")

            # Enqueue left and right children of current node
            if node.left is not None:
                queue.append((node.left, hd - 1))
            if node.right is not None:
                queue.append((node.right, hd + 1))

# Driver class to test above methods
if __name__ == "__main__":
    n = int(input())
    nodeMap = {}

    for i in range(n):
        data = list(map(int, input().split()))
        key = data[0]
        left = data[1]
        right = data[2]

        if key not in nodeMap:
            nodeMap[key] = TreeNode(key)
        currentNode = nodeMap[key]

        if left!= -1:
            if left not in nodeMap:
                nodeMap[left] = TreeNode(left)
            currentNode.left = nodeMap[left]

        if right!= -1:
            if right not in nodeMap:
                nodeMap[right] = TreeNode(right)
            currentNode.right = nodeMap[right]

    rootKey = int(input())
    t = Tree(nodeMap[rootKey])
    print("Top view of the binary tree:")
    t.printTopView()


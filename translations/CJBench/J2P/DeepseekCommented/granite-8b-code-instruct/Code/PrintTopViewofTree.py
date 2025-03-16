
import sys
from collections import deque

# Represents a node in a binary tree
class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

# Represents a binary tree
class Tree:
    def __init__(self, root):
        self.root = root

    # Prints the top view of the binary tree
    def printTopView(self):
        if self.root is None:
            return
        set = set()
        queue = deque()
        queue.append((self.root, 0))
        while len(queue) > 0:
            node, hd = queue.popleft()
            if hd not in set:
                set.add(hd)
                print(node.key, end=" ")
            if node.left is not None:
                queue.append((node.left, hd - 1))
            if node.right is not None:
                queue.append((node.right, hd + 1))

# Main class to run the program
if __name__ == "__main__":
    n = int(input())
    nodeMap = {}
    for i in range(n):
        data = list(map(int, input().split()))
        key = data[0]
        left = data[1]
        right = data[2]
        nodeMap[key] = TreeNode(key)
        currentNode = nodeMap[key]
        if left!= -1:
            nodeMap[left] = TreeNode(left)
            currentNode.left = nodeMap[left]
        if right!= -1:
            nodeMap[right] = TreeNode(right)
            currentNode.right = nodeMap[right]
    rootKey = int(input())
    t = Tree(nodeMap[rootKey])
    print("Top view of the binary tree:")
    t.printTopView()


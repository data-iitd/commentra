
import sys
from collections import deque

class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class QItem:
    def __init__(self, node, hd):
        self.node = node
        self.hd = hd

class Tree:
    def __init__(self, root):
        self.root = root

    def printTopView(self):
        if self.root is None:
            return
        set = set()
        queue = deque()
        queue.append(QItem(self.root, 0))
        while queue:
            qi = queue.popleft()
            hd = qi.hd
            n = qi.node
            if hd not in set:
                set.add(hd)
                print(n.key, end=" ")
            if n.left is not None:
                queue.append(QItem(n.left, hd - 1))
            if n.right is not None:
                queue.append(QItem(n.right, hd + 1))

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    nodeMap = {}
    for i in range(n):
        key, left, right = map(int, sys.stdin.readline().strip().split())
        nodeMap[key] = TreeNode(key)
        if left != -1:
            nodeMap[key].left = TreeNode(left)
        if right != -1:
            nodeMap[key].right = TreeNode(right)
    rootKey = int(sys.stdin.readline().strip())
    t = Tree(nodeMap[rootKey])
    print("Top view of the binary tree:")
    t.printTopView()
    # 
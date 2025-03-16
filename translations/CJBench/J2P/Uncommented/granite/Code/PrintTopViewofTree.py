

import sys
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
    def __init__(self, n):
        self.root = n
    def printTopView(self):
        if self.root == None:
            return
        set = set()
        queue = []
        queue.append(QItem(self.root, 0))
        while len(queue) > 0:
            qi = queue.pop(0)
            hd = qi.hd
            n = qi.node
            if hd not in set:
                set.add(hd)
                print(n.key, end = " ")
            if n.left!= None:
                queue.append(QItem(n.left, hd - 1))
            if n.right!= None:
                queue.append(QItem(n.right, hd + 1))
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

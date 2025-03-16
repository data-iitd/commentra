
import sys
import collections

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
        if self.root == None:
            return
        set = set()
        queue = collections.deque()
        queue.append(QItem(self.root, 0))
        while len(queue) > 0:
            qi = queue.popleft()
            hd = qi.hd
            n = qi.node
            if hd not in set:
                set.add(hd)
                print(n.key, end=' ')
            if n.left!= None:
                queue.append(QItem(n.left, hd - 1))
            if n.right!= None:
                queue.append(QItem(n.right, hd + 1))

def main():
    n = int(sys.stdin.readline().strip())
    nodeMap = {}
    for i in range(n):
        key = int(sys.stdin.readline().strip())
        left = int(sys.stdin.readline().strip())
        right = int(sys.stdin.readline().strip())
        nodeMap[key] = TreeNode(key)
        currentNode = nodeMap[key]
        if left!= -1:
            nodeMap[left] = TreeNode(left)
            currentNode.left = nodeMap[left]
        if right!= -1:
            nodeMap[right] = TreeNode(right)
            currentNode.right = nodeMap[right]
    rootKey = int(sys.stdin.readline().strip())
    t = Tree(nodeMap[rootKey])
    print("Top view of the binary tree:")
    t.printTopView()

if __name__ == "__main__":
    main()


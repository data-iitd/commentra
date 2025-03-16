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

        set_hd = set()
        queue = []

        queue.append(QItem(self.root, 0))

        while queue:
            qi = queue.pop(0)
            hd = qi.hd
            n = qi.node

            if hd not in set_hd:
                set_hd.add(hd)
                print(n.key, end=" ")

            if n.left:
                queue.append(QItem(n.left, hd - 1))

            if n.right:
                queue.append(QItem(n.right, hd + 1))

class Main:
    @staticmethod
    def main(args):
        import sys
        input = sys.stdin.read
        data = input().split()

        index = 0
        n = int(data[index])
        index += 1

        nodeMap = {}

        for i in range(n):
            key = int(data[index])
            index += 1
            left = int(data[index])
            index += 1
            right = int(data[index])
            index += 1

            nodeMap[key] = TreeNode(key)
            currentNode = nodeMap[key]

            if left != -1:
                nodeMap[left] = TreeNode(left)
                currentNode.left = nodeMap[left]

            if right != -1:
                nodeMap[right] = TreeNode(right)
                currentNode.right = nodeMap[right]

        rootKey = int(data[index])
        index += 1

        tree = Tree(nodeMap[rootKey])
        tree.printTopView()

Main.main([])

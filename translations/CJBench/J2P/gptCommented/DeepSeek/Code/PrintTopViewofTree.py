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
    def __init__(self, node):
        self.root = node

    def printTopView(self):
        if self.root is None:
            return

        set_ = set()
        queue = []
        queue.append(QItem(self.root, 0))

        while queue:
            qi = queue.pop(0)
            hd = qi.hd
            n = qi.node

            if hd not in set_:
                set_.add(hd)
                print(n.key, end=" ")

            if n.left:
                queue.append(QItem(n.left, hd - 1))
            if n.right:
                queue.append(QItem(n.right, hd + 1))

def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    i = 0
    n = int(data[i])
    i += 1

    nodeMap = {}

    for _ in range(n):
        key = int(data[i])
        i += 1
        left = int(data[i])
        i += 1
        right = int(data[i])
        i += 1

        nodeMap[key] = TreeNode(key)
        currentNode = nodeMap[key]

        if left != -1:
            nodeMap[left] = TreeNode(left)
            currentNode.left = nodeMap[left]
        if right != -1:
            nodeMap[right] = TreeNode(right)
            currentNode.right = nodeMap[right]

    rootKey = int(data[i])
    i += 1

    tree = Tree(nodeMap[rootKey])

    print("Top view of the binary tree:")
    tree.printTopView()

if __name__ == "__main__":
    main()

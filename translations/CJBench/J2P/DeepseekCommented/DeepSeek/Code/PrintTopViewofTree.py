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
        set_ = set()
        queue = []
        queue.append(QItem(self.root, 0))
        while queue:
            qi = queue.pop(0)
            hd = qi.hd
            node = qi.node
            if hd not in set_:
                set_.add(hd)
                print(node.key, end=" ")
            if node.left:
                queue.append(QItem(node.left, hd - 1))
            if node.right:
                queue.append(QItem(node.right, hd + 1))


# Main class to run the program
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    nodeMap = {}
    index = 1
    for i in range(n):
        key = int(data[index])
        left = int(data[index + 1])
        right = int(data[index + 2])
        index += 3
        nodeMap[key] = TreeNode(key)
        currentNode = nodeMap[key]
        if left != -1:
            nodeMap[left] = TreeNode(left)
            currentNode.left = nodeMap[left]
        if right != -1:
            nodeMap[right] = TreeNode(right)
            currentNode.right = nodeMap[right]
    rootKey = int(data[index])
    tree = Tree(nodeMap[rootKey])
    print("Top view of the binary tree:")
    tree.printTopView()

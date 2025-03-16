class TreeNode:
    def __init__(self, data):
        self.data = data
        self.leftNode = None
        self.rightNode = None

    def getData(self):
        return self.data

    def setLeftNode(self, leftNode):
        self.leftNode = leftNode

    def setRightNode(self, rightNode):
        self.rightNode = rightNode

    def getLeftNode(self):
        return self.leftNode

    def getRightNode(self):
        return self.rightNode

    def isLeafNode(self):
        return self.leftNode is None and self.rightNode is None


def preOrderTraversal(root):
    if root is None:
        return

    print(root.getData(), end=" ")
    preOrderTraversal(root.getLeftNode())
    preOrderTraversal(root.getRightNode())


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    nodes = [TreeNode(i) for i in range(n + 1)]

    index = 1
    for i in range(1, n):
        parent = int(data[index])
        child = int(data[index + 1])
        direction = data[index + 2]
        index += 3

        if direction == "L":
            nodes[parent].setLeftNode(nodes[child])
        elif direction == "R":
            nodes[parent].setRightNode(nodes[child])

    preOrderTraversal(nodes[1])


if __name__ == "__main__":
    main()

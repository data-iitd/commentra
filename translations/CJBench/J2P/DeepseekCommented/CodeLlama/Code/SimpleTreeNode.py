import sys

class Main:
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
        return self.leftNode == None and self.rightNode == None

def main():
    scanner = sys.stdin
    n = int(scanner.readline())
    nodes = [None] * (n + 1)
    for i in range(1, n + 1):
        nodes[i] = Main(i)
    for i in range(0, n - 1):
        parent = int(scanner.readline())
        child = int(scanner.readline())
        direction = scanner.readline().strip()
        if direction == "L":
            nodes[parent].setLeftNode(nodes[child])
        else:
            nodes[parent].setRightNode(nodes[child])
    preOrderTraversal(nodes[1])

def preOrderTraversal(root):
    if root == None:
        return
    print(root.getData(), end=" ")
    preOrderTraversal(root.getLeftNode())
    preOrderTraversal(root.getRightNode())

if __name__ == "__main__":
    main()


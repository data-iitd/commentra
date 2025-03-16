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
    n = int(sys.stdin.readline())
    nodes = [Main(i) for i in range(1, n + 1)]
    for i in range(n - 1):
        parent, child, direction = map(int, sys.stdin.readline().split())
        if direction == 1:
            nodes[parent].setLeftNode(nodes[child])
        else:
            nodes[parent].setRightNode(nodes[child])
    preOrderTraversal(nodes[1])

def preOrderTraversal(root):
    if root == None:
        return
    print(root.getData(), end = " ")
    preOrderTraversal(root.getLeftNode())
    preOrderTraversal(root.getRightNode())

if __name__ == "__main__":
    main()


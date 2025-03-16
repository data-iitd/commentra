import sys
class Node:
    def __init__(self, data):
        self.data = data
        self.leftNode = None
        self.rightNode = None
    def isLeafNode(self):
        return self.leftNode == None and self.rightNode == None
    def setLeftNode(self, leftNode):
        self.leftNode = leftNode
    def setRightNode(self, rightNode):
        self.rightNode = rightNode
    def getLeftNode(self):
        return self.leftNode
    def getRightNode(self):
        return self.rightNode
    def getData(self):
        return self.data
def preOrderTraversal(root):
    if root == None:
        return
    print(root.getData(), end=" ")
    preOrderTraversal(root.getLeftNode())
    preOrderTraversal(root.getRightNode())
if __name__ == "__main__":
    n = int(sys.stdin.readline())
    nodes = [None] * (n + 1)
    for i in range(1, n + 1):
        nodes[i] = Node(i)
    for i in range(n - 1):
        parent, child = map(int, sys.stdin.readline().split())
        direction = sys.stdin.readline().strip()
        if direction == "L":
            nodes[parent].setLeftNode(nodes[child])
        else:
            nodes[parent].setRightNode(nodes[child])
    preOrderTraversal(nodes[1])
    # 

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
        return self.leftNode is None and self.rightNode is None

if __name__ == "__main__":
    import sys

    # Input number of nodes
    n = int(input())

    # Create an array of nodes
    nodes = [Main(i) for i in range(1, n + 1)]

    # Input edges
    for i in range(n - 1):
        parent, child, direction = input().split()
        parent, child = int(parent), int(child)

        if direction == "L":
            nodes[parent - 1].setLeftNode(nodes[child - 1])
        else:
            nodes[parent - 1].setRightNode(nodes[child - 1])

    # Perform pre-order traversal and print the tree
    def preOrderTraversal(root):
        if root is None:
            return

        print(root.getData(), end=" ")
        preOrderTraversal(root.getLeftNode())
        preOrderTraversal(root.getRightNode())

    preOrderTraversal(nodes[0])


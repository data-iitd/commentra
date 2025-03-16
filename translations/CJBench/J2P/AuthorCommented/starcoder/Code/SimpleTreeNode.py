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

    def __str__(self):
        return str(self.data)

def main():
    # Input number of nodes
    n = int(sys.stdin.readline())

    # Create an array of nodes
    nodes = [Main(i) for i in range(1, n + 1)]

    # Input edges
    for i in range(n - 1):
        parent = int(sys.stdin.readline())
        child = int(sys.stdin.readline())
        direction = sys.stdin.readline()

        if direction.strip() == "L":
            nodes[parent - 1].setLeftNode(nodes[child - 1])
        else:
            nodes[parent - 1].setRightNode(nodes[child - 1])

    # Perform pre-order traversal and print the tree
    preOrderTraversal(nodes[0])

def preOrderTraversal(root):
    if root == None:
        return

    print(root, end=" ")
    preOrderTraversal(root.getLeftNode())
    preOrderTraversal(root.getRightNode())

if __name__ == "__main__":
    main()


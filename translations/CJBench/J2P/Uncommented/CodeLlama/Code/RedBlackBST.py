
class Node:
    def __init__(self, key):
        self.key = key
        self.color = 1
        self.left = None
        self.right = None
        self.p = None

class RBTree:
    def __init__(self):
        self.nil = Node(-1)
        self.root = self.nil

    def printTree(self, node):
        if node == self.nil:
            return
        self.printTree(node.left)
        print((("R " if node.color == 0 else "B ") + str(node.key) + " "))
        self.printTree(node.right)

    def insert(self, key):
        node = Node(key)
        temp = self.root
        if self.root == self.nil:
            self.root = node
            node.color = 0
        else:
            node.color = 1
            while True:
                if key < temp.key:
                    if temp.left == self.nil:
                        temp.left = node
                        node.p = temp
                        break
                    temp = temp.left
                else:
                    if temp.right == self.nil:
                        temp.right = node
                        node.p = temp
                        break
                    temp = temp.right
            self.fixTree(node)

    def fixTree(self, node):
        while node.p.color == 0:
            if node.p == node.p.p.left:
                y = node.p.p.right
                if y.color == 0:
                    node.p.color = 1
                    y.color = 1
                    node.p.p.color = 0
                    node = node.p.p
                else:
                    if node == node.p.right:
                        node = node.p
                        self.rotateLeft(node)
                    node.p.color = 1
                    node.p.p.color = 0
                    self.rotateRight(node.p.p)
            else:
                y = node.p.p.left
                if y.color == 0:
                    node.p.color = 1
                    y.color = 1
                    node.p.p.color = 0
                    node = node.p.p
                else:
                    if node == node.p.left:
                        node = node.p
                        self.rotateRight(node)
                    node.p.color = 1
                    node.p.p.color = 0
                    self.rotateLeft(node.p.p)

    def rotateLeft(self, node):
        temp = node.right
        node.right = temp.left
        if temp.left != self.nil:
            temp.left.p = node
        temp.p = node.p
        if node.p == self.nil:
            self.root = temp
        else:
            if node == node.p.left:
                node.p.left = temp
            else:
                node.p.right = temp
        temp.left = node
        node.p = temp

    def rotateRight(self, node):
        temp = node.left
        node.left = temp.right
        if temp.right != self.nil:
            temp.right.p = node
        temp.p = node.p
        if node.p == self.nil:
            self.root = temp
        else:
            if node == node.p.right:
                node.p.right = temp
            else:
                node.p.left = temp
        temp.right = node
        node.p = temp

    def printInOrder(self):
        self.printTree(self.root)
        print()

if __name__ == "__main__":
    rbTree = RBTree()
    n = int(input())
    for i in range(n):
        key = int(input())
        rbTree.insert(key)
    print("In-order traversal:")
    rbTree.printInOrder()


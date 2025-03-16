

class Node:
    def __init__(self, key):
        self.key = key
        self.color = "BLACK"
        self.left = None
        self.right = None
        self.p = None

class Main:
    def __init__(self):
        self.nil = Node(-1)
        self.root = self.nil

    def printTree(self, node):
        if node == self.nil:
            return
        self.printTree(node.left)
        print(((node.color == "RED")? "R " : "B ") + str(node.key) + " ", end="")
        self.printTree(node.right)

    def insert(self, key):
        node = Node(key)
        temp = self.root
        if self.root == self.nil:
            self.root = node
            node.color = "BLACK"
        else:
            node.color = "RED"
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
        while node.p.color == "RED":
            if node.p == node.p.p.left:
                y = node.p.p.right
                if y.color == "RED":
                    node.p.color = "BLACK"
                    y.color = "BLACK"
                    node.p.p.color = "RED"
                    node = node.p.p
                else:
                    if node == node.p.right:
                        node = node.p
                        self.rotateLeft(node)
                    node.p.color = "BLACK"
                    node.p.p.color = "RED"
                    self.rotateRight(node.p.p)
            else:
                y = node.p.p.left
                if y.color == "RED":
                    node.p.color = "BLACK"
                    y.color = "BLACK"
                    node.p.p.color = "RED"
                    node = node.p.p
                else:
                    if node == node.p.left:
                        node = node.p
                        self.rotateRight(node)
                    node.p.color = "BLACK"
                    node.p.p.color = "RED"
                    self.rotateLeft(node.p.p)
        self.root.color = "BLACK"

    def rotateLeft(self, node):
        temp = node.right
        node.right = temp.left
        if temp.left!= self.nil:
            temp.left.p = node
        temp.p = node.p
        if node.p == self.nil:
            self.root = temp
        elif node == node.p.left:
            node.p.left = temp
        else:
            node.p.right = temp
        temp.left = node
        node.p = temp

    def rotateRight(self, node):
        temp = node.left
        node.left = temp.right
        if temp.right!= self.nil:
            temp.right.p = node
        temp.p = node.p
        if node.p == self.nil:
            self.root = temp
        elif node == node.p.right:
            node.p.right = temp
        else:
            node.p.left = temp
        temp.right = node
        node.p = temp

    def printInOrder(self):
        self.printTree(self.root)
        print()

if __name__ == "__main__":
    import sys
    n = int(input())
    rbTree = Main()
    for i in range(n):
        key = int(input())
        rbTree.insert(key)
    print("In-order traversal:")
    rbTree.printInOrder()

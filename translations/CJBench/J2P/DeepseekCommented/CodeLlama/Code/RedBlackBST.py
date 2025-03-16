
# Importing the Scanner class for input operations
from java.util import Scanner

# Inner class Node representing a node in the Red-Black Tree
class Node:
    def __init__(self, key):
        self.key = key
        self.color = 1 # Color of the node, default is black
        self.left = None
        self.right = None
        self.p = None

# Sentinel node to represent null in the tree
nil = Node(-1)

class Main:
    def __init__(self):
        self.root = nil

    # Method to print the tree in an in-order traversal manner
    def printTree(self, node):
        if node == nil:
            return
        self.printTree(node.left)
        print(((node.color == 0) and "R " or "B ") + str(node.key) + " ")
        self.printTree(node.right)

    # Method to insert a new node into the Red-Black Tree
    def insert(self, key):
        node = Node(key)
        temp = self.root
        if self.root == nil:
            self.root = node
            node.color = 0 # Root is always black
        else:
            node.color = 0 # New node is red
            while True:
                if key < temp.key:
                    if temp.left == nil:
                        temp.left = node
                        node.p = temp
                        break
                    temp = temp.left
                else:
                    if temp.right == nil:
                        temp.right = node
                        node.p = temp
                        break
                    temp = temp.right
            self.fixTree(node)

    # Method to fix the tree after insertion to maintain Red-Black properties
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

    # Method to perform left rotation on a given node
    def rotateLeft(self, node):
        temp = node.right
        node.right = temp.left
        if temp.left != nil:
            temp.left.p = node
        temp.p = node.p
        if node.p == nil:
            self.root = temp
        elif node == node.p.left:
            node.p.left = temp
        else:
            node.p.right = temp
        temp.left = node
        node.p = temp

    # Method to perform right rotation on a given node
    def rotateRight(self, node):
        temp = node.left
        node.left = temp.right
        if temp.right != nil:
            temp.right.p = node
        temp.p = node.p
        if node.p == nil:
            self.root = temp
        elif node == node.p.right:
            node.p.right = temp
        else:
            node.p.left = temp
        temp.right = node
        node.p = temp

    # Method to print the tree in an in-order traversal manner
    def printInOrder(self):
        self.printTree(self.root)
        print()

    # Main method to run the program
    def main(self):
        scanner = Scanner(System.in)
        n = scanner.nextInt()
        for i in range(n):
            key = scanner.nextInt()
            self.insert(key)
        print("In-order traversal:")
        self.printInOrder()
        scanner.close()

Main().main()


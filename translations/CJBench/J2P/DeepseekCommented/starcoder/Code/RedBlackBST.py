# Importing the Scanner class for input operations
import java.util.Scanner;

class Main:
    # Constant for red color
    RED = 0
    # Constant for black color
    BLACK = 1

    # Inner class Node representing a node in the Red-Black Tree
    class Node:
        def __init__(self, key):
            self.key = key
            self.color = BLACK
            self.left = None
            self.right = None
            self.p = None

    # Sentinel node to represent null in the tree
    nil = Node(-1)
    root = nil

    # Method to print the tree in an in-order traversal manner
    def printTree(self, node):
        if node == nil: return
        self.printTree(node.left)
        print(((node.color == RED) and "R " or "B ") + str(node.key) + " ")
        self.printTree(node.right)

    # Method to insert a new node into the Red-Black Tree
    def insert(self, key):
        node = Node(key)
        temp = root
        if root == nil:
            root = node
            node.color = BLACK
        else:
            node.color = RED
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
        while node.p.color == RED:
            if node.p == node.p.p.left:
                y = node.p.p.right
                if y.color == RED:
                    node.p.color = BLACK
                    y.color = BLACK
                    node.p.p.color = RED
                    node = node.p.p
                else:
                    if node == node.p.right:
                        node = node.p
                        self.rotateLeft(node)
                    node.p.color = BLACK
                    node.p.p.color = RED
                    self.rotateRight(node.p.p)
            else:
                y = node.p.p.left
                if y.color == RED:
                    node.p.color = BLACK
                    y.color = BLACK
                    node.p.p.color = RED
                    node = node.p.p
                else:
                    if node == node.p.left:
                        node = node.p
                        self.rotateRight(node)
                    node.p.color = BLACK
                    node.p.p.color = RED
                    self.rotateLeft(node.p.p)
        root.color = BLACK

    # Method to perform left rotation on a given node
    def rotateLeft(self, node):
        temp = node.right
        node.right = temp.left
        if temp.left!= nil: temp.left.p = node
        temp.p = node.p
        if node.p == nil: root = temp
        else if node == node.p.left: node.p.left = temp
        else node.p.right = temp
        temp.left = node
        node.p = temp

    # Method to perform right rotation on a given node
    def rotateRight(self, node):
        temp = node.left
        node.left = temp.right
        if temp.right!= nil: temp.right.p = node
        temp.p = node.p
        if node.p == nil: root = temp
        else if node == node.p.right: node.p.right = temp
        else node.p.left = temp
        temp.right = node
        node.p = temp

    # Method to print the tree in an in-order traversal manner
    def printInOrder(self):
        self.printTree(root)
        print()

    # Main method to run the program
    def main(self):
        scanner = Scanner(System.in)
        rbTree = Main()
        n = scanner.nextInt()
        for i in range(0, n):
            key = scanner.nextInt()
            rbTree.insert(key)
        print("In-order traversal:")
        rbTree.printInOrder()
        scanner.close()

# 

# Constants to represent node colors
RED = 0
BLACK = 1

class Node:
    def __init__(self, key):
        self.key = key
        self.color = BLACK
        self.left = None
        self.right = None
        self.p = None

# Sentinel nil node to represent null nodes
nil = Node(-1)
root = nil

def printTree(node):
    if node == nil: return
    printTree(node.left)
    print(((node.color == RED) and "R " or "B ") + str(node.key) + " ")
    printTree(node.right)

def insert(key):
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
        fixTree(node)

def fixTree(node):
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
                    rotateLeft(node)
                node.p.color = BLACK
                node.p.p.color = RED
                rotateRight(node.p.p)
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
                    rotateRight(node)
                node.p.color = BLACK
                node.p.p.color = RED
                rotateLeft(node.p.p)
    root.color = BLACK

def rotateLeft(node):
    temp = node.right
    node.right = temp.left
    if temp.left!= nil: temp.left.p = node
    temp.p = node.p
    if node.p == nil: root = temp
    else:
        if node == node.p.left: node.p.left = temp
        else: node.p.right = temp
    temp.left = node
    node.p = temp

def rotateRight(node):
    temp = node.left
    node.left = temp.right
    if temp.right!= nil: temp.right.p = node
    temp.p = node.p
    if node.p == nil: root = temp
    else:
        if node == node.p.right: node.p.right = temp
        else: node.p.left = temp
    temp.right = node
    node.p = temp

def printInOrder():
    printTree(root)
    print()

if __name__ == "__main__":
    import sys
    scanner = sys.stdin
    n = int(scanner.readline())
    for i in range(n):
        key = int(scanner.readline())
        insert(key)
    print("In-order traversal:")
    printInOrder()


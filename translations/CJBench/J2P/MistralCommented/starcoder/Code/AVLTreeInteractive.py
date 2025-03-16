
class Node:
    def __init__(self, key, parent):
        self.key = key
        self.parent = parent
        self.left = None
        self.right = None
        self.balance = 0
        self.height = 0

class Main:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root == None:
            self.root = Node(key, None)
        else:
            n = self.root
            parent = n
            while True:
                if n.key == key:
                    return False
                parent = n
                if n.key > key:
                    n = n.left
                else:
                    n = n.right
                if n == None:
                    if parent.key > key:
                        parent.left = Node(key, parent)
                    else:
                        parent.right = Node(key, parent)
                    self.rebalance(parent)
                    break
        return True

    def delete(self, delKey):
        if self.root == None:
            return
        node = self.root
        child = self.root
        while child!= None:
            node = child
            child = delKey >= node.key and node.right or node.left
            if delKey == node.key:
                self.deleteNode(node)
                return
        return

    def deleteNode(self, node):
        if node.left == None and node.right == None:
            if node.parent == None:
                self.root = None
            else:
                parent = node.parent
                if parent.left == node:
                    parent.left = None
                else:
                    parent.right = None
                self.rebalance(parent)
            return
        child = node.left!= None and node.left or node.right
        if node.left!= None:
            child = node.left
        else:
            child = node.right
        if child!= None:
            node.key = child.key
        self.deleteNode(child)
        return

    def search(self, key):
        result = self.searchHelper(self.root, key)
        return result!= None

    def searchHelper(self, root, key):
        if root == None or root.key == key:
            return root
        if key < root.key:
            return self.searchHelper(root.left, key)
        else:
            return self.searchHelper(root.right, key)

    def display(self):
        self.displayHelper(self.root)

    def displayHelper(self, node):
        if node!= None:
            self.displayHelper(node.left)
            print(node.key, end=' ')
            self.displayHelper(node.right)

    def rebalance(self, n):
        self.setBalance(n)
        if n.balance == -2:
            if self.height(n.left.left) >= self.height(n.left.right):
                n = self.rotateRight(n)
            else:
                n = self.rotateLeftThenRight(n)
        elif n.balance == 2:
            if self.height(n.right.right) >= self.height(n.right.left):
                n = self.rotateLeft(n)
            else:
                n = self.rotateRightThenLeft(n)
        if n.parent!= None:
            self.rebalance(n.parent)
        else:
            self.root = n

    def rotateRight(self, a):
        b = a.left
        b.parent = a.parent
        a.left = b.right
        if a.left!= None:
            a.left.parent = a
        b.right = a
        a.parent = b
        self.setBalance(a, b)
        return b

    def rotateLeft(self, a):
        b = a.right
        b.parent = a.parent
        a.right = b.left
        if a.right!= None:
            a.right.parent = a
        b.left = a
        a.parent = b
        self.setBalance(a, b)
        return b

    def rotateLeftThenRight(self, n):
        n.left = self.rotateLeft(n.left)
        return self.rotateRight(n)

    def height(self, node):
        return node == None and -1 or node.height

    def setBalance(self, *nodes):
        for n in nodes:
            self.reheight(n)
            n.balance = self.height(n.right) - self.height(n.left)

    def reheight(self, node):
        if node!= None:
            node.height = 1 + max(self.height(node.left), self.height(node.right))

    # Main method to run the program
    def main(self):
        tree = Main()
        tree.insert(10)
        tree.insert(20)
        tree.insert(30)
        tree.insert(40)
        tree.insert(50)
        tree.insert(25)
        tree.insert(35)
        tree.insert(45)
        tree.insert(55)
        tree.insert(22)
        tree.insert(27)
        tree.insert(32)
        tree.insert(37)
        tree.insert(42)
        tree.insert(47)
        tree.insert(52)
        tree.insert(57)
        tree.display()
        print()
        tree.delete(22)
        tree.delete(27)
        tree.delete(32)
        tree.delete(37)
        tree.delete(42)
        tree.delete(47)
        tree.delete(52)
        tree.delete(57)
        tree.display()
        print()
        print(tree.search(20))
        print(tree.search(25))
        print(tree.search(30))
        print(tree.search(35))
        print(tree.search(40))
        print(tree.search(45))
        print(tree.search(50))
        print(tree.search(55))
        print(tree.search(100))


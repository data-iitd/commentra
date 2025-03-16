

class Node:
    def __init__(self, key, parent=None):
        self.key = key
        self.parent = parent
        self.balance = 0
        self.height = 1
        self.left = None
        self.right = None

class Main:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root is None:
            self.root = Node(key, None)
        else:
            n = self.root
            parent = None
            while True:
                parent = n
                if key < n.key:
                    if n.left is None:
                        n.left = Node(key, parent)
                        self.rebalance(parent)
                        break
                    else:
                        n = n.left
                else:
                    if n.right is None:
                        n.right = Node(key, parent)
                        self.rebalance(parent)
                        break
                    else:
                        n = n.right
            return True

    def delete(self, delKey):
        if self.root is None:
            return
        node = self.root
        child = self.root
        while child is not None:
            node = child
            if delKey >= node.key:
                child = node.right
            else:
                child = node.left
            if delKey == node.key:
                self.deleteNode(node)
                return

    def deleteNode(self, node):
        if node.left is None and node.right is None:
            if node.parent is None:
                self.root = None
            else:
                parent = node.parent
                if parent.left == node:
                    parent.left = None
                else:
                    parent.right = None
                self.rebalance(parent)
            return
        child = None
        if node.left is not None:
            child = node.left
        else:
            child = node.right
        while child.left is not None or child.right is not None:
            if child.left is not None:
                child = child.left
            else:
                child = child.right
        node.key = child.key
        self.deleteNode(child)

    def search(self, key):
        result = self.searchHelper(self.root, key)
        return result is not None

    def searchHelper(self, root, key):
        if root is None or root.key == key:
            return root
        if key < root.key:
            return self.searchHelper(root.left, key)
        else:
            return self.searchHelper(root.right, key)

    def display(self):
        self.displayHelper(self.root)

    def displayHelper(self, node):
        if node is not None:
            self.displayHelper(node.left)
            print(node.key, end=" ")
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
        if n.parent is not None:
            self.rebalance(n.parent)
        else:
            self.root = n

    def rotateRight(self, a):
        b = a.left
        b.parent = a.parent
        a.left = b.right
        if a.left is not None:
            a.left.parent = a
        b.right = a
        a.parent = b
        self.setBalance(a, b)
        return b

    def rotateLeft(self, a):
        b = a.right
        b.parent = a.parent
        a.right = b.left
        if a.right is not None:
            a.right.parent = a
        b.left = a
        a.parent = b
        self.setBalance(a, b)
        return b

    def rotateLeftThenRight(self, n):
        n.left = self.rotateLeft(n.left)
        return self.rotateRight(n)

    def height(self, node):
        return node.height if node is not None else -1

    def setBalance(self, *nodes):
        for n in nodes:
            self.reheight(n)
            n.balance = self.height(n.right) - self.height(n.left)

    def reheight(self, node):
        if node is not None:
            node.height = 1 + max(self.height(node.left), self.height(node.right))

    def main():
        tree = Main()
        # Perform operations on the tree
        #...

if __name__ == "__main__":
    Main.main()


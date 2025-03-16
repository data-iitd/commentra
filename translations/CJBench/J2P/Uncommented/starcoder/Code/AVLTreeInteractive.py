class Node:
    def __init__(self, key, parent):
        self.key = key
        self.parent = parent
        self.left = None
        self.right = None
        self.balance = 0
        self.height = 0

class AVLTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root == None:
            self.root = Node(key, None)
        else:
            n = self.root
            parent = None
            while True:
                if n.key == key:
                    return False
                parent = n
                n = n.left if n.key > key else n.right
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
        child = node.left if node.left!= None else node.right
        while child.right!= None:
            child = child.right
        node.key = child.key
        self.deleteNode(child)

    def search(self, key):
        result = self.searchHelper(self.root, key)
        return result!= None

    def searchHelper(self, root, key):
        if root == None or root.key == key:
            return root
        return key < root.key and self.searchHelper(root.left, key) or self.searchHelper(root.right, key)

    def display(self):
        self.displayHelper(self.root)
        print

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

    def rotateLeftThenRight(self, n):
        n.left = self.rotateLeft(n.left)
        return self.rotateRight(n)

    def rotateRightThenLeft(self, n):
        n.right = self.rotateRight(n.right)
        return self.rotateLeft(n)

    def height(self, n):
        return n == None and -1 or n.height

    def setBalance(self, *nodes):
        for n in nodes:
            self.reheight(n)
            n.balance = self.height(n.right) - self.height(n.left)

    def reheight(self, node):
        if node!= None:
            node.height = 1 + max(self.height(node.left), self.height(node.right))

if __name__ == "__main__":
    tree = AVLTree()
    while True:
        command = input("Enter commands (insert <value>, delete <value>, search <value>, display, exit):")
        if command.lower().strip() == "exit":
            break
        parts = command.split(" ")
        try:
            if parts[0].lower().strip() == "insert":
                valueToInsert = int(parts[1])
                tree.insert(valueToInsert)
                print("Inserted: " + str(valueToInsert))
            elif parts[0].lower().strip() == "delete":
                valueToDelete = int(parts[1])
                tree.delete(valueToDelete)
                print("Deleted: " + str(valueToDelete))
            elif parts[0].lower().strip() == "search":
                valueToSearch = int(parts[1])
                print("Found" if tree.search(valueToSearch) else "Not Found")
            elif parts[0].lower().strip() == "display":
                tree.display()
            else:
                print("Unknown command")
        except Exception as e:
            print("Invalid command or input")


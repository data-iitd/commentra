class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.parent = None

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def treeMinimum(self, x):
        while x.left is not None:
            x = x.left
        return x

    def treeMaximum(self, x):
        while x.right is not None:
            x = x.right
        return x

    def treeSearch(self, u, k):
        if u is None or k == u.key:
            return u
        if k < u.key:
            return self.treeSearch(u.left, k)
        else:
            return self.treeSearch(u.right, k)

    def treeSuccessor(self, x):
        if x.right is not None:
            return self.treeMinimum(x.right)
        y = x.parent
        while y is not None and x == y.right:
            x = y
            y = y.parent
        return y

    def treeDelete(self, z):
        if z.left is None or z.right is None:
            y = z
        else:
            y = self.treeSuccessor(z)
        if y.left is not None:
            x = y.left
        else:
            x = y.right
        if x is not None:
            x.parent = y.parent
        if y.parent is None:
            self.root = x
        elif y == y.parent.left:
            y.parent.left = x
        else:
            y.parent.right = x
        if y != z:
            z.key = y.key

    def insert(self, k):
        z = Node(k)
        y = None
        x = self.root
        while x is not None:
            y = x
            if z.key < x.key:
                x = x.left
            else:
                x = x.right
        z.parent = y
        if y is None:
            self.root = z
        elif z.key < y.key:
            y.left = z
        else:
            y.right = z

    def inorder(self, u):
        if u is None:
            return
        self.inorder(u.left)
        print(u.key, end=' ')
        self.inorder(u.right)

    def preorder(self, u):
        if u is None:
            return
        print(u.key, end=' ')
        self.preorder(u.left)
        self.preorder(u.right)

if __name__ == "__main__":
    n = int(input())
    bst = BinarySearchTree()
    for _ in range(n):
        command = input().strip().split()
        if command[0] == 'f':
            x = int(command[1])
            t = bst.treeSearch(bst.root, x)
            if t is not None:
                print("yes")
            else:
                print("no")
        elif command[0] == 'i':
            x = int(command[1])
            bst.insert(x)
        elif command[0] == 'p':
            bst.inorder(bst.root)
            print()
            bst.preorder(bst.root)
            print()
        elif command[0] == 'd':
            x = int(command[1])
            bst.treeDelete(bst.treeSearch(bst.root, x))

# <END-OF-CODE>

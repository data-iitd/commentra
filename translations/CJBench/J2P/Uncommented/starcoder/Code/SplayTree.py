
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class EmptyTreeException(Exception):
    def __init__(self, message):
        super(EmptyTreeException, self).__init__(message)

class DuplicateKeyException(Exception):
    def __init__(self, message):
        super(DuplicateKeyException, self).__init__(message)

class TreeTraversal:
    def traverse(self, root, result):
        pass

class InOrderTraversal(TreeTraversal):
    def traverse(self, root, result):
        if root!= None:
            self.traverse(root.left, result)
            result.append(root.key)
            self.traverse(root.right, result)

class Main:
    def __init__(self):
        self.root = None
        self.IN_ORDER = InOrderTraversal()

    def isEmpty(self):
        return self.root == None

    def insert(self, key):
        self.root = self.insertRec(self.root, key)
        self.root = self.splay(self.root, key)

    def search(self, key):
        self.root = self.splay(self.root, key)
        return self.root!= None and self.root.key == key

    def delete(self, key):
        if self.isEmpty():
            raise EmptyTreeException("Cannot delete from an empty tree")
        self.root = self.splay(self.root, key)
        if self.root.key!= key:
            return
        if self.root.left == None:
            self.root = self.root.right
        else:
            temp = self.root
            self.root = self.splay(self.root.left, self.findMax(self.root.left).key)
            self.root.right = temp.right

    def traverse(self, traversal):
        result = []
        traversal.traverse(self.root, result)
        return result

    def findMax(self, root):
        while root.right!= None:
            root = root.right
        return root

    def rotateRight(self, x):
        y = x.left
        x.left = y.right
        y.right = x
        return y

    def rotateLeft(self, x):
        y = x.right
        x.right = y.left
        y.left = x
        return y

    def splay(self, root, key):
        if root == None or root.key == key:
            return root
        if root.key > key:
            if root.left == None:
                return root
            if root.left.key > key:
                root.left.left = self.splay(root.left.left, key)
                root = self.rotateRight(root)
            else:
                root.left.right = self.splay(root.left.right, key)
                if root.left.right!= None:
                    root.left = self.rotateLeft(root.left)
            return (root.left == None) and root or self.rotateRight(root)
        else:
            if root.right == None:
                return root
            if root.right.key > key:
                root.right.left = self.splay(root.right.left, key)
                if root.right.left!= None:
                    root.right = self.rotateRight(root.right)
            else:
                root.right.right = self.splay(root.right.right, key)
                root = self.rotateLeft(root)
            return (root.right == None) and root or self.rotateLeft(root)

    def insertRec(self, root, key):
        if root == None:
            return Node(key)
        if key < root.key:
            root.left = self.insertRec(root.left, key)
        elif key > root.key:
            root.right = self.insertRec(root.right, key)
        else:
            raise DuplicateKeyException("Duplicate key: " + str(key))
        return root

if __name__ == "__main__":
    import sys
    scanner = sys.stdin
    splayTree = Main()
    n = int(scanner.readline())
    for i in range(n):
        choice = int(scanner.readline())
        if choice == 1:
            valueToInsert = int(scanner.readline())
            splayTree.insert(valueToInsert)
            print("Inserted " + str(valueToInsert))
        elif choice == 2:
            valueToDelete = int(scanner.readline())
            try:
                splayTree.delete(valueToDelete)
                print("Deleted " + str(valueToDelete))
            except EmptyTreeException as e:
                print(e.message)
        elif choice == 3:
            valueToSearch = int(scanner.readline())
            found = splayTree.search(valueToSearch)
            print(found and "Found " + str(valueToSearch) or "Not found")
        elif choice == 4:
            print("In-order traversal:")
            print(splayTree.traverse(splayTree.IN_ORDER))
        else:
            print("Invalid operation.")


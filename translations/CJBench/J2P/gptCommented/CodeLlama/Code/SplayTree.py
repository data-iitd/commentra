
class EmptyTreeException(Exception):
    def __init__(self, message):
        super().__init__(message)

class DuplicateKeyException(Exception):
    def __init__(self, message):
        super().__init__(message)

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class TreeTraversal:
    def traverse(self, root, result):
        if root is not None:
            self.traverse(root.left, result)
            result.append(root.key)
            self.traverse(root.right, result)

class InOrderTraversal(TreeTraversal):
    def traverse(self, root, result):
        if root is not None:
            self.traverse(root.left, result)
            result.append(root.key)
            self.traverse(root.right, result)

class Main:
    def __init__(self):
        self.root = None

    def isEmpty(self):
        return self.root is None

    def insert(self, key):
        self.root = self.insertRec(self.root, key)
        self.root = self.splay(self.root, key)

    def search(self, key):
        self.root = self.splay(self.root, key)
        return self.root is not None and self.root.key == key

    def delete(self, key):
        if self.isEmpty():
            raise EmptyTreeException("Cannot delete from an empty tree")
        self.root = self.splay(self.root, key)
        if self.root.key != key:
            return
        if self.root.left is None:
            self.root = self.root.right
        else:
            temp = self.root
            self.root = self.splay(self.root.left, self.findMax(self.root.left).key)
            self.root.right = temp.right
        return

    def traverse(self, traversal):
        result = []
        traversal.traverse(self.root, result)
        return result

    def findMax(self, root):
        while root.right is not None:
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
        if root is None or root.key == key:
            return root
        if root.key > key:
            if root.left is None:
                return root
            if root.left.key > key:
                root.left = self.splay(root.left, key)
                root = self.rotateRight(root)
            elif root.left.key < key:
                root.left = self.splay(root.left, key)
                if root.left is not None:
                    root = self.rotateLeft(root)
            return (root.left is None) and root or self.rotateRight(root)
        else:
            if root.right is None:
                return root
            if root.right.key > key:
                root.right = self.splay(root.right, key)
                if root.right is not None:
                    root = self.rotateLeft(root)
            elif root.right.key < key:
                root.right = self.splay(root.right, key)
                root = self.rotateRight(root)
            return (root.right is None) and root or self.rotateLeft(root)

    def insertRec(self, root, key):
        if root is None:
            return Node(key)
        if key < root.key:
            root.left = self.insertRec(root.left, key)
        elif key > root.key:
            root.right = self.insertRec(root.right, key)
        else:
            raise DuplicateKeyException("Duplicate key: " + str(key))
        return root

    def main(self):
        scanner = Scanner(System.in)
        n = scanner.nextInt()
        for i in range(n):
            choice = scanner.nextInt()
            if choice == 1:
                valueToInsert = scanner.nextInt()
                self.insert(valueToInsert)
                print("Inserted " + str(valueToInsert))
            elif choice == 2:
                valueToDelete = scanner.nextInt()
                try:
                    self.delete(valueToDelete)
                    print("Deleted " + str(valueToDelete))
                except EmptyTreeException as e:
                    print(e.getMessage())
            elif choice == 3:
                valueToSearch = scanner.nextInt()
                found = self.search(valueToSearch)
                print(found and "Found " + str(valueToSearch) or "Not found")
            elif choice == 4:
                print("In-order traversal:")
                print(self.traverse(InOrderTraversal()))
            else:
                print("Invalid operation.")
        scanner.close()

if __name__ == "__main__":
    Main().main()


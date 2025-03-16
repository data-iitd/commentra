

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

class Main:
    def __init__(self):
        self.root = None

    def insert(self, key):
        self.root = self.insert_rec(self.root, key)
        self.root = self.splay(self.root, key)

    def search(self, key):
        self.root = self.splay(self.root, key)
        return self.root is not None and self.root.key == key

    def delete(self, key):
        if self.root is None:
            raise EmptyTreeException("Cannot delete from an empty tree")
        self.root = self.splay(self.root, key)
        if self.root.key!= key:
            return
        if self.root.left is None:
            self.root = self.root.right
        else:
            max_node = self.find_max(self.root.left)
            self.root = self.splay(self.root.left, max_node.key)
            self.root.right = self.root.right

    def traverse(self, traversal):
        result = []
        traversal.traverse(self.root, result)
        return result

    def find_max(self, root):
        while root.right is not None:
            root = root.right
        return root

    def rotate_right(self, x):
        y = x.left
        x.left = y.right
        y.right = x
        return y

    def rotate_left(self, x):
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
                root = self.rotate_right(root)
            elif root.left.key < key:
                root.left.right = self.splay(root.left.right, key)
                if root.left.right is not None:
                    root.left = self.rotate_left(root.left)
        else:
            if root.right is None:
                return root
            if root.right.key > key:
                root.right = self.splay(root.right, key)
                root = self.rotate_left(root)
            elif root.right.key < key:
                root.right.left = self.splay(root.right.left, key)
                root = self.rotate_right(root)
        return root if root.left is None else self.rotate_right(root)

    def insert_rec(self, root, key):
        if root is None:
            return Node(key)
        if key < root.key:
            root.left = self.insert_rec(root.left, key)
        elif key > root.key:
            root.right = self.insert_rec(root.right, key)
        else:
            raise DuplicateKeyException("Duplicate key: " + str(key))
        return root

# Main method to read user input and perform tree operations
if __name__ == "__main__":
    import sys
    n = int(input())
    splay_tree = Main()
    for _ in range(n):
        choice = int(input())
        if choice == 1:
            value_to_insert = int(input())
            splay_tree.insert(value_to_insert)
            print("Inserted", value_to_insert)
        elif choice == 2:
            value_to_delete = int(input())
            try:
                splay_tree.delete(value_to_delete)
                print("Deleted", value_to_delete)
            except EmptyTreeException as e:
                print(e)
        elif choice == 3:
            value_to_search = int(input())
            found = splay_tree.search(value_to_search)
            print("Found" if found else "Not found", value_to_search)
        elif choice == 4:
            print("In-order traversal:")
            print(splay_tree.traverse(IN_ORDER_TRAVERSAL))
        else:
            print("Invalid operation.")

# Define a private static class for the Node
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

# Define the TreeTraversal interface
class TreeTraversal:
    def traverse(self, root, result):
        pass

# Implement the InOrderTraversal class that implements the TreeTraversal interface
class InOrderTraversal(TreeTraversal):
    def traverse(self, root, result):
        if root is not None:
            self.traverse(root.left, result)
            result.append(root.key)
            self.traverse(root.right, result)

# Define the IN_ORDER_TRAVERSAL object
IN_ORDER_TRAVERSAL = InOrderTraversal()


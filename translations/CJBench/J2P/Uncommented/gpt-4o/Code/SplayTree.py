class EmptyTreeException(Exception):
    pass

class DuplicateKeyException(Exception):
    pass

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class TreeTraversal:
    def traverse(self, root, result):
        raise NotImplementedError

class InOrderTraversal(TreeTraversal):
    def traverse(self, root, result):
        if root is not None:
            self.traverse(root.left, result)
            result.append(root.key)
            self.traverse(root.right, result)

class SplayTree:
    def __init__(self):
        self.root = None
        self.in_order = InOrderTraversal()

    def is_empty(self):
        return self.root is None

    def insert(self, key):
        self.root = self._insert_rec(self.root, key)
        self.root = self._splay(self.root, key)

    def search(self, key):
        self.root = self._splay(self.root, key)
        return self.root is not None and self.root.key == key

    def delete(self, key):
        if self.is_empty():
            raise EmptyTreeException("Cannot delete from an empty tree")
        self.root = self._splay(self.root, key)
        if self.root.key != key:
            return
        if self.root.left is None:
            self.root = self.root.right
        else:
            temp = self.root
            self.root = self._splay(self.root.left, self._find_max(self.root.left).key)
            self.root.right = temp.right

    def traverse(self, traversal):
        result = []
        traversal.traverse(self.root, result)
        return result

    def _find_max(self, root):
        while root.right is not None:
            root = root.right
        return root

    def _rotate_right(self, x):
        y = x.left
        x.left = y.right
        y.right = x
        return y

    def _rotate_left(self, x):
        y = x.right
        x.right = y.left
        y.left = x
        return y

    def _splay(self, root, key):
        if root is None or root.key == key:
            return root
        if root.key > key:
            if root.left is None:
                return root
            if root.left.key > key:
                root.left.left = self._splay(root.left.left, key)
                root = self._rotate_right(root)
            elif root.left.key < key:
                root.left.right = self._splay(root.left.right, key)
                if root.left.right is not None:
                    root.left = self._rotate_left(root.left)
            return root.left is None and root or self._rotate_right(root)
        else:
            if root.right is None:
                return root
            if root.right.key > key:
                root.right.left = self._splay(root.right.left, key)
                if root.right.left is not None:
                    root.right = self._rotate_right(root.right)
            elif root.right.key < key:
                root.right.right = self._splay(root.right.right, key)
                root = self._rotate_left(root)
            return root.right is None and root or self._rotate_left(root)

    def _insert_rec(self, root, key):
        if root is None:
            return Node(key)
        if key < root.key:
            root.left = self._insert_rec(root.left, key)
        elif key > root.key:
            root.right = self._insert_rec(root.right, key)
        else:
            raise DuplicateKeyException(f"Duplicate key: {key}")
        return root

def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    splay_tree = SplayTree()
    n = int(data[0])
    
    for i in range(1, n + 1):
        choice = int(data[i].split()[0])
        if choice == 1:
            value_to_insert = int(data[i].split()[1])
            splay_tree.insert(value_to_insert)
            print(f"Inserted {value_to_insert}")
        elif choice == 2:
            value_to_delete = int(data[i].split()[1])
            try:
                splay_tree.delete(value_to_delete)
                print(f"Deleted {value_to_delete}")
            except EmptyTreeException as e:
                print(e)
        elif choice == 3:
            value_to_search = int(data[i].split()[1])
            found = splay_tree.search(value_to_search)
            print(f"Found {value_to_search}" if found else "Not found")
        elif choice == 4:
            print("In-order traversal:")
            print(splay_tree.traverse(splay_tree.in_order))
        else:
            print("Invalid operation.")

if __name__ == "__main__":
    main()

# <END-OF-CODE>


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
    # Define a constant for in-order traversal
    IN_ORDER = InOrderTraversal()

    # The root node of the tree
    def __init__(self):
        self.root = None

    # Check if the tree is empty
    def is_empty(self):
        return self.root is None

    # Insert a new key into the tree
    def insert(self, key):
        self.root = self.insert_rec(self.root, key)
        self.root = self.splay(self.root, key)  # Splay the tree to place the new node at the root

    # Search for a key in the tree
    def search(self, key):
        self.root = self.splay(self.root, key)  # Splay the tree to bring the searched key to the root
        return self.root is not None and self.root.key == key

    # Delete a key from the tree
    def delete(self, key):
        if self.is_empty():
            raise EmptyTreeException("Cannot delete from an empty tree")
        self.root = self.splay(self.root, key)  # Splay the tree to bring the key to the root
        if self.root.key!= key:
            return  # Key not found, do nothing
        if self.root.left is None:
            self.root = self.root.right  # If no left child, replace root with right child
        else:
            temp = self.root
            self.root = self.splay(self.root.left, self.find_max(self.root.left).key)  # Splay the left subtree to find max and make it new root
            self.root.right = temp.right  # Attach the right subtree of the original root to the new root

    # Traverse the tree in a specified order
    def traverse(self, traversal):
        result = []
        traversal.traverse(self.root, result)
        return result

    # Helper method to find the node with the maximum key in the tree
    def find_max(self, root):
        while root.right is not None:
            root = root.right
        return root

    # Helper method to perform a right rotation
    def rotate_right(self, x):
        y = x.left
        x.left = y.right
        y.right = x
        return y

    # Helper method to perform a left rotation
    def rotate_left(self, x):
        y = x.right
        x.right = y.left
        y.left = x
        return y

    # Splay the tree to bring a key to the root
    def splay(self, root, key):
        if root is None or root.key == key:
            return root
        if root.key > key:
            if root.left is None:
                return root
            if root.left.key > key:
                root.left.left = self.splay(root.left.left, key)  # Double rotation needed
                root = self.rotate_right(root)
            elif root.left.key < key:
                root.left.right = self.splay(root.left.right, key)  # Double rotation needed
                if root.left.right is not None:
                    root.left = self.rotate_left(root.left)
            return (root.left is None) and root or self.rotate_right(root)
        else:
            if root.right is None:
                return root
            if root.right.key > key:
                root.right.left = self.splay(root.right.left, key)  # Double rotation needed
                if root.right.left is not None:
                    root.right = self.rotate_right(root.right)
            elif root.right.key < key:
                root.right.right = self.splay(root.right.right, key)  # Double rotation needed
                root = self.rotate_left(root)
            return (root.right is None) and root or self.rotate_left(root)

    # Recursive method to insert a new key into the tree
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

    # Main method to run the application
    @staticmethod
    def main():
        import sys
        n = int(input())
        splay_tree = Main()
        for i in range(n):
            choice = int(input())
            if choice == 1:
                value_to_insert = int(input())
                splay_tree.insert(value_to_insert)
                print("Inserted " + str(value_to_insert))
            elif choice == 2:
                value_to_delete = int(input())
                try:
                    splay_tree.delete(value_to_delete)
                    print("Deleted " + str(value_to_delete))
                except EmptyTreeException as e:
                    print(e)
            elif choice == 3:
                value_to_search = int(input())
                found = splay_tree.search(value_to_search)
                print("Found" if found else "Not found")
            elif choice == 4:
                print("In-order traversal:")
                print(splay_tree.traverse(Main.IN_ORDER))
            else:
                print("Invalid operation.")

    # Inner class representing a node in the tree
    class Node:
        def __init__(self, key):
            self.key = key
            self.left = None
            self.right = None

# Call the main method to run the application
Main.main()

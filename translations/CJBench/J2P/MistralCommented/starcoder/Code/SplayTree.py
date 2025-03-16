
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class Main:
    # Declare a constant for the In-Order tree traversal
    IN_ORDER = TreeTraversal()

    # Initialize the root node to null
    def __init__(self):
        self.root = None

    # Check if the tree is empty
    def isEmpty(self):
        return self.root == None

    # Insert a new node into the tree
    def insert(self, key):
        self.root = self.insertRec(self.root, key) # Recursively insert the new node
        self.root = self.splay(self.root, key) # Splay the tree to maintain balance

    # Search for a node with the given key
    def search(self, key):
        self.root = self.splay(self.root, key) # Splay the tree to bring the searched node to the root
        return self.root!= None and self.root.key == key

    # Delete a node with the given key
    def delete(self, key):
        if self.isEmpty():
            raise EmptyTreeException("Cannot delete from an empty tree")
        self.root = self.splay(self.root, key) # Splay the tree to bring the node to be deleted to the root

        # Check if the root node matches the key
        if self.root.key!= key:
            return

        # If the root node has no children, simply set the root to null
        if self.root.left == None:
            self.root = self.root.right
        else:
            # If the root node has a left child, find the maximum value in the left subtree
            temp = self.root
            self.root = self.splay(self.root.left, self.findMax(self.root.left).key)

            # Replace the root's right pointer with the deleted node's right pointer
            self.root.right = temp.right

    # Traverse the tree using a given traversal method
    def traverse(self, traversal):
        result = []
        traversal.traverse(self.root, result) # Traverse the tree recursively
        return result

    # Find the node with the maximum key in the left subtree
    def findMax(self, root):
        while root.right!= None:
            root = root.right
        return root

    # Rotate the tree right around the given node
    def rotateRight(self, x):
        y = x.left
        x.left = y.right
        y.right = x
        return y

    # Rotate the tree left around the given node
    def rotateLeft(self, x):
        y = x.right
        x.right = y.left
        y.left = x
        return y

    # Splay the tree to bring the node with the given key to the root
    def splay(self, root, key):
        if root == None or root.key == key:
            return root

        # Determine which subtree the node to be splayed is in
        if root.key > key:
            if root.left == None:
                return root

            # Perform left rotations until the node to be splayed is in the left subtree
            if root.left.key > key:
                root.left = self.splay(root.left, key)
                root = self.rotateRight(root)
            elif root.left.key < key:
                root.left.right = self.splay(root.left.right, key)

                # If the right subtree of the left child is not empty, perform a left rotation
                if root.left.right!= None:
                    root.left = self.rotateLeft(root.left)
            return (root.left == None) and root or self.rotateRight(root)
        else:
            # Similar logic for the right subtree
            if root.right == None:
                return root

            if root.right.key > key:
                root.right = self.splay(root.right, key)
                root = self.rotateLeft(root)
            elif root.right.key < key:
                root.right.left = self.splay(root.right.left, key)
                root = self.rotateRight(root)
            return (root.right == None) and root or self.rotateLeft(root)

    # Recursively insert a new node into the tree
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

# Main method to read user input and perform tree operations
if __name__ == "__main__":
    import sys
    import math
    scanner = sys.stdin
    splayTree = Main()
    n = int(scanner.readline())

    # Initialize the splay tree object
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


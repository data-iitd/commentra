
# Define a constant for in-order traversal
IN_ORDER = TreeTraversal()

# The root node of the tree
root = None

# Check if the tree is empty
def isEmpty():
    return root == None

# Insert a new key into the tree
def insert(key):
    global root
    root = insertRec(root, key)
    root = splay(root, key) # Splay the tree to place the new node at the root

# Search for a key in the tree
def search(key):
    global root
    root = splay(root, key) # Splay the tree to bring the searched key to the root
    return root!= None and root.key == key

# Delete a key from the tree
def delete(key):
    if isEmpty():
        raise EmptyTreeException("Cannot delete from an empty tree")
    global root
    root = splay(root, key) # Splay the tree to bring the key to the root
    if root.key!= key:
        return # Key not found, do nothing
    if root.left == None:
        root = root.right # If no left child, replace root with right child
    else:
        temp = root
        root = splay(root.left, findMax(root.left).key) # Splay the left subtree to find max and make it new root
        root.right = temp.right # Attach the right subtree of the original root to the new root

# Traverse the tree in a specified order
def traverse(traversal):
    result = []
    traversal.traverse(root, result)
    return result

# Helper method to find the node with the maximum key in the tree
def findMax(root):
    while root.right!= None:
        root = root.right
    return root

# Helper method to perform a right rotation
def rotateRight(x):
    y = x.left
    x.left = y.right
    y.right = x
    return y

# Helper method to perform a left rotation
def rotateLeft(x):
    y = x.right
    x.right = y.left
    y.left = x
    return y

# Splay the tree to bring a key to the root
def splay(root, key):
    if root == None or root.key == key:
        return root
    if root.key > key:
        if root.left == None:
            return root
        if root.left.key > key:
            root.left.left = splay(root.left.left, key) # Double rotation needed
            root = rotateRight(root)
        else:
            root.left.right = splay(root.left.right, key) # Double rotation needed
            if root.left.right!= None:
                root.left = rotateLeft(root.left)
        return (root.left == None)? root : rotateRight(root)
    else:
        if root.right == None:
            return root
        if root.right.key > key:
            root.right.left = splay(root.right.left, key) # Double rotation needed
            if root.right.left!= None:
                root.right = rotateRight(root.right)
        else:
            root.right.right = splay(root.right.right, key) # Double rotation needed
            root = rotateLeft(root)
        return (root.right == None)? root : rotateLeft(root)

# Recursive method to insert a new key into the tree
def insertRec(root, key):
    if root == None:
        return Node(key)
    if key < root.key:
        root.left = insertRec(root.left, key)
    elif key > root.key:
        root.right = insertRec(root.right, key)
    else:
        raise DuplicateKeyException("Duplicate key: " + str(key))
    return root

# Main method to run the application
def main():
    scanner = Scanner(System.in)
    splayTree = Main()
    n = scanner.nextInt()
    for i in range(n):
        choice = scanner.nextInt()
        if choice == 1:
            valueToInsert = scanner.nextInt()
            splayTree.insert(valueToInsert)
            print("Inserted " + str(valueToInsert))
        elif choice == 2:
            valueToDelete = scanner.nextInt()
            try:
                splayTree.delete(valueToDelete)
                print("Deleted " + str(valueToDelete))
            except EmptyTreeException as e:
                print(e.getMessage())
        elif choice == 3:
            valueToSearch = scanner.nextInt()
            found = splayTree.search(valueToSearch)
            print(found? "Found " + str(valueToSearch) : "Not found")
        elif choice == 4:
            print("In-order traversal:")
            print(splayTree.traverse(IN_ORDER))
        else:
            print("Invalid operation.")
    scanner.close()

# Inner class representing a node in the tree
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

# Custom exception for empty tree
class EmptyTreeException(Exception):
    def __init__(self, message):
        super(EmptyTreeException, self).__init__(message)

# Custom exception for duplicate keys
class DuplicateKeyException(Exception):
    def __init__(self, message):
        super(DuplicateKeyException, self).__init__(message)

# Interface for tree traversal
class TreeTraversal:
    def traverse(self, root, result):
        if root!= None:
            self.traverse(root.left, result)
            result.append(root.key)
            self.traverse(root.right, result)

# Concrete implementation of in-order traversal
class InOrderTraversal(TreeTraversal):
    def traverse(self, root, result):
        if root!= None:
            self.traverse(root.left, result)
            result.append(root.key)
            self.traverse(root.right, result)

if __name__ == "__main__":
    main()


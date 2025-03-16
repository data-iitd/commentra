
class Node: # Inner class representing a node in the AVL tree
    def __init__(self, key, parent):
        self.key = key
        self.parent = parent
        self.balance = 0
        self.height = 1
        self.left = None
        self.right = None

class AVLTree: # AVL tree class
    def __init__(self):
        self.root = None

    def insert(self, key): # Inserts a new key into the AVL tree
        if self.root is None: # If the tree is empty, create a new root node
            self.root = Node(key, None)
        else: # Otherwise, traverse the tree to find the correct position
            n = self.root
            parent = None
            while True:
                parent = n
                if key < n.key: # Determine whether to go left or right
                    n = n.left
                    if n is None: # If the correct position is found, insert the new node
                        parent.left = Node(key, parent)
                        self.rebalance(parent) # Rebalance the tree if necessary
                        break
                else:
                    n = n.right
                    if n is None: # If the correct position is found, insert the new node
                        parent.right = Node(key, parent)
                        self.rebalance(parent) # Rebalance the tree if necessary
                        break

    def delete(self, delKey): # Deletes a node with the specified key from the AVL tree
        if self.root is None: # If the tree is empty, return
            return
        node = self.root
        child = self.root
        while child is not None: # Traverse the tree to find the node to delete
            node = child
            child = delKey if delKey >= node.key else node.right
            if delKey == node.key: # If the node is found, delete it
                self.deleteNode(node)
                return

    def deleteNode(self, node): # Deletes the specified node from the AVL tree
        if node.left is None and node.right is None: # Case 1: node has no children
            if node.parent is None: # If the node is the root, set the root to null
                self.root = None
            else: # Otherwise, set the parent's child to null
                parent = node.parent
                if parent.left == node:
                    parent.left = None
                else:
                    parent.right = None
                self.rebalance(parent) # Rebalance the tree if necessary
            return
        child = node.left if node.left is not None else node.right
        while child.right is not None: # Find the rightmost child of the left subtree
            child = child.right
        node.key = child.key # Replace the node's key with the child's key
        self.deleteNode(child) # Delete the child node

    def search(self, key): # Searches for a node with the specified key in the AVL tree
        result = self.searchHelper(self.root, key)
        return result is not None # Return true if the node is found, otherwise false

    def searchHelper(self, root, key): # Helper method for searching
        if root is None or root.key == key: # If the root is null or the key matches, return the root
            return root
        return self.searchHelper(root.left, key) if key < root.key else self.searchHelper(root.right, key) # Traverse the tree recursively

    def display(self): # Displays the keys of the nodes in the AVL tree in an in-order traversal
        self.displayHelper(self.root)
        print()

    def displayHelper(self, node): # Helper method for displaying the tree
        if node is not None:
            self.displayHelper(node.left) # Traverse the left subtree
            print(node.key, end=" ") # Print the current node's key
            self.displayHelper(node.right) # Traverse the right subtree

    def rebalance(self, n): # Rebalances the AVL tree after insertion or deletion
        self.setBalance(n)
        if n.balance == -2: # If the balance factor is -2, perform a right rotation or a left-then-right rotation
            if self.height(n.left.left) >= self.height(n.left.right):
                n = self.rotateRight(n)
            else:
                n = self.rotateLeftThenRight(n)
        elif n.balance == 2: # If the balance factor is 2, perform a left rotation or a right-then-left rotation
            if self.height(n.right.right) >= self.height(n.right.left):
                n = self.rotateLeft(n)
            else:
                n = self.rotateRightThenLeft(n)
        if n.parent is not None: # Recursively rebalance the parent node
            self.rebalance(n.parent)
        else: # If the node is the root, set it as the new root
            self.root = n

    def rotateLeft(self, a): # Performs a left rotation
        b = a.right
        b.parent = a.parent
        a.right = b.left
        if a.right is not None:
            a.right.parent = a
        b.left = a
        a.parent = b
        self.setBalance(a, b)
        return b

    def rotateRight(self, a): # Performs a right rotation
        b = a.left
        b.parent = a.parent
        a.left = b.right
        if a.left is not None:
            a.left.parent = a
        b.right = a
        a.parent = b
        self.setBalance(a, b)
        return b

    def rotateLeftThenRight(self, n): # Performs a left-then-right rotation
        n.left = self.rotateLeft(n.left)
        return self.rotateRight(n)

    def rotateRightThenLeft(self, n): # Performs a right-then-left rotation
        n.right = self.rotateRight(n.right)
        return self.rotateLeft(n)

    def height(self, n): # Returns the height of the node
        return n.height if n is not None else -1

    def setBalance(self, *nodes): # Sets the balance factor of the nodes
        for n in nodes:
            self.reheight(n)
            n.balance = self.height(n.right) - self.height(n.left)

    def reheight(self, node): # Sets the height of the node
        if node is not None:
            node.height = 1 + max(self.height(node.left), self.height(node.right))

    if __name__ == "__main__": # Main method to provide a simple command-line interface
        tree = AVLTree()
        while True:
            command = input().strip()
            if command.lower() == "exit":
                break
            parts = command.split(" ")
            try:
                if parts[0].lower() == "insert":
                    valueToInsert = int(parts[1])
                    tree.insert(valueToInsert)
                    print("Inserted:", valueToInsert)
                elif parts[0].lower() == "delete":
                    valueToDelete = int(parts[1])
                    tree.delete(valueToDelete)
                    print("Deleted:", valueToDelete)
                elif parts[0].lower() == "search":
                    valueToSearch = int(parts[1])
                    print("Found" if tree.search(valueToSearch) else "Not Found")
                elif parts[0].lower() == "display":
                    tree.display()
                else:
                    print("Unknown command")
            except Exception as e:
                print("Invalid command or input")


class Node:
    def __init__(self, key):
        self.key = key  # The key value of the node
        self.p = None   # Pointer to the parent node
        self.l = None   # Pointer to the left child node
        self.r = None   # Pointer to the right child node

class AVLTree:
    def __init__(self):
        self.root = None  # Initialize the root pointer
        self.NIL = None   # Initialize the NIL pointer

    def find(self, x, k):
        while x is not self.NIL and k != x.key:  # Search for the node with the given key
            if k < x.key:  # If the key is less than the current node's key
                x = x.l  # Move to the left subtree
            else:
                x = x.r  # Move to the right subtree
        return x  # Return the node if found, otherwise return NIL

    def insert(self, k):
        y = self.NIL
        x = self.root
        z = Node(k)  # Create a new node

        # Traverse down the tree to find the position for the new node
        while x is not self.NIL:
            y = x  # Move y pointer one level up
            if z.key < x.key:  # If the new key is less than the current node's key
                x = x.l  # Move to the left subtree
            else:
                x = x.r  # Move to the right subtree

        # Link the new node to its parent node
        z.p = y

        # Update the left or right child of the parent node
        if y is None:
            self.root = z  # If y is NIL, the new node is the root
        elif z.key < y.key:
            y.l = z
        else:
            y.r = z

    def inorder(self, u):
        if u is None:  # Base case: if the tree is empty, return
            return []
        return self.inorder(u.l) + [u.key] + self.inorder(u.r)  # Inorder traversal

    def preorder(self, u):
        if u is None:  # Base case: if the tree is empty, return
            return []
        return [u.key] + self.preorder(u.l) + self.preorder(u.r)  # Preorder traversal

    def print_tree(self):
        inorder_result = self.inorder(self.root)  # Perform inorder traversal
        preorder_result = self.preorder(self.root)  # Perform preorder traversal
        print(" ".join(map(str, inorder_result)))  # Print inorder result
        print(" ".join(map(str, preorder_result)))  # Print preorder result

def main():
    n = int(input())  # Read the number of commands
    avl_tree = AVLTree()  # Create an instance of AVLTree

    for _ in range(n):  # Iterate through each command
        command = input().strip()  # Read the command string

        if command[0] == 'f':  # If the command is to find a node
            x = int(command[2:])  # Read the key value to search for
            t = avl_tree.find(avl_tree.root, x)  # Find the node with the given key
            if t is None:  # If the node is not found
                print("no")
            else:  # If the node is found
                print("yes")

        elif command[0] == 'i':  # If the command is to insert a new node
            z = int(command[2:])  # Read the key value of the new node
            avl_tree.insert(z)  # Insert the new node into the AVL tree

        else:  # If the command is to print the keys of the AVL tree
            avl_tree.print_tree()  # Print the keys in inorder and preorder traversals

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>

class Node:
    def __init__(self, key):
        self.key = key  # The key value of the node
        self.p = None   # Pointer to the parent node
        self.l = None   # Pointer to the left child node
        self.r = None   # Pointer to the right child node

# Global variables for the root of the tree and a NIL pointer
r = None
NIL = None

# Function to find a node with a given key in the binary search tree
def find(x, k):
    while x is not NIL and k != x.key:
        if k < x.key:
            x = x.l  # Move to the left child if the key is smaller
        else:
            x = x.r  # Move to the right child if the key is larger
    return x  # Return the node with the key or NIL if not found

# Function to insert a new key into the binary search tree
def insert(k):
    global r
    y = NIL  # Parent of the new node
    x = r    # Start from the root

    z = Node(k)  # Create a new node
    z.l = NIL    # Initialize left child to NIL
    z.r = NIL    # Initialize right child to NIL

    # Find the position to insert the new node
    while x is not NIL:
        y = x  # Update the parent of the new node
        if z.key < x.key:
            x = x.l  # Move to the left child if the key is smaller
        else:
            x = x.r  # Move to the right child if the key is larger
    z.p = y  # Set the parent of the new node

    if y is NIL:
        r = z  # If the tree was empty, the new node becomes the root
    elif z.key < y.key:
        y.l = z  # Insert as the left child if the key is smaller
    else:
        y.r = z  # Insert as the right child if the key is larger

# Function to perform an inorder traversal of the tree and print the keys
def inorder(u):
    if u is NIL:
        return  # Base case: if the node is NIL, return
    inorder(u.l)  # Recursively traverse the left subtree
    print(u.key, end=' ')  # Print the key of the current node
    inorder(u.r)  # Recursively traverse the right subtree

# Function to perform a preorder traversal of the tree and print the keys
def preorder(u):
    if u is NIL:
        return  # Base case: if the node is NIL, return
    print(u.key, end=' ')  # Print the key of the current node
    preorder(u.l)  # Recursively traverse the left subtree
    preorder(u.r)  # Recursively traverse the right subtree

# Function to print the tree in both inorder and preorder traversals
def print_tree():
    inorder(r)  # Perform inorder traversal
    print()  # Print a newline
    preorder(r)  # Perform preorder traversal
    print()  # Print a newline

# Main function to execute the program
if __name__ == "__main__":
    n = int(input())  # Read the number of operations
    for _ in range(n):
        command = input().strip()  # Read the command
        if command[0] == 'f':
            x = int(command[2:])  # Read the key to find
            t = find(r, x)  # Find the key in the tree
            if t is NIL:
                print("no")  # Print "no" if not found
            else:
                print("yes")  # Print "yes" if found
        elif command[0] == 'i':
            z = int(command[2:])  # Read the key to insert
            insert(z)  # Insert the key into the tree
        else:
            print_tree()  # Print the tree in both traversals

# <END-OF-CODE>

class Node:
    def __init__(self, key):
        self.key = key  # The key value of the node
        self.p = None   # Pointer to the parent node
        self.l = None   # Pointer to the left child
        self.r = None   # Pointer to the right child

# Global variables for the root of the tree and a sentinel NIL node
r = None
NIL = None

# Function to find a node with a specific key in the binary search tree
def find(x, k):
    while x is not NIL and k != x.key:
        if k < x.key:
            x = x.l  # Move to the left child if the key is smaller
        else:
            x = x.r  # Move to the right child if the key is larger
    return x  # Return the found node or NIL if not found

# Function to insert a new key into the binary search tree
def insert(k):
    global r
    y = NIL  # Parent node of the new node
    x = r    # Start from the root

    # Create a new node
    z = Node(k)

    # Find the appropriate position for the new node
    while x is not NIL:
        y = x  # Keep track of the parent node
        if z.key < x.key:
            x = x.l  # Move to the left child
        else:
            x = x.r  # Move to the right child

    z.p = y  # Set the parent of the new node

    # Insert the new node in the tree
    if y is NIL:
        r = z  # Tree was empty, new node becomes the root
    elif z.key < y.key:
        y.l = z  # Insert as the left child
    else:
        y.r = z  # Insert as the right child

# Function to perform an inorder traversal of the tree
def inorder(u):
    if u is NIL:
        return  # Base case: if the node is NIL, return
    inorder(u.l)  # Traverse the left subtree
    print(u.key, end=' ')  # Visit the current node
    inorder(u.r)  # Traverse the right subtree

# Function to perform a preorder traversal of the tree
def preorder(u):
    if u is NIL:
        return  # Base case: if the node is NIL, return
    print(u.key, end=' ')  # Visit the current node
    preorder(u.l)  # Traverse the left subtree
    preorder(u.r)  # Traverse the right subtree

# Function to print the tree in both inorder and preorder
def print_tree():
    inorder(r)  # Print the inorder traversal
    print()     # New line after inorder
    preorder(r) # Print the preorder traversal
    print()     # New line after preorder

# Main function to drive the program
if __name__ == "__main__":
    n = int(input())  # Read the number of operations to perform
    for _ in range(n):
        command = input().strip()  # Read the command
        if command[0] == 'f':  # If the command is 'find'
            x = int(input())  # Read the key to find
            t = find(r, x)  # Search for the key
            if t is NIL:
                print("no")  # Key not found
            else:
                print("yes")  # Key found
        elif command[0] == 'i':  # If the command is 'insert'
            z = int(input())  # Read the key to insert
            insert(z)  # Insert the key into the tree
        else:  # If the command is 'print'
            print_tree()  # Print the tree

# <END-OF-CODE>

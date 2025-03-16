class Node:
    def __init__(self, key, priority):
        self.key = key            # Key of the node
        self.priority = priority  # Priority of the node
        self.left = None         # Pointer to the left child
        self.right = None        # Pointer to the right child

# Function to find a key in the treap
def find(p, x):
    while p is not None:  # Traverse until a leaf is reached
        if p.key == x:
            return True  # Key found
        elif p.key > x:
            p = p.left  # Move to the left child
        else:
            p = p.right  # Move to the right child
    return False  # Key not found

# Function for inorder traversal of the treap
def inorder(a):
    if a.left is not None:
        inorder(a.left)  # Traverse left subtree
    print(a.key, end=' ')  # Print the current node's key
    if a.right is not None:
        inorder(a.right)  # Traverse right subtree

# Function for preorder traversal of the treap
def preorder(p):
    print(p.key, end=' ')  # Print the current node's key
    if p.left is not None:
        preorder(p.left)  # Traverse left subtree
    if p.right is not None:
        preorder(p.right)  # Traverse right subtree

# Function to print the treap in both inorder and preorder
def print_treap(p):
    inorder(p)  # Print inorder
    print()
    preorder(p)  # Print preorder
    print()

# Function to perform a right rotation on the treap
def right_rotate(p):
    q = p.left  # Store the left child
    p.left = q.right  # Move the right child of left child to the left of p
    q.right = p  # Perform the rotation
    return q  # Return the new root after rotation

# Function to perform a left rotation on the treap
def left_rotate(p):
    q = p.right  # Store the right child
    p.right = q.left  # Move the left child of right child to the right of p
    q.left = p  # Perform the rotation
    return q  # Return the new root after rotation

# Function to insert a new node into the treap
def insert(t, key, priority):
    if t is None:
        return Node(key, priority)  # Create a new node if leaf is reached
    if t.key == key:
        return t  # Ignore duplicate keys

    if key < t.key:  # Move to the left child
        t.left = insert(t.left, key, priority)  # Update left child pointer
        if t.priority < t.left.priority:  # Right rotation if left child has higher priority
            t = right_rotate(t)
    else:  # Move to the right child
        t.right = insert(t.right, key, priority)  # Update right child pointer
        if t.priority < t.right.priority:  # Left rotation if right child has higher priority
            t = left_rotate(t)
    return t  # Return the updated root

# Function to delete a node from the treap
def delete_node(t, key):
    if t is None:
        return None  # Return None if the tree is empty

    if key < t.key:  # Search for the key in the left subtree
        t.left = delete_node(t.left, key)
    elif key > t.key:  # Search for the key in the right subtree
        t.right = delete_node(t.right, key)
    else:
        return delete(t, key)  # Key found, proceed to delete it
    return t  # Return the updated root

# Helper function to handle the actual deletion of a node
def delete(t, key):
    if t.left is None and t.right is None:  # Case: Leaf node
        return None  # Remove the leaf node
    elif t.left is None:  # Case: Node with only right child
        t = left_rotate(t)  # Perform left rotation
    elif t.right is None:  # Case: Node with only left child
        t = right_rotate(t)  # Perform right rotation
    else:  # Case: Node with both children
        if t.left.priority > t.right.priority:  # Compare priorities
            t = right_rotate(t)  # Rotate right if left child has higher priority
        else:
            t = left_rotate(t)  # Rotate left otherwise
    return delete_node(t, key)  # Continue deletion process

# Main function to execute the program
def main():
    num = int(input())  # Read the number of commands
    root = None  # Initialize the root of the treap

    for _ in range(num):
        command = input().strip().split()  # Read the command
        if command[0] == 'i':  # Insert command
            x, y = map(int, command[1:])  # Read key and priority
            root = insert(root, x, y)  # Insert the new node
        elif command[0] == 'd':  # Delete command
            x = int(command[1])  # Read key to delete
            root = delete_node(root, x)  # Delete the node
        elif command[0] == 'f':  # Find command
            x = int(command[1])  # Read key to find
            if find(root, x):
                print("yes")  # Print "yes" if found
            else:
                print("no")  # Print "no" if not found
        elif command[0] == 'p':  # Print command
            print_treap(root)  # Print the treap

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>

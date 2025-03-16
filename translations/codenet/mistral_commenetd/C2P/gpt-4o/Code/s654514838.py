class Node:
    def __init__(self, key, priority):
        self.key = key          # The key value of the node
        self.priority = priority # The priority value of the node
        self.left = None       # Pointer to the left child
        self.right = None      # Pointer to the right child

# Function to check if a key is present in the AVL tree
def find(p, x):
    while p is not None:
        if p.key == x:
            return True
        elif p.key > x:
            p = p.left
        else:
            p = p.right
    return False

# Function to perform an inorder traversal of the AVL tree and return the keys
def inorder(a):
    result = []
    if a is not None:
        result.extend(inorder(a.left))
        result.append(a.key)
        result.extend(inorder(a.right))
    return result

# Function to perform a preorder traversal of the AVL tree and return the keys
def preorder(p):
    result = []
    if p is not None:
        result.append(p.key)
        result.extend(preorder(p.left))
        result.extend(preorder(p.right))
    return result

# Function to create a new node in the AVL tree
def makenode(x, y):
    return Node(x, y)

# Function to perform a right rotation on an AVL tree
def rightRotate(p):
    q = p.left
    p.left = q.right
    q.right = p
    return q

# Function to perform a left rotation on an AVL tree
def leftRotate(p):
    q = p.right
    p.right = q.left
    q.left = p
    return q

# Function to insert a new node into the AVL tree
def insert(t, key, priority):
    if t is None:
        return makenode(key, priority)
    
    if key < t.key:
        t.left = insert(t.left, key, priority)
    else:
        t.right = insert(t.right, key, priority)

    # Check for rotations
    if t.left and (t.priority < t.left.priority or (t.right and t.priority < t.right.priority)):
        if t.left and (t.right is None or t.left.priority > t.right.priority):
            t = rightRotate(t)
        else:
            t = leftRotate(t)
    
    return t

# Function to delete a node from the AVL tree
def Delete(t, key):
    if t is None:
        return None
    
    if key < t.key:
        t.left = Delete(t.left, key)
    elif key > t.key:
        t.right = Delete(t.right, key)
    else:
        q = t
        if t.left is None:
            return t.right
        elif t.right is None:
            return t.left
        else:
            # Find the minimum node in the right subtree
            min_larger_node = t.right
            while min_larger_node.left is not None:
                min_larger_node = min_larger_node.left
            t.key, t.priority = min_larger_node.key, min_larger_node.priority
            t.right = Delete(t.right, min_larger_node.key)

    # Check for rotations
    if t and (t.left and (t.priority < t.left.priority or (t.right and t.priority < t.right.priority))):
        if t.left and (t.right is None or t.left.priority > t.right.priority):
            t = rightRotate(t)
        else:
            t = leftRotate(t)

    return t

# Main function to read commands and perform the corresponding operations on the AVL tree
def main():
    root = None
    num = int(input())
    
    for _ in range(num):
        command = input().strip().split()
        if command[0] == 'i':  # Insert a new node
            x, y = int(command[1]), int(command[2])
            root = insert(root, x, y)
        elif command[0] == 'd':  # Delete a node
            x = int(command[1])
            root = Delete(root, x)
        elif command[0] == 'f':  # Find a node
            x = int(command[1])
            if find(root, x):
                print("yes")
            else:
                print("no")
        elif command[0] == 'p':  # Print the AVL tree
            print("Inorder:", inorder(root))
            print("Preorder:", preorder(root))

if __name__ == "__main__":
    main()

# <END-OF-CODE>

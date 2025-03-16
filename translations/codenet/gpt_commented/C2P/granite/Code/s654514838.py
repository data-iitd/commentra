

class Node:
    def __init__(self, key, priority):
        self.key = key
        self.priority = priority
        self.left = None
        self.right = None

def find(root, x):
    while root is not None:
        if root.key == x:
            return True
        elif root.key > x:
            root = root.left
        else:
            root = root.right
    return False

def inorder(root):
    if root.left is not None:
        inorder(root.left)
    print(root.key, end=" ")
    if root.right is not None:
        inorder(root.right)

def preorder(root):
    print(root.key, end=" ")
    if root.left is not None:
        preorder(root.left)
    if root.right is not None:
        preorder(root.right)

def print_tree(root):
    inorder(root)
    print()
    preorder(root)
    print()

def right_rotate(root):
    left = root.left
    root.left = left.right
    left.right = root
    return left

def left_rotate(root):
    right = root.right
    root.right = right.left
    right.left = root
    return right

def insert(root, key, priority):
    if root is None:
        return Node(key, priority)
    if root.key == key:
        return root
    if key < root.key:
        root.left = insert(root.left, key, priority)
        if root.priority < root.left.priority:
            root = right_rotate(root)
    else:
        root.right = insert(root.right, key, priority)
        if root.priority < root.right.priority:
            root = left_rotate(root)
    return root

def delete(root, key):
    if root is None:
        return None
    if key < root.key:
        root.left = delete(root.left, key)
    elif key > root.key:
        root.right = delete(root.right, key)
    else:
        if root.left is None:
            return root.right
        elif root.right is None:
            return root.left
        if root.left.priority > root.right.priority:
            root = right_rotate(root)
            root.right = delete(root.right, key)
        else:
            root = left_rotate(root)
            root.left = delete(root.left, key)
    return root

num = int(input())
root = None
for _ in range(num):
    command = input().split()
    if command[0] == "insert":
        key, priority = map(int, command[1:])
        root = insert(root, key, priority)
    elif command[0] == "delete":
        key = int(command[1])
        root = delete(root, key)
    elif command[0] == "find":
        key = int(command[1])
        if find(root, key):
            print("yes")
        else:
            print("no")
    elif command[0] == "print":
        print_tree(root)


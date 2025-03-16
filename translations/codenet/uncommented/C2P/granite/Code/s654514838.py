
class Node:
    def __init__(self, key, priority):
        self.key = key
        self.priority = priority
        self.left = None
        self.right = None

def delete(t, key):
    if t is None:
        return None

    if key < t.key:
        t.left = delete(t.left, key)
    elif key > t.key:
        t.right = delete(t.right, key)
    else:
        return _delete(t, key)

    return t

def _delete(t, key):
    if t.left is None and t.right is None:
        return None

    if t.left is None:
        t = right_rotate(t)
    elif t.right is None:
        t = left_rotate(t)
    else:
        if t.left.priority > t.right.priority:
            t = right_rotate(t)
        else:
            t = left_rotate(t)

    return delete(t, key)

def right_rotate(t):
    s = t.left
    t.left = s.right
    s.right = t
    return s

def left_rotate(t):
    s = t.right
    t.right = s.left
    s.left = t
    return s

def insert(t, key, priority):
    if t is None:
        return Node(key, priority)

    if key < t.key:
        t.left = insert(t.left, key, priority)
    else:
        t.right = insert(t.right, key, priority)

    if t.priority < t.left.priority:
        t = right_rotate(t)
    elif t.priority < t.right.priority:
        t = left_rotate(t)

    return t

def find(t, key):
    while t is not None:
        if key == t.key:
            return True
        elif key < t.key:
            t = t.left
        else:
            t = t.right
    return False

def inorder(t):
    if t.left is not None:
        inorder(t.left)
    print(f" {t.key}", end="")
    if t.right is not None:
        inorder(t.right)

def preorder(t):
    print(f" {t.key}", end="")
    if t.left is not None:
        preorder(t.left)
    if t.right is not None:
        preorder(t.right)

def print_tree(t):
    inorder(t)
    print()
    preorder(t)
    print()

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


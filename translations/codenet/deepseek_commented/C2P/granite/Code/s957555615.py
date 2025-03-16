
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.parent = None

def tree_minimum(x):
    while x.left is not None:
        x = x.left
    return x

def tree_maximum(x):
    while x.right is not None:
        x = x.right
    return x

def tree_search(u, k):
    if u is None or k == u.key:
        return u
    if k < u.key:
        return tree_search(u.left, k)
    else:
        return tree_search(u.right, k)

def tree_successor(x):
    if x.right is not None:
        return tree_minimum(x.right)
    y = x.parent
    while y is not None and x == y.right:
        x = y
        y = y.parent
    return y

def tree_delete(z):
    y = None
    x = None
    if z.left is None or z.right is None:
        y = z
    else:
        y = tree_successor(z)
    if y.left is not None:
        x = y.left
    else:
        x = y.right
    if x is not None:
        x.parent = y.parent
    if y.parent is None:
        root = x
    elif y == y.parent.left:
        y.parent.left = x
    else:
        y.parent.right = x
    if y!= z:
        z.key = y.key

def insert(k):
    y = None
    x = root
    z = Node(k)
    z.left = None
    z.right = None
    while x is not None:
        y = x
        if z.key < x.key:
            x = x.left
        else:
            x = x.right
    z.parent = y
    if y is None:
        root = z
    elif z.key < y.key:
        y.left = z
    else:
        y.right = z

def inorder(u):
    if u is None:
        return
    inorder(u.left)
    print(f" {u.key}", end="")
    inorder(u.right)

def preorder(u):
    if u is None:
        return
    print(f" {u.key}", end="")
    preorder(u.left)
    preorder(u.right)

n = int(input())
for i in range(n):
    com = input().split()
    if com[0] == "f":
        x = int(com[1])
        t = tree_search(root, x)
        if t is not None:
            print("yes")
        else:
            print("no")
    elif com[0] == "i":
        x = int(com[1])
        insert(x)
    elif com[0] == "p":
        inorder(root)
        print()
        preorder(root)
        print()
    elif com[0] == "d":
        x = int(com[1])
        tree_delete(tree_search(root, x))


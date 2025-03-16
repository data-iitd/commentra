
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.parent = None

root = None

def treeMinimum(x):
    while x.left is not None:
        x = x.left
    return x

def treeMaximum(x):
    while x.right is not None:
        x = x.right
    return x

def treeSearch(u, k):
    if u is None or k == u.key:
        return u
    if k < u.key:
        return treeSearch(u.left, k)
    else:
        return treeSearch(u.right, k)

def treeSuccessor(x):
    if x.right is not None:
        return treeMinimum(x.right)
    y = x.parent
    while y is not None and x == y.right:
        x = y
        y = y.parent
    return y

def treeDelete(z):
    y = None
    x = None
    if z.left is None or z.right is None:
        y = z
    else:
        y = treeSuccessor(z)
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
    print(u.key, end=" ")
    inorder(u.right)

def preorder(u):
    if u is None:
        return
    print(u.key, end=" ")
    preorder(u.left)
    preorder(u.right)

n = int(input())
for i in range(n):
    com = input().split()
    if com[0] == 'find':
        x = int(com[1])
        t = treeSearch(root, x)
        if t is not None:
            print("yes")
        else:
            print("no")
    elif com[0] == 'insert':
        x = int(com[1])
        insert(x)
    elif com[0] == 'print':
        inorder(root)
        print()
        preorder(root)
        print()
    elif com[0] == 'delete':
        x = int(com[1])
        treeDelete(treeSearch(root, x))


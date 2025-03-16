class Node:
    def __init__(self, key):
        self.right = None
        self.left = None
        self.parent = None
        self.key = key

NIL = None
root = None

def treeMinimum(x):
    while x.left != NIL:
        x = x.left
    return x

def treeMaximum(x):
    while x.right != NIL:
        x = x.right
    return x

def treeSearch(u, k):
    while u != NIL and k != u.key:
        if k < u.key:
            u = u.left
        else:
            u = u.right
    return u

def treeSuccessor(x):
    if x.right != NIL:
        return treeMinimum(x.right)
    y = x.parent
    while y != NIL and x == y.right:
        x = y
        y = y.parent
    return y

def treeDelete(z):
    if z.left == NIL or z.right == NIL:
        y = z
    else:
        y = treeSuccessor(z)

    if y.left != NIL:
        x = y.left
    else:
        x = y.right

    if x != NIL:
        x.parent = y.parent

    if y.parent == NIL:
        root = x
    elif y == y.parent.left:
        y.parent.left = x
    else:
        y.parent.right = x

    if y != z:
        z.key = y.key

def insert(k):
    y = NIL
    x = root
    z = Node(k)

    while x != NIL:
        y = x
        if z.key < x.key:
            x = x.left
        else:
            x = x.right
    z.parent = y
    if y == NIL:
        root = z
    elif z.key < y.key:
        y.left = z
    else:
        y.right = z

def inorder(u):
    if u == NIL:
        return
    inorder(u.left)
    print(" " + str(u.key), end='')
    inorder(u.right)

def preorder(u):
    if u == NIL:
        return
    print(" " + str(u.key), end='')
    preorder(u.left)
    preorder(u.right)

n = int(input())
for i in range(n):
    com = input().split()
    if com[0] == 'find':
        x = int(com[1])
        t = treeSearch(root, x)
        if t != NIL:
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


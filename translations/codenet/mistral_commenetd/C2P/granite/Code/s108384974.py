

# Python code to implement an AVL tree

class Node:
    def __init__(self, key):
        self.key = key
        self.p = None
        self.l = None
        self.r = None

def find(x, k):
    while x is not None and k!= x.key:
        if k < x.key:
            x = x.l
        else:
            x = x.r
    return x

def insert(k):
    y = None
    x = r
    z = Node(k)
    while x is not None:
        y = x
        if k < x.key:
            x = x.l
        else:
            x = x.r
    z.p = y
    if y is None:
        r = z
    elif k < y.key:
        y.l = z
    else:
        y.r = z

def inorder(u):
    if u is None:
        return
    inorder(u.l)
    print(u.key, end=" ")
    inorder(u.r)

def preorder(u):
    if u is None:
        return
    print(u.key, end=" ")
    preorder(u.l)
    preorder(u.r)

def print_tree():
    inorder(r)
    print()
    preorder(r)
    print()

n = int(input())
for i in range(n):
    command = input().split()
    if command[0] == "f":
        x = int(command[1])
        t = find(r, x)
        if t is None:
            print("no")
        else:
            print("yes")
    elif command[0] == "i":
        z = int(command[1])
        insert(z)
    else:
        print_tree()

print("
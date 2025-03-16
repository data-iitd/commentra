
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
    z.l = None
    z.r = None

    while x is not None:
        y = x
        if z.key < x.key:
            x = x.l
        else:
            x = x.r
    z.p = y

    if y is None:
        r = z
    elif z.key < y.key:
        y.l = z
    else:
        y.r = z

def inorder(u):
    if u is None:
        return
    inorder(u.l)
    print(u.key, end=' ')
    inorder(u.r)

def preorder(u):
    if u is None:
        return
    print(u.key, end=' ')
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
    if command[0] == 'find':
        x = find(r, int(command[1]))
        if x is None:
            print('no')
        else:
            print('yes')
    elif command[0] == 'insert':
        insert(int(command[1]))
    else:
        print_tree()


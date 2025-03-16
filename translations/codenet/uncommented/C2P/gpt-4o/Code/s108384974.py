class Node:
    def __init__(self, key):
        self.key = key
        self.p = None
        self.l = None
        self.r = None

NIL = None
r = NIL

def find(x, k):
    while x is not NIL and k != x.key:
        if k < x.key:
            x = x.l
        else:
            x = x.r
    return x

def insert(k):
    global r
    y = NIL
    x = r

    z = Node(k)

    while x is not NIL:
        y = x
        if z.key < x.key:
            x = x.l
        else:
            x = x.r
    z.p = y

    if y is NIL:
        r = z
    elif z.key < y.key:
        y.l = z
    else:
        y.r = z

def inorder(u):
    if u is NIL:
        return
    inorder(u.l)
    print(u.key, end=' ')
    inorder(u.r)

def preorder(u):
    if u is NIL:
        return
    print(u.key, end=' ')
    preorder(u.l)
    preorder(u.r)

def print_tree():
    inorder(r)
    print()
    preorder(r)
    print()

if __name__ == "__main__":
    n = int(input())
    for _ in range(n):
        s = input().strip()
        if s[0] == 'f':
            x = int(input())
            t = find(r, x)
            if t is NIL:
                print("no")
            else:
                print("yes")
        elif s[0] == 'i':
            z = int(input())
            insert(z)
        else:
            print_tree()

# <END-OF-CODE>

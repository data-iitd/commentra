
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
        if t.left is None:
            return t.right
        elif t.right is None:
            return t.left
        temp = t.right
        while temp.left is not None:
            temp = temp.left
        t.key = temp.key
        t.right = delete(t.right, temp.key)
    if t is None:
        return t
    if t.priority < t.left.priority or t.priority < t.right.priority:
        if t.left.priority > t.right.priority:
            t = rightRotate(t)
        else:
            t = leftRotate(t)
    return t

def rightRotate(t):
    q = t.left
    t.left = q.right
    q.right = t
    return q

def leftRotate(t):
    q = t.right
    t.right = q.left
    q.left = t
    return q

def insert(t, key, priority):
    if t is None:
        return Node(key, priority)
    if key < t.key:
        t.left = insert(t.left, key, priority)
    else:
        t.right = insert(t.right, key, priority)
    if t.priority < t.left.priority or t.priority < t.right.priority:
        if t.left.priority > t.right.priority:
            t = rightRotate(t)
        else:
            t = leftRotate(t)
    return t

def find(p, x):
    while p is not None:
        if p.key == x:
            return 1
        elif p.key > x:
            p = p.left
        else:
            p = p.right
    return 0

def inorder(a):
    if a.left is not None:
        inorder(a.left)
    print(f" {a.key}", end="")
    if a.right is not None:
        inorder(a.right)

def preorder(p):
    print(f" {p.key}", end="")
    if p.left is not None:
        preorder(p.left)
    if p.right is not None:
        preorder(p.right)

def print(p):
    inorder(p)
    preorder(p)

def main():
    num = int(input())
    root = None
    for i in range(num):
        com = input().split()
        if com[0] == "i":
            x, y = map(int, com[1:])
            root = insert(root, x, y)
        elif com[0] == "d":
            x = int(com[1])
            root = delete(root, x)
        elif com[0] == "f":
            x = int(com[1])
            if find(root, x):
                print("yes")
            else:
                print("no")
        elif com[0] == "p":
            print(root)

if __name__ == "__main__":
    main()


class Node:
    def __init__(self, key, priority):
        self.key = key
        self.priority = priority
        self.left = None
        self.right = None

def find(p, x):
    while p is not None:
        if p.key == x:
            return True
        elif p.key > x:
            p = p.left
        else:
            p = p.right
    return False

def inorder(a):
    if a.left is not None:
        inorder(a.left)
    print(" " + str(a.key), end="")
    if a.right is not None:
        inorder(a.right)
    return

def preorder(p):
    print(" " + str(p.key), end="")
    if p.left is not None:
        preorder(p.left)
    if p.right is not None:
        preorder(p.right)
    return

def print_tree(p):
    inorder(p)
    print()
    preorder(p)
    print()
    return

def makenode(x, y):
    return Node(x, y)

def right_rotate(p):
    q = p.left
    p.left = q.right
    q.right = p
    return q

def left_rotate(p):
    q = p.right
    p.right = q.left
    q.left = p
    return q

def insert(t, key, priority):
    if t is None:
        return makenode(key, priority)
    if t.key == key:
        return t
    
    if key < t.key:
        t.left = insert(t.left, key, priority)
        if t.priority < t.left.priority:
            t = right_rotate(t)
    else:
        t.right = insert(t.right, key, priority)
        if t.priority < t.right.priority:
            t = left_rotate(t)
    return t

def delete(t, key):
    if t is None:
        return None
    
    if key < t.key:
        t.left = delete(t.left, key)
    elif key > t.key:
        t.right = delete(t.right, key)
    else:
        if t.left is None and t.right is None:
            return None
        elif t.left is None:
            t = left_rotate(t)
        elif t.right is None:
            t = right_rotate(t)
        else:
            if t.left.priority > t.right.priority:
                t = right_rotate(t)
            else:
                t = left_rotate(t)
        return delete(t, key)
    return t

def main():
    num = int(input())
    root = None
    
    for _ in range(num):
        com = input().split()
        if com[0] == 'i':
            x, y = map(int, com[1:])
            root = insert(root, x, y)
        elif com[0] == 'd':
            x = int(com[1])
            root = delete(root, x)
        elif com[0] == 'f':
            x = int(com[1])
            if find(root, x):
                print("yes")
            else:
                print("no")
        elif com[0] == 'p':
            print_tree(root)

if __name__ == "__main__":
    main()

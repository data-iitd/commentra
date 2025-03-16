class Node:
    def __init__(self, key, priority):
        self.key = key
        self.priority = priority
        self.left = None
        self.right = None

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
    print(" " + str(a.key), end='')
    if a.right is not None:
        inorder(a.right)
    return

def preorder(p):
    print(" " + str(p.key), end='')
    if p.left is not None:
        preorder(p.left)
    if p.right is not None:
        preorder(p.right)
    return

def print_tree(p):
    inorder(p)
    preorder(p)
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
    t = insert(t, key, priority)
    if t.priority < t.left.priority or t.priority < t.right.priority:
        if t.left.priority > t.right.priority:
            t = right_rotate(t)
        else:
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
        if t.left is None:
            return t.right
        elif t.right is None:
            return t.left
        else:
            if t.left.priority > t.right.priority:
                t = right_rotate(t)
                t.right = delete(t.right, key)
            else:
                t = left_rotate(t)
                t.left = delete(t.left, key)
    return t

def delete_node(t, key):
    if t is None:
        return None
    if key < t.key:
        t.left = delete_node(t.left, key)
    elif key > t.key:
        t.right = delete_node(t.right, key)
    else:
        q = t
        t = delete(t, key)
        del q
    if t is not None and (t.priority < t.left.priority or t.priority < t.right.priority):
        if t.left.priority > t.right.priority:
            t = right_rotate(t)
        else:
            t = left_rotate(t)
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
            root = delete_node(root, x)
        elif com[0] == 'f':
            x = int(com[1])
            if find(root, x):
                print("yes")
            else:
                print("no")
        elif com[0] == 'p':
            if root is not None:
                print_tree(root)
            print()

if __name__ == "__main__":
    main()

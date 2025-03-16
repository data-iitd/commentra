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
    if a is not None:
        inorder(a.left)
        print(a.key, end=' ')
        inorder(a.right)

def preorder(p):
    if p is not None:
        print(p.key, end=' ')
        preorder(p.left)
        preorder(p.right)

def print_tree(p):
    inorder(p)
    print()
    preorder(p)
    print()

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
        return t  # Ignore duplicate keys
    
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
    if t.left is None and t.right is None:  # Leaf node
        return None
    elif t.left is None:  # Only right child
        return left_rotate(t)
    elif t.right is None:  # Only left child
        return right_rotate(t)
    else:  # Both children
        if t.left.priority > t.right.priority:
            t = right_rotate(t)
        else:
            t = left_rotate(t)
    
    return delete(t, key)

def Delete(t, key):
    if t is None:
        return None
    
    if key < t.key:
        t.left = Delete(t.left, key)
    elif key > t.key:
        t.right = Delete(t.right, key)
    else:
        return delete(t, key)
    
    return t

def main():
    num = int(input())
    root = None
    
    for _ in range(num):
        command = input().strip().split()
        if command[0] == 'i':
            x, y = map(int, command[1:])
            root = insert(root, x, y)
        elif command[0] == 'd':
            x = int(command[1])
            root = Delete(root, x)
        elif command[0] == 'f':
            x = int(command[1])
            if find(root, x):
                print("yes")
            else:
                print("no")
        elif command[0] == 'p':
            print_tree(root)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

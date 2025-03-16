class Node:
    def __init__(self, key):
        self.right = None
        self.left = None
        self.parent = None
        self.key = key

NIL = None
root = None

# This function finds the node with the minimum key in the subtree rooted at x
def tree_minimum(x):
    while x.left != NIL:
        x = x.left
    return x

# This function finds the node with the maximum key in the subtree rooted at x
def tree_maximum(x):
    while x.right != NIL:
        x = x.right
    return x

# This function searches for a node with a given key k in the subtree rooted at u
def tree_search(u, k):
    while u != NIL and k != u.key:
        if k < u.key:
            u = u.left
        else:
            u = u.right
    return u

# This function finds the successor of a given node x in the tree
def tree_successor(x):
    if x.right != NIL:
        return tree_minimum(x.right)
    y = x.parent
    while y != NIL and x == y.right:
        x = y
        y = y.parent
    return y

# This function deletes a node z from the tree
def tree_delete(z):
    y = z
    if z.left == NIL or z.right == NIL:
        y = z
    else:
        y = tree_successor(z)
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

# This function inserts a new node with key k into the tree
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

# This function performs an inorder traversal of the tree and prints the keys
def inorder(u):
    if u == NIL:
        return
    inorder(u.left)
    print(" " + str(u.key), end='')
    inorder(u.right)

# This function performs a preorder traversal of the tree and prints the keys
def preorder(u):
    if u == NIL:
        return
    print(" " + str(u.key), end='')
    preorder(u.left)
    preorder(u.right)

# Main function to handle commands
def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    index = 1
    commands = []
    
    for i in range(n):
        com = data[index]
        index += 1
        if com[0] == 'f':
            x = int(data[index])
            index += 1
            t = tree_search(root, x)
            if t != NIL:
                print("yes")
            else:
                print("no")
        elif com[0] == 'i':
            x = int(data[index])
            index += 1
            insert(x)
        elif com[0] == 'p':
            inorder(root)
            print()
            preorder(root)
            print()
        elif com[0] == 'd':
            x = int(data[index])
            index += 1
            tree_delete(tree_search(root, x))

if __name__ == "__main__":
    main()

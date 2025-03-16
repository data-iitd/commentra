# Define the structure Node
class Node:
    def __init__(self, parent, left, right):
        self.parent = parent
        self.left = left
        self.right = right

# Declare an array of Node structures and an integer variable n
R = []
n = 0

# Declare the traversal functions
def preorder(x):
    if x == NIL:
        return
    print(" " + str(x), end="")
    preorder(R[x].left)
    preorder(R[x].right)

def inorder(x):
    if x == NIL:
        return
    inorder(R[x].left)
    print(" " + str(x), end="")
    inorder(R[x].right)

def postorder(x):
    if x == NIL:
        return
    postorder(R[x].left)
    postorder(R[x].right)
    print(" " + str(x), end="")

# Implement the main function
def main():
    global R, n
    for i in range(0, 10000):
        R.append(Node(NIL, NIL, NIL))
    n = int(input())
    for i in range(0, n):
        a, b, c = map(int, input().split())
        R[a].left = b
        R[a].right = c
        if b!= NIL:
            R[b].parent = a
        if c!= NIL:
            R[c].parent = a
    for i in range(0, n):
        if R[i].parent == NIL:
            root = i
    print("Preorder")
    preorder(root)
    print()
    print("Inorder")
    inorder(root)
    print()
    print("Postorder")
    postorder(root)
    print()

# 
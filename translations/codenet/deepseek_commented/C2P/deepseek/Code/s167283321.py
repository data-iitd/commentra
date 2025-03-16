class Node:
    def __init__(self, parent=-1, left=-1, right=-1):
        self.parent = parent
        self.left = left
        self.right = right

# Declare an array of Node structures and an integer variable n
R = [Node() for _ in range(10000)]
n = 0

# Declare the traversal functions
def preorder(x):
    if x == -1:
        return
    print(f" {x}", end="")
    preorder(R[x].left)
    preorder(R[x].right)

def inorder(x):
    if x == -1:
        return
    inorder(R[x].left)
    print(f" {x}", end="")
    inorder(R[x].right)

def postorder(x):
    if x == -1:
        return
    postorder(R[x].left)
    postorder(R[x].right)
    print(f" {x}", end="")

# Implement the main function
if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        R[i].parent = -1
    for i in range(n):
        a, b, c = map(int, input().split())
        R[a].left = b
        R[a].right = c
        if b != -1: R[b].parent = a
        if c != -1: R[c].parent = a
    for i in range(n):
        if R[i].parent == -1:
            root = i
            break
    print("Preorder")
    preorder(root)
    print()
    print("Inorder")
    inorder(root)
    print()
    print("Postorder")
    postorder(root)
    print()

class Node:
    def __init__(self, parent=-1, left=-1, right=-1):
        self.parent = parent
        self.left = left
        self.right = right

def preorder(x, R):
    if x == -1:
        return
    print(f" {x}", end="")
    preorder(R[x].left, R)
    preorder(R[x].right, R)

def inorder(x, R):
    if x == -1:
        return
    inorder(R[x].left, R)
    print(f" {x}", end="")
    inorder(R[x].right, R)

def postorder(x, R):
    if x == -1:
        return
    postorder(R[x].left, R)
    postorder(R[x].right, R)
    print(f" {x}", end="")

n = int(input())
R = [Node() for _ in range(10000)]

for _ in range(n):
    a, b, c = map(int, input().split())
    R[a].left = b
    R[a].right = c
    if b != -1:
        R[b].parent = a
    if c != -1:
        R[c].parent = a

root = -1
for i in range(n):
    if R[i].parent == -1:
        root = i
        break

print("Preorder")
preorder(root, R)
print()
print("Inorder")
inorder(root, R)
print()
print("Postorder")
postorder(root, R)
print()

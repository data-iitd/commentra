class Node:
    def __init__(self, parent=-1, left=-1, right=-1):
        self.parent = parent
        self.left = left
        self.right = right

def preorder(a, bt):
    if a == -1:
        return
    print(f" {a}", end="")
    preorder(bt[a].left, bt)
    preorder(bt[a].right, bt)

def inorder(a, bt):
    if a == -1:
        return
    inorder(bt[a].left, bt)
    print(f" {a}", end="")
    inorder(bt[a].right, bt)

def postorder(a, bt):
    if a == -1:
        return
    postorder(bt[a].left, bt)
    postorder(bt[a].right, bt)
    print(f" {a}", end="")

n = int(input())
bt = [Node() for _ in range(n)]

for _ in range(n):
    num, left, right = map(int, input().split())
    bt[num].left = left
    bt[num].right = right
    if left != -1:
        bt[left].parent = num
    if right != -1:
        bt[right].parent = num

root = next(i for i in range(n) if bt[i].parent == -1)

print("Preorder")
preorder(root, bt)
print()

print("Inorder")
inorder(root, bt)
print()

print("Postorder")
postorder(root, bt)
print()


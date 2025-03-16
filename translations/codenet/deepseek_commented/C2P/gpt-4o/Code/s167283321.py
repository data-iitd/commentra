class Node:
    def __init__(self):
        self.parent = -1
        self.left = -1
        self.right = -1

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

# Main function
n = int(input())
R = [Node() for _ in range(10000)]
root = -1

for i in range(n):
    R[i].parent = -1

for i in range(n):
    a, b, c = map(int, input().split())
    R[a].left = b
    R[a].right = c
    if b != -1:
        R[b].parent = a
    if c != -1:
        R[c].parent = a

for i in range(n):
    if R[i].parent == -1:
        root = i

print("Preorder")
preorder(root)
print("\nInorder")
inorder(root)
print("\nPostorder")
postorder(root)
print()

# <END-OF-CODE>

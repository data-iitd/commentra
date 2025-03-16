class Node:
    def __init__(self, id):
        self.id = id
        self.l = -1
        self.r = -1
        self.par = -1

MAX = 25
nodes = [Node(i) for i in range(MAX)]

def init(n):
    for i in range(n):
        nodes[i].par = nodes[i].l = nodes[i].r = -1

def preorder(p):
    if p != -1:
        print(f" {p}", end="")
        preorder(nodes[p].l)
        preorder(nodes[p].r)

def inorder(p):
    if p != -1:
        inorder(nodes[p].l)
        print(f" {p}", end="")
        inorder(nodes[p].r)

def postorder(p):
    if p != -1:
        postorder(nodes[p].l)
        postorder(nodes[p].r)
        print(f" {p}", end="")

n = int(input())
init(n)

for _ in range(n):
    id, l, r = map(int, input().split())
    if l != -1:
        nodes[id].l = l
        nodes[l].par = id
    if r != -1:
        nodes[id].r = r
        nodes[r].par = id

for i in range(n):
    if nodes[i].par == -1:
        p = i
        break

print("Preorder")
preorder(p)
print()

print("Inorder")
inorder(p)
print()

print("Postorder")
postorder(p)
print()

class Node:
    def __init__(self, id):
        self.l = -1
        self.r = -1
        self.par = -1

def init(n):
    return [Node(i) for i in range(n)]

def Preorder(node, nodes):
    if node != -1:
        print(f" {node}", end="")
        Preorder(nodes[node].l, nodes)
        Preorder(nodes[node].r, nodes)

def Inorder(node, nodes):
    if node != -1:
        Inorder(nodes[node].l, nodes)
        print(f" {node}", end="")
        Inorder(nodes[node].r, nodes)

def Postorder(node, nodes):
    if node != -1:
        Postorder(nodes[node].l, nodes)
        Postorder(nodes[node].r, nodes)
        print(f" {node}", end="")

n = int(input())
nodes = init(n)

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
        root = i
        break

print("Preorder")
Preorder(root, nodes)
print()

print("Inorder")
Inorder(root, nodes)
print()

print("Postorder")
Postorder(root, nodes)
print()

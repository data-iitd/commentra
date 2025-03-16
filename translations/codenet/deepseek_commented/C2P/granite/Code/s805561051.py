
class Node:
    def __init__(self, parent, left, right):
        self.parent = parent
        self.left = left
        self.right = right

def preorder(node):
    if node is None:
        return
    print(node.val, end=" ")
    preorder(node.left)
    preorder(node.right)

def inorder(node):
    if node is None:
        return
    inorder(node.left)
    print(node.val, end=" ")
    inorder(node.right)

def postorder(node):
    if node is None:
        return
    postorder(node.left)
    postorder(node.right)
    print(node.val, end=" ")

n = int(input())
nodes = [None] * n
for i in range(n):
    val, left, right = map(int, input().split())
    nodes[val] = Node(None, left, right)
    if left!= -1:
        nodes[left].parent = val
    if right!= -1:
        nodes[right].parent = val

root = None
for i in range(n):
    if nodes[i].parent is None:
        root = nodes[i]
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


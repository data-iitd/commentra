
class Node:
    def __init__(self, parent, left, right):
        self.parent = parent
        self.left = left
        self.right = right

def preorder(node):
    if node is None:
        return
    print(f" {node.id}", end="")
    preorder(node.left)
    preorder(node.right)

def inorder(node):
    if node is None:
        return
    inorder(node.left)
    print(f" {node.id}", end="")
    inorder(node.right)

def postorder(node):
    if node is None:
        return
    postorder(node.left)
    postorder(node.right)
    print(f" {node.id}", end="")

def main():
    n = int(input())
    nodes = [None] * n
    for i in range(n):
        parent, left, right = map(int, input().split())
        nodes[i] = Node(parent, left, right)
        if left!= -1:
            nodes[left].parent = i
        if right!= -1:
            nodes[right].parent = i
    root = None
    for i in range(n):
        if nodes[i].parent is None:
            root = i
            break
    print("Preorder")
    preorder(nodes[root])
    print()
    print("Inorder")
    inorder(nodes[root])
    print()
    print("Postorder")
    postorder(nodes[root])
    print()

if __name__ == "__main__":
    main()


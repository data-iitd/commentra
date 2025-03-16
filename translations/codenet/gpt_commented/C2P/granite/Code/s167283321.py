
class Node:
    def __init__(self, parent, left, right):
        self.parent = parent
        self.left = left
        self.right = right

def preorder(node):
    if node is None:
        return
    print(f" {node.val}", end="")
    preorder(node.left)
    preorder(node.right)

def inorder(node):
    if node is None:
        return
    inorder(node.left)
    print(f" {node.val}", end="")
    inorder(node.right)

def postorder(node):
    if node is None:
        return
    postorder(node.left)
    postorder(node.right)
    print(f" {node.val}", end="")

if __name__ == "__main__":
    n = int(input("Enter the number of nodes in the tree: "))
    nodes = [Node(None, None, None) for _ in range(n)]
    for _ in range(n):
        a, b, c = map(int, input("Enter the current node and its left and right children: ").split())
        nodes[a].left = b
        nodes[a].right = c
        if b!= -1:
            nodes[b].parent = a
        if c!= -1:
            nodes[c].parent = a
    root = None
    for node in nodes:
        if node.parent is None:
            root = node
            break
    print("Preorder:")
    preorder(root)
    print()

    print("Inorder:")
    inorder(root)
    print()

    print("Postorder:")
    postorder(root)
    print()


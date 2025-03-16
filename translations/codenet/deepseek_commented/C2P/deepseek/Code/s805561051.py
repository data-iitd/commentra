class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        self.parent = None

def preorder(node):
    if node is None:
        return
    print(f" {node.val}", end='')
    preorder(node.left)
    preorder(node.right)

def inorder(node):
    if node is None:
        return
    inorder(node.left)
    print(f" {node.val}", end='')
    inorder(node.right)

def postorder(node):
    if node is None:
        return
    postorder(node.left)
    postorder(node.right)
    print(f" {node.val}", end='')

def main():
    n = int(input())
    nodes = [TreeNode(i) for i in range(n)]

    for i in range(n):
        val, left, right = map(int, input().split())
        if left != -1:
            nodes[i].left = nodes[left]
            nodes[left].parent = i
        if right != -1:
            nodes[i].right = nodes[right]
            nodes[right].parent = i

    root_index = next(i for i in range(n) if nodes[i].parent is None)

    print("Preorder")
    preorder(nodes[root_index])
    print()

    print("Inorder")
    inorder(nodes[root_index])
    print()

    print("Postorder")
    postorder(nodes[root_index])
    print()

if __name__ == "__main__":
    main()

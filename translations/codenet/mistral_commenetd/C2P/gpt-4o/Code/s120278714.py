class Node:
    def __init__(self):
        self.l = -1  # left child
        self.r = -1  # right child
        self.par = -1  # parent

def init(n):
    global N
    N = [Node() for _ in range(n)]

def Preorder(node):
    if node == -1:
        return
    print(node, end=' ')
    Preorder(N[node].l)
    Preorder(N[node].r)

def Inorder(node):
    if node == -1:
        return
    Inorder(N[node].l)
    print(node, end=' ')
    Inorder(N[node].r)

def Postorder(node):
    if node == -1:
        return
    Postorder(N[node].l)
    Postorder(N[node].r)
    print(node, end=' ')

if __name__ == "__main__":
    # Declare and initialize variables
    n = int(input())

    # Initialize the tree
    init(n)

    # Read the input and build the tree
    for _ in range(n):
        id, l, r = map(int, input().split())

        # If the left child is not -1, assign it to the left child of the current node
        if l != -1:
            N[id].l = l
            N[l].par = id

        # If the right child is not -1, assign it to the right child of the current node
        if r != -1:
            N[id].r = r
            N[r].par = id

    # Find the root node
    p = next(i for i in range(n) if N[i].par == -1)

    # Print the tree traversals in Preorder, Inorder, and Postorder
    print("Preorder")
    Preorder(p)
    print()

    print("Inorder")
    Inorder(p)
    print()

    print("Postorder")
    Postorder(p)
    print()

# <END-OF-CODE>

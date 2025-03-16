
class Node:
    def __init__(self, id, l=-1, r=-1, par=-1):
        self.id = id
        self.l = l
        self.r = r
        self.par = par

def init(n):
    global N
    N = [Node(i) for i in range(n)]

def Preorder(u):
    if u == -1:
        return
    print(" " + str(u), end="")
    Preorder(N[u].l)
    Preorder(N[u].r)

def Inorder(u):
    if u == -1:
        return
    Inorder(N[u].l)
    print(" " + str(u), end="")
    Inorder(N[u].r)

def Postorder(u):
    if u == -1:
        return
    Postorder(N[u].l)
    Postorder(N[u].r)
    print(" " + str(u), end="")

if __name__ == "__main__":
    # Declare and initialize variables
    n = int(input())
    init(n)

    # Read the input and build the tree
    for i in range(n):
        id, l, r = map(int, input().split())
        if l!= -1:
            N[id].l = l
            N[l].par = id
        if r!= -1:
            N[id].r = r
            N[r].par = id

    # Find the root node and perform tree traversals
    p = -1
    for i in range(n):
        if N[i].par == -1:
            p = i
            break

    # Print the tree traversals in Preorder, Inorder, and Postorder
    print("Preorder")
    Preorder(p)
    print("")

    print("Inorder")
    Inorder(p)
    print("")

    print("Postorder")
    Postorder(p)
    print("")

Comment: This is the Python translation of the given C code. It defines a Node class to represent each node in the tree, initializes the tree, reads the input, and performs the tree traversals in Preorder, Inorder, and Postorder.
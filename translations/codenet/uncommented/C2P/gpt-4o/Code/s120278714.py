class Node:
    def __init__(self):
        self.l = -1
        self.r = -1
        self.par = -1

MAX = 25
N = [Node() for _ in range(MAX)]

def init(n):
    for i in range(n):
        N[i].par = N[i].l = N[i].r = -1

def preorder(p):
    if p != -1:
        print(f" {p}", end="")
        preorder(N[p].l)
        preorder(N[p].r)

def inorder(p):
    if p != -1:
        inorder(N[p].l)
        print(f" {p}", end="")
        inorder(N[p].r)

def postorder(p):
    if p != -1:
        postorder(N[p].l)
        postorder(N[p].r)
        print(f" {p}", end="")

def main():
    n = int(input())
    init(n)

    for _ in range(n):
        id, l, r = map(int, input().split())
        if l != -1:
            N[id].l = l
            N[l].par = id
        if r != -1:
            N[id].r = r
            N[r].par = id

    p = next(i for i in range(n) if N[i].par == -1)

    print("Preorder")
    preorder(p)
    print("")

    print("Inorder")
    inorder(p)
    print("")

    print("Postorder")
    postorder(p)
    print("")

if __name__ == "__main__":
    main()

# <END-OF-CODE>


import sys

class Node:
    def __init__(self, id, l, r):
        self.id = id
        self.l = l
        self.r = r
        self.par = -1

def init(n):
    global N
    N = [Node(i, -1, -1, -1) for i in range(n)]

def Preorder(p):
    if p!= -1:
        print(" %d" % p, end="")
        Preorder(N[p].l)
        Preorder(N[p].r)

def Inorder(p):
    if p!= -1:
        Inorder(N[p].l)
        print(" %d" % p, end="")
        Inorder(N[p].r)

def Postorder(p):
    if p!= -1:
        Postorder(N[p].l)
        Postorder(N[p].r)
        print(" %d" % p, end="")

if __name__ == "__main__":
    n = int(input())
    init(n)

    for i in range(n):
        id, l, r = map(int, input().split())
        if l!= -1:
            N[id].l = l
            N[l].par = id
        if r!= -1:
            N[id].r = r
            N[r].par = id

    for i in range(n):
        if N[i].par == -1:
            p = i
            break

    print("Preorder")
    Preorder(p)
    print("")

    print("Inorder")
    Inorder(p)
    print("")

    print("Postorder")
    Postorder(p)
    print("")


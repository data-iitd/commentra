class TreeNode:
    def __init__(self, id):
        self.l = -1
        self.r = -1
        self.par = -1

class Tree:
    def __init__(self, n):
        self.N = [TreeNode(i) for i in range(n)]
        self.root = -1

    def init(self, n):
        for i in range(n):
            self.N[i].par = self.N[i].l = self.N[i].r = -1

    def Preorder(self, p):
        if p != -1:
            print(f" {p}", end="")
            self.Preorder(self.N[p].l)
            self.Preorder(self.N[p].r)

    def Inorder(self, p):
        if p != -1:
            self.Inorder(self.N[p].l)
            print(f" {p}", end="")
            self.Inorder(self.N[p].r)

    def Postorder(self, p):
        if p != -1:
            self.Postorder(self.N[p].l)
            self.Postorder(self.N[p].r)
            print(f" {p}", end="")

    def find_root(self):
        for i in range(len(self.N)):
            if self.N[i].par == -1:
                self.root = i
                break

def main():
    n = int(input())
    tree = Tree(n)
    tree.init(n)

    for i in range(n):
        id, l, r = map(int, input().split())
        if l != -1:
            tree.N[id].l = l
            tree.N[l].par = id
        if r != -1:
            tree.N[id].r = r
            tree.N[r].par = id

    tree.find_root()

    print("Preorder")
    tree.Preorder(tree.root)
    print()

    print("Inorder")
    tree.Inorder(tree.root)
    print()

    print("Postorder")
    tree.Postorder(tree.root)
    print()

if __name__ == "__main__":
    main()

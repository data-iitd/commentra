class AVLNode:
    def __init__(self, key):
        self.key = key
        self.p = None
        self.l = None
        self.r = None

class AVLTree:
    def __init__(self):
        self.r = None
        self.NIL = AVLNode(None)
        self.NIL.l = self.NIL
        self.NIL.r = self.NIL
        self.NIL.p = self.NIL

    def find(self, x, k):
        while x != self.NIL and k != x.key:
            if k < x.key:
                x = x.l
            else:
                x = x.r
        return x

    def insert(self, k):
        y = self.NIL
        x = self.r
        z = AVLNode(k)

        while x != self.NIL:
            y = x
            if z.key < x.key:
                x = x.l
            else:
                x = x.r

        z.p = y
        if y == self.NIL:
            self.r = z
        elif z.key < y.key:
            y.l = z
        else:
            y.r = z

    def inorder(self, u):
        if u == self.NIL:
            return
        self.inorder(u.l)
        print(" %d" % u.key, end='')
        self.inorder(u.r)

    def preorder(self, u):
        if u == self.NIL:
            return
        print(" %d" % u.key, end='')
        self.preorder(u.l)
        self.preorder(u.r)

    def print(self):
        self.inorder(self.r)
        print("")
        self.preorder(self.r)
        print("")

# Main function to read commands from the standard input and perform the corresponding operations
def main():
    tree = AVLTree()
    n = int(input())
    for i in range(n):
        command = input().split()
        if command[0] == 'find':
            x = int(command[1])
            t = tree.find(tree.r, x)
            if t == tree.NIL:
                print("no")
            else:
                print("yes")
        elif command[0] == 'insert':
            z = int(command[1])
            tree.insert(z)
        else:
            tree.print()

if __name__ == "__main__":
    main()

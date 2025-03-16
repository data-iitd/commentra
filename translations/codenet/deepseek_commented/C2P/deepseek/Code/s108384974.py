class TreeNode:
    def __init__(self, key):
        self.key = key
        self.p = None
        self.l = None
        self.r = None

class BinarySearchTree:
    def __init__(self):
        self.r = None
        self.NIL = TreeNode(None)  # Sentinel node
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

        z = TreeNode(k)

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
        print(" " + str(u.key), end="")
        self.inorder(u.r)

    def preorder(self, u):
        if u == self.NIL:
            return
        print(" " + str(u.key), end="")
        self.preorder(u.l)
        self.preorder(u.r)

    def print(self):
        self.inorder(self.r)
        print("")
        self.preorder(self.r)
        print("")

# Main function to execute the program
def main():
    bst = BinarySearchTree()
    n = int(input())
    for i in range(n):
        command = input().split()
        if command[0] == 'find':
            x = int(command[1])
            t = bst.find(bst.r, x)
            if t == bst.NIL:
                print("no")
            else:
                print("yes")
        elif command[0] == 'insert':
            z = int(command[1])
            bst.insert(z)
        else:
            bst.print()

if __name__ == "__main__":
    main()

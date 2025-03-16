
import sys

class Main:
    def __init__(self):
        self.sc = sys.stdin
        self.MOD = 1000000007

    def doIt(self):
        # Step 1: Read the input number of elements (n) and create a UnionFindTree instance.
        n = int(self.sc.readline())
        utf = UnionFindTree(n)

        # Step 2: Read the number of operations (m) and iterate through each operation.
        m = int(self.sc.readline())
        for i in range(m):
            # Step 3: For each operation, read the two elements (x and y) and the operation type (z).
            x, y, z = map(int, self.sc.readline().split())
            x -= 1
            y -= 1

            # Step 4: Perform the union operation on the elements x and y.
            utf.unite(x, y)

        # Step 5: Count the number of connected components in the UnionFindTree and print the result.
        cnt = 0
        for i in range(n):
            if utf.par[i] == i:
                cnt += 1
        print(cnt)

class UnionFindTree:
    def __init__(self, n):
        self.n = n
        self.par = [i for i in range(n)]
        self.rank = [0 for i in range(n)]

    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            return self.par[x] = self.find(self.par[x])

    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return
        if self.rank[x] < self.rank[y]:
            self.par[x] = y
        else:
            self.par[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    def same(self, x, y):
        return self.find(x) == self.find(y)

if __name__ == '__main__':
    obj = Main()
    obj.doIt()

# 
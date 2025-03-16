
import sys

class Main:
    def __init__(self):
        self.sc = sys.stdin
        self.MOD = 1000000007

    def doIt(self):
        n = int(self.sc.readline())
        utf = UnionFindTree(n)
        m = int(self.sc.readline())

        for i in range(m):
            x = int(self.sc.readline()) - 1
            y = int(self.sc.readline()) - 1
            z = int(self.sc.readline())
            utf.unite(x, y)

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


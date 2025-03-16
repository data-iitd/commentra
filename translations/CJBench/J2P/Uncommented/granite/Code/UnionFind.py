

class Main:
    def __init__(self, n):
        self.p = list(range(n))
        self.r = [0] * n

    def find(self, i):
        parent = self.p[i]
        if i == parent:
            return i
        result = self.find(parent)
        self.p[i] = result
        return result

    def union(self, x, y):
        r0 = self.find(x)
        r1 = self.find(y)
        if r1 == r0:
            return
        if self.r[r0] > self.r[r1]:
            self.p[r1] = r0
        elif self.r[r1] > self.r[r0]:
            self.p[r0] = r1
        else:
            self.p[r1] = r0
            self.r[r0] += 1

    def count(self):
        parents = set()
        for i in range(len(self.p)):
            root = self.find(i)
            parents.add(root)
        return len(parents)

    def __str__(self):
        return "p {} r {}\n".format(self.p, self.r)

if __name__ == "__main__":
    import sys
    n = int(input())
    uf = Main(n)
    unionOps = int(input())
    for i in range(unionOps):
        x, y = map(int, input().split())
        uf.union(x, y)
    findOps = int(input())
    for i in range(findOps):
        x = int(input())
        print("Find({}) -> Root: {}".format(x, uf.find(x)))
    print("Number of disjoint sets: {}".format(uf.count()))


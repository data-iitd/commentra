class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.r = [0] * n

    def find(self, i):
        if self.p[i] != i:
            self.p[i] = self.find(self.p[i])
        return self.p[i]

    def union(self, x, y):
        r0 = self.find(x)
        r1 = self.find(y)
        if r1 != r0:
            if self.r[r0] > self.r[r1]:
                self.p[r1] = r0
            elif self.r[r1] > self.r[r0]:
                self.p[r0] = r1
            else:
                self.p[r1] = r0
                self.r[r0] += 1

    def count(self):
        parents = []
        for i in range(len(self.p)):
            root = self.find(i)
            if root not in parents:
                parents.append(root)
        return len(parents)

    def __str__(self):
        return f"p {self.p} r {self.r}\n"


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    uf = UnionFind(n)
    unionOps = int(data[1])
    idx = 2
    for _ in range(unionOps):
        x = int(data[idx])
        y = int(data[idx + 1])
        uf.union(x, y)
        idx += 2
    findOps = int(data[idx])
    idx += 1
    for _ in range(findOps):
        x = int(data[idx])
        print(f"Find({x}) -> Root: {uf.find(x)}")
        idx += 1
    print(f"Number of disjoint sets: {uf.count()}")


main()

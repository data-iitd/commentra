class UnionFind:
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
        parents = []
        for i in range(len(self.p)):
            root = self.find(i)
            if root not in parents:
                parents.append(root)
        return len(parents)

    def __str__(self):
        return f"p {self.p} r {self.r}\n"


if __name__ == "__main__":
    n = int(input())
    uf = UnionFind(n)
    union_ops = int(input())
    for _ in range(union_ops):
        x, y = map(int, input().split())
        uf.union(x, y)
    find_ops = int(input())
    for _ in range(find_ops):
        x = int(input())
        print(f"Find({x}) -> Root: {uf.find(x)}")
    print(f"Number of disjoint sets: {uf.count()}")

# <END-OF-CODE>

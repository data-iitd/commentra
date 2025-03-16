
class Main:
    def __init__(self, n):
        self.p = [i for i in range(n)]
        self.r = [0 for i in range(n)]

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
        return "p " + str(self.p) + " r " + str(self.r) + "\n"

if __name__ == "__main__":
    n = int(input())
    uf = Main(n)
    unionOps = int(input())
    for i in range(unionOps):
        x = int(input())
        y = int(input())
        uf.union(x, y)
    findOps = int(input())
    for i in range(findOps):
        x = int(input())
        print("Find(" + str(x) + ") -> Root: " + str(uf.find(x)))
    print("Number of disjoint sets: " + str(uf.count()))


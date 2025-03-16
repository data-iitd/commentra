
import sys

class UnionFind:
    def __init__(self, n):
        self.p = [i for i in range(n)]
        self.r = [0 for i in range(n)]

    def find(self, i):
        parent = self.p[i]

        if i == parent:
            return i

        # Path compression
        result = self.find(parent)
        self.p[i] = result
        return result

    def union(self, x, y):
        r0 = self.find(x)
        r1 = self.find(y)

        if r1 == r0:
            return

        # Union by rank
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
            if root not in parents:
                parents.add(root)
        return len(parents)

    def __str__(self):
        return "p " + str(self.p) + " r " + str(self.r) + "\n"

def main():
    n = int(sys.stdin.readline())
    uf = UnionFind(n)

    unionOps = int(sys.stdin.readline())

    # Perform union operations
    for i in range(unionOps):
        x, y = map(int, sys.stdin.readline().split())
        uf.union(x, y)

    # Input: number of find operations
    findOps = int(sys.stdin.readline())

    # Perform find operations
    for i in range(findOps):
        x = int(sys.stdin.readline())
        print("Find(" + str(x) + ") -> Root: " + str(uf.find(x)))

    # Output: number of disjoint sets
    print("Number of disjoint sets: " + str(uf.count()))

if __name__ == "__main__":
    main()


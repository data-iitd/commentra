import sys

# The main package declaration.
# This package uses sys for efficient I/O operations.

class UnionFind:
    def __init__(self, n):
        self.par = list(range(n))
        self.rank = [0] * n

    def root(self, i):
        if self.par[i] != i:
            self.par[i] = self.root(self.par[i])  # Path compression
        return self.par[i]

    def same(self, i, j):
        return self.root(i) == self.root(j)

    def unite(self, i, j):
        root_i = self.root(i)
        root_j = self.root(j)
        if root_i == root_j:
            return
        if self.rank[root_i] < self.rank[root_j]:
            self.par[root_i] = root_j
        else:
            self.par[root_j] = root_i
            if self.rank[root_i] == self.rank[root_j]:
                self.rank[root_i] += 1

def next_line():
    return sys.stdin.readline().strip()

def next_ints():
    return list(map(int, next_line().split()))

def next_int_array():
    return [int(x) - 1 for x in next_line().split()]

def main():
    n, m = next_ints()
    p = next_int_array()
    uf = UnionFind(n)

    for _ in range(m):
        x, y = next_ints()
        uf.unite(x - 1, y - 1)

    s = sum(1 for i in range(n) if uf.same(i, p[i]))
    print(s)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

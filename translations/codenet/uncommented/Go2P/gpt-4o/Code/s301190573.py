import sys

class UnionFind:
    def __init__(self, n):
        self.par = list(range(n))
        self.rank = [0] * n

    def root(self, i):
        if self.par[i] != i:
            self.par[i] = self.root(self.par[i])
        return self.par[i]

    def same(self, i, j):
        return self.root(i) == self.root(j)

    def unite(self, i, j):
        i = self.root(i)
        j = self.root(j)
        if i == j:
            return
        if self.rank[i] < self.rank[j]:
            self.par[i] = j
        else:
            self.par[j] = i
            if self.rank[i] == self.rank[j]:
                self.rank[i] += 1

def next_line():
    return sys.stdin.readline().strip()

def next_ints():
    return list(map(int, next_line().split()))

def next_int_array():
    return list(map(lambda x: int(x) - 1, next_line().split()))

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

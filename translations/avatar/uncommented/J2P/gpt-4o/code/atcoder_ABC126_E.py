class UnionFindTree:
    def __init__(self, n):
        self.n = n
        self.par = list(range(n))
        self.rank = [0] * n

    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

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


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    n = int(data[index])
    index += 1
    utf = UnionFindTree(n)
    m = int(data[index])
    index += 1
    
    for _ in range(m):
        x = int(data[index]) - 1
        y = int(data[index + 1]) - 1
        z = int(data[index + 2])  # z is read but not used
        utf.unite(x, y)
        index += 3
    
    cnt = sum(1 for i in range(n) if utf.par[i] == i)
    print(cnt)


if __name__ == "__main__":
    main()

# <END-OF-CODE>

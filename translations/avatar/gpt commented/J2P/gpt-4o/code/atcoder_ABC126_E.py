class UnionFindTree:
    def __init__(self, n):
        self.n = n
        self.par = list(range(n))  # Parent array
        self.rank = [0] * n  # Rank array for union by rank

    def find(self, x):
        if self.par[x] != x:
            self.par[x] = self.find(self.par[x])  # Path compression
        return self.par[x]

    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return  # Already in the same set
        # Union by rank
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
        z = int(data[index + 2])  # Weight is not used
        index += 3
        utf.unite(x, y)
    
    # Count the number of unique connected components
    cnt = sum(1 for i in range(n) if utf.par[i] == i)
    
    # Output the count of unique connected components
    print(cnt)


if __name__ == "__main__":
    main()

# <END-OF-CODE>

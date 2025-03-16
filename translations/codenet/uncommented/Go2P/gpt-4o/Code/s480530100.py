class FenwickTree:
    def __init__(self, n):
        self.n = n
        self.data = [0] * n

    def add(self, p, x):
        p += 1
        while p <= self.n:
            self.data[p - 1] += x
            p += p & -p

    def sum(self, l, r):
        return self._sum(r) - self._sum(l)

    def _sum(self, r):
        s = 0
        while r > 0:
            s += self.data[r - 1]
            r -= r & -r
        return s


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    q = int(data[1])
    
    fw = FenwickTree(n)
    
    index = 2
    for i in range(n):
        a = int(data[index])
        fw.add(i, a)
        index += 1

    results = []
    for _ in range(q):
        t = int(data[index])
        index += 1
        if t == 0:
            p = int(data[index])
            index += 1
            x = int(data[index])
            index += 1
            fw.add(p, x)
        else:
            l = int(data[index])
            index += 1
            r = int(data[index])
            index += 1
            results.append(fw.sum(l, r))

    print("\n".join(map(str, results)))


if __name__ == "__main__":
    main()

# <END-OF-CODE>

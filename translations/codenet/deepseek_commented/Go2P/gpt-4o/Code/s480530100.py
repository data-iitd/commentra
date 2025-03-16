class FenwickTree:
    def __init__(self, n):
        self.n = n
        self.data = [0] * n

    def add(self, p, x):
        p += 1  # Convert to 1-based index
        while p <= self.n:
            self.data[p - 1] += x
            p += p & -p  # Move to the next node

    def sum(self, l, r):
        return self._sum(r) - self._sum(l)

    def _sum(self, r):
        s = 0
        while r > 0:
            s += self.data[r - 1]
            r -= r & -r  # Move to the parent node
        return s


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    idx = 0
    n = int(data[idx])
    idx += 1
    q = int(data[idx])
    idx += 1

    fw = FenwickTree(n)

    for i in range(n):
        a = int(data[idx])
        idx += 1
        fw.add(i, a)

    results = []
    for _ in range(q):
        t = int(data[idx])
        idx += 1
        if t == 0:
            p = int(data[idx])
            idx += 1
            x = int(data[idx])
            idx += 1
            fw.add(p, x)
        else:
            l = int(data[idx])
            idx += 1
            r = int(data[idx])
            idx += 1
            results.append(fw.sum(l, r))

    print("\n".join(map(str, results)))


if __name__ == "__main__":
    main()

# <END-OF-CODE>

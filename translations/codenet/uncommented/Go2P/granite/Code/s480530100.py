
class BIT:
    def __init__(self, n):
        self.n = n
        self.data = [0] * n

    def add(self, p, x):
        p += 1
        while p <= self.n:
            self.data[p-1] += x
            p += p & -p

    def sum(self, l, r):
        return self._sum(r) - self._sum(l)

    def _sum(self, r):
        s = 0
        while r > 0:
            s += self.data[r-1]
            r -= r & -r
        return s

def main():
    n, q = map(int, input().split())
    fw = BIT(n)
    for i in range(n):
        a = int(input())
        fw.add(i, a)

    for i in range(q):
        t = int(input())
        if t == 0:
            p, x = map(int, input().split())
            fw.add(p, x)
        else:
            l, r = map(int, input().split())
            print(fw.sum(l, r))

if __name__ == "__main__":
    main()


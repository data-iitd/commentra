import sys
import io
import os

class FenwickTree:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)

    def add(self, p, x):
        p += 1
        while p <= self.size:
            self.tree[p] += x
            p += p & -p

    def sum(self, l, r):
        return self._sum(r) - self._sum(l)

    def _sum(self, r):
        s = 0
        while r > 0:
            s += self.tree[r]
            r -= r & -r
        return s

def main():
    input_text = sys.stdin.read
    sys.stdin = io.StringIO(input_text())
    n, q = map(int, input().split())
    fw = FenwickTree(n)
    a = list(map(int, input().split()))
    for i in range(n):
        fw.add(i, a[i])

    for _ in range(q):
        t = list(map(int, input().split()))
        if t[0] == 0:
            p, x = t[1], t[2]
            fw.add(p, x)
        else:
            l, r = t[1], t[2]
            print(fw.sum(l, r))

if __name__ == "__main__":
    main()

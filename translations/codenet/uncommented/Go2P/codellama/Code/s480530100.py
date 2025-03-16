
import sys

def out(x):
    print(x)

def getInt():
    return int(sys.stdin.readline().rstrip())

def getString():
    return sys.stdin.readline().rstrip()

def main():
    n, q = getInt(), getInt()

    fw = FenwickTree(n)
    for i in range(n):
        a = getInt()
        fw.add(i, a)

    for i in range(q):
        t = getInt()
        if t == 0:
            p, x = getInt(), getInt()
            fw.add(p, x)
        else:
            l, r = getInt(), getInt()
            out(fw.sum(l, r))

class FenwickTree:
    def __init__(self, n):
        self.n = n
        self.data = [0] * (n + 1)

    def add(self, p, x):
        p += 1
        while p <= self.n:
            self.data[p] += x
            p += p & -p

    def sum(self, l, r):
        return self.sum(r) - self.sum(l)

    def sum(self, r):
        s = 0
        while r > 0:
            s += self.data[r - 1]
            r -= r & -r
        return s

if __name__ == "__main__":
    main()


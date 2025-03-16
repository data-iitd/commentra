import sys
from bisect import bisect_left

MOD = 1000000007
MAX_N = 500000 + 50

class FenwickTree:
    def __init__(self, n):
        self.dat = [0] * (n + 1)
        self.n = n

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.dat[i]
            i -= i & -i
        return s

    def add(self, i, x):
        while i <= self.n:
            self.dat[i] += x
            i += i & -i

def read_int():
    return int(sys.stdin.readline().strip())

def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

def main():
    n, q = read_ints()
    C = read_ints()

    P = [-1] * (MAX_N)
    Answers = [0] * (q)

    Q = []
    for i in range(q):
        l, r = read_ints()
        Q.append((i, l, r))

    Q.sort(key=lambda x: x[2])
    ft = FenwickTree(MAX_N)

    k = 0
    for idx, l, r in Q:
        while k < r:
            if P[C[k]] != -1:
                ft.add(P[C[k]] + 1, -1)
            P[C[k]] = k
            ft.add(k + 1, 1)
            k += 1

        Answers[idx] = ft.sum(r) - ft.sum(l - 1)

    for answer in Answers:
        print(answer)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

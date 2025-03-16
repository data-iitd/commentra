import sys
from bisect import bisect_left

MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = float('inf')
INF_INT32 = 2**31 - 1
NIL = -1

class FenwickTree:
    def __init__(self, n):
        self.dat = [0] * (n + 1)
        self.n = n
        self.minPow2 = 1
        while self.minPow2 <= n:
            self.minPow2 <<= 1

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

    def lower_bound(self, w):
        if w <= 0:
            return 0
        x = 0
        for k in range(self.minPow2, 0, -1):
            if x + k <= self.n and self.dat[x + k] < w:
                w -= self.dat[x + k]
                x += k
        return x + 1

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    q = int(data[1])
    C = list(map(int, data[2:n + 2]))
    
    P = [-1] * (500000 + 50)
    Answers = [0] * (500000 + 50)
    queries = []
    
    index = n + 2
    for i in range(q):
        l = int(data[index])
        r = int(data[index + 1])
        queries.append((i, l, r))
        index += 2

    queries.sort(key=lambda x: x[2])
    ft = FenwickTree(500000 + 50)

    k = 0
    for idx, l, r in queries:
        while k < r:
            if P[C[k]] != -1:
                ft.add(P[C[k]] + 1, -1)
            P[C[k]] = k
            ft.add(k + 1, 1)
            k += 1

        Answers[idx] = ft.sum(r) - ft.sum(l - 1)

    for i in range(q):
        print(Answers[i])

if __name__ == "__main__":
    main()

# <END-OF-CODE>

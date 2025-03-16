import sys
from collections import defaultdict

MOD = 1000000000 + 7

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

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    q = int(data[1])
    C = list(map(int, data[2:n + 2]))
    
    queries = []
    for i in range(q):
        l = int(data[n + 2 + 2 * i])
        r = int(data[n + 3 + 2 * i])
        queries.append((i, l, r))
    
    queries.sort(key=lambda x: x[2])
    
    P = [-1] * (n + 1)
    answers = [0] * q
    ft = FenwickTree(500000 + 50)
    
    k = 0
    for idx, l, r in queries:
        while k < r:
            if P[C[k]] != -1:
                ft.add(P[C[k]] + 1, -1)
            P[C[k]] = k
            ft.add(k + 1, 1)
            k += 1
        
        answers[idx] = ft.sum(r) - ft.sum(l - 1)
    
    print('\n'.join(map(str, answers)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>

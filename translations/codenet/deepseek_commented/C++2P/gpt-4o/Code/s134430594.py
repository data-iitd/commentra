import sys
import math

# Structure to store the left, right, and value of a ban
class Ban:
    def __init__(self, l, r, val):
        self.l = l
        self.r = r
        self.val = val

# Namespace for sparse table operations
class SparseTable:
    LIM = 20
    N = 200007

    def __init__(self):
        self.mn = [[0] * self.N for _ in range(self.LIM)]
        self.pw = [0] * self.N

    # Initialize the sparse table with the given array
    def init(self, a):
        n = len(a)
        for i in range(n):
            self.mn[0][i] = a[i]
        for i in range(self.LIM - 1):
            for j in range(n - (1 << (i + 1)) + 1):
                self.mn[i + 1][j] = max(self.mn[i][j], self.mn[i][j + (1 << i)])
        self.pw[1] = 0
        for i in range(2, self.N):
            self.pw[i] = self.pw[i // 2] + 1

    # Query the sparse table for the minimum value in the range [l, r)
    def get(self, l, r):
        r += 1
        p = self.pw[r - l]
        return min(self.mn[p][l], self.mn[p][r - (1 << p)])

# Main function to execute the program
def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    a = list(map(int, data[1:n + 1]))
    
    dl = [0] * n
    for i in range(n):
        if a[i] > i:
            print(-1)
            return
        dl[i] = i - a[i]
    
    ans = 0
    bans = []
    i = 0
    while i < n:
        r = i
        while r + 1 < n and a[r] + 1 == a[r + 1]:
            r += 1
        ans += a[r]
        bans.append(Ban(r - a[r], r, r - a[r]))
        i = r
    
    sp = SparseTable()
    sp.init(dl)
    
    for t in bans:
        if sp.get(t.l, t.r) > t.val:
            print(-1)
            return
    
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

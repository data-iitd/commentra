import sys
import math

# Structure to store the left, right, and value of a ban
class Ban:
    def __init__(self, l, r, val):
        self.l = l
        self.r = r
        self.val = val

# Namespace for sparse table operations
class Sp:
    LIM = 20
    N = 200007
    mn = [[0] * N for _ in range(LIM)]
    pw = [0] * N

    # Initialize the sparse table with the given array
    @staticmethod
    def init(a):
        n = len(a)
        for i in range(n):
            Sp.mn[0][i] = a[i]
        for i in range(Sp.LIM - 1):
            for j in range(n - (1 << (i + 1)) + 1):
                Sp.mn[i + 1][j] = max(Sp.mn[i][j], Sp.mn[i][j + (1 << i)])
        Sp.pw[1] = 0
        for i in range(2, Sp.N):
            Sp.pw[i] = Sp.pw[i // 2] + 1

    # Query the sparse table for the minimum value in the range [l, r)
    @staticmethod
    def get(l, r):
        r += 1
        p = Sp.pw[r - l]
        return min(Sp.mn[p][l], Sp.mn[p][r - (1 << p)])

# Main function to execute the program
def main():
    n = int(input())
    a = list(map(int, input().split()))
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
    Sp.init(dl)
    for t in bans:
        if Sp.get(t.l, t.r) > t.val:
            print(-1)
            return
    print(ans)

if __name__ == "__main__":
    main()

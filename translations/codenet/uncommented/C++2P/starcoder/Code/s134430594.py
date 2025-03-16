
import sys

class Sp:
    LIM = 20
    N = 2e5 + 7
    mn = [[0] * N for _ in range(LIM)]
    pw = [0] * N

    def init(self, a):
        n = len(a)
        for i in range(n):
            self.mn[0][i] = a[i]
        for i in range(LIM - 1):
            for j in range(n - (1 << (i + 1)) + 1):
                self.mn[i + 1][j] = max(self.mn[i][j], self.mn[i][j + (1 << i)])
        self.pw[1] = 0
        for i in range(2, N):
            self.pw[i] = self.pw[i // 2] + 1

    def get(self, l, r):
        r += 1
        p = self.pw[r - l]
        return min(self.mn[p][l], self.mn[p][r - (1 << p)])

def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    dl = [0] * n
    for i in range(n):
        if a[i] > i:
            print(-1)
            return
        dl[i] = i - a[i]
    ans = 0
    bans = []
    for i in range(n):
        r = i
        while r + 1 < n and a[r] + 1 == a[r + 1]:
            r += 1
        ans += a[r]
        i = r
        bans.append(Ban(r - a[r], r, r - a[r]))
    Sp().init(dl)
    for t in bans:
        if Sp().get(t.l, t.r) > t.val:
            print(-1)
            return
    print(ans)

if __name__ == '__main__':
    solve()

# 
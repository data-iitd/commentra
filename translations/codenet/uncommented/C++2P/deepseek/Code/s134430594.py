import sys
import math

class Ban:
    def __init__(self, l, r, val):
        self.l = l
        self.r = r
        self.val = val

def init_sparse_table(a):
    n = len(a)
    LIM = 20
    N = 200007
    mn = [[0] * N for _ in range(LIM)]
    pw = [0] * N

    for i in range(n):
        mn[0][i] = a[i]

    for i in range(1, LIM):
        for j in range(n):
            if j + (1 << (i - 1)) < n:
                mn[i][j] = max(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))])

    pw[1] = 0
    for i in range(2, N):
        pw[i] = pw[i // 2] + 1

    return mn, pw

def get_min_sparse_table(mn, l, r):
    p = pw[r - l + 1]
    return min(mn[p][l], mn[p][r - (1 << p) + 1])

# Read input
n = int(input())
a = list(map(int, input().split()))

# Calculate dl
dl = [i - a[i] for i in range(n)]

# Check for invalid case
for i in range(n):
    if a[i] > i:
        print(-1)
        sys.exit()

# Calculate ans and bans
ans = 0
bans = []
for i in range(n):
    r = i
    while r + 1 < n and a[r] + 1 == a[r + 1]:
        r += 1
    ans += a[r]
    bans.append(Ban(r - a[r], r, r - a[r]))
    i = r

# Initialize sparse table
mn, pw = init_sparse_table(dl)

# Check bans
for t in bans:
    if get_min_sparse_table(mn, t.l, t.r) > t.val:
        print(-1)
        sys.exit()

# Print answer
print(ans)

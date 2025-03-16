import sys
from collections import defaultdict

sys_input = sys.stdin.read
input = sys_input().splitlines

class Edge:
    def __init__(self, to, pre, c):
        self.to = to
        self.pre = pre
        self.c = c

N = 10**5 + 10
e = [None] * (N << 1)
u = [0] * N
l = 0

def ins(a, b, c):
    global l
    l += 1
    e[l] = Edge(b, u[a], c)
    u[a] = l

n, m = map(int, input()[0].split())
for i in range(1, m + 1):
    a, b = map(int, input()[i].split())
    ins(a, b, 1)
    ins(b, a, 2)

ans = 0
vis = [False] * N
cnt = [0] * 3
d = [0] * N
T = 0
ok = True

def dfs(x, l):
    global T, ok
    vis[x] = True
    cnt[l] += 1
    d[x] = l
    i = u[x]
    while i:
        v = e[i].to
        ec = e[i].c
        T += 1
        if not vis[v]:
            dfs(v, (l + ec) % 3)
        elif (l + ec) % 3 != d[v]:
            ok = False
        i = e[i].pre

for i in range(1, n + 1):
    if not vis[i]:
        T = 0
        cnt = [0, 0, 0]
        ok = True
        dfs(i, 0)
        s = cnt[0] + cnt[1] + cnt[2]
        if not ok:
            ans += s * s
        else:
            if cnt[0] and cnt[1] and cnt[2]:
                ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0]
            else:
                ans += T // 2

print(ans)
# <END-OF-CODE>

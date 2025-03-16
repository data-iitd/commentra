
import sys

MAXN = 100001
n, m, Q = map(int, input().split())
a = list(map(int, input().split()))
b = [0] * MAXN
id = [0] * MAXN
vis = [False] * MAXN
cnt = [0] * MAXN

for i in range(Q - 1, -1, -1):
    if not vis[a[i]]:
        b[m] = a[i]
        vis[a[i]] = True
        m -= 1

for i in range(m, 0, -1):
    if not vis[i]:
        b[i] = i

for i in range(1, m + 1):
    id[b[i]] = i

flag = True
cnt[0] = n

for i in range(Q - 1, -1, -1):
    t = id[a[i]]
    if cnt[t - 1] > 0:
        cnt[t - 1] -= 1
        cnt[t] += 1
        vis[t] = True
    else:
        if not vis[t]:
            flag = False
            break

l = 0
while cnt[l] == 0:
    l += 1

for i in range(l + 1, m):
    if b[i] < b[i + 1]:
        flag = False
        break

print("Yes" if flag else "No")


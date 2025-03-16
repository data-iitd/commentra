
import sys

MAXN = 100001
n, m, Q = map(int, input().split())
a = list(map(int, input().split()))
b = [0] * MAXN
id = [0] * MAXN
vis = [False] * MAXN
cnt = [0] * MAXN

for k, j in enumerate(reversed(a), start=1):
    if not vis[j]:
        b[k] = j
        vis[j] = True

for j, i in enumerate(reversed(range(1, m + 1)), start=m):
    if not vis[i]:
        b[j] = i

for i in range(1, m + 1):
    id[b[i]] = i

cnt[0] = n
flag = True
for i in reversed(a):
    t = id[i]
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
    flag &= b[i] < b[i + 1]

print("Yes" if flag else "No")


MAXN = 100010

n, m, Q = map(int, input().split())
a = list(map(int, input().split()))

b = []
vis = [False] * (m + 1)

for i in range(Q):
    if not vis[a[i]]:
        b.append(a[i])
        vis[a[i]] = True

for i in range(1, m + 1):
    if not vis[i]:
        b.append(i)

id = {b[i]: i for i in range(len(b))}

flag = True
cnt = [n] * (m + 1)

for i in range(Q - 1, -1, -1):
    t = id[a[i]]
    if cnt[t - 1] > 0:
        cnt[t - 1] -= 1
        cnt[t] += 1
        vis[t] = True
    elif not vis[t]:
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

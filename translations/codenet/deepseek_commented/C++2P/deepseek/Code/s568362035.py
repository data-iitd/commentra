MAXN = 10**5 + 10

n, m, Q = 0, 0, 0
a = [0] * MAXN
b = [0] * MAXN
id = [0] * MAXN
vis = [False] * MAXN
cnt = [0] * MAXN

n, m = map(int, input().split())
Q = int(input())
a[1:Q+1] = map(int, input().split())

k = 0
for j in range(Q, 0, -1):
    if not vis[a[j]]:
        b[k+1] = a[j]
        vis[a[j]] = True
        k += 1

for j in range(m, 0, -1):
    if not vis[j]:
        b[k+1] = j
        k += 1

for i in range(1, m+1):
    id[b[i]] = i

flag = True
cnt[0] = n
for i in range(Q, 0, -1):
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
    if b[i] >= b[i + 1]:
        flag = False
        break

print("Yes" if flag else "No")

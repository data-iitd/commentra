n, m, Q = map(int, input().split())
a = [0] * (Q + 1)
for i in range(1, Q + 1):
    a[i] = int(input())
b = [0] * (m + 1)
vis = [False] * (m + 1)
cnt = [0] * (m + 1)
k = 0
for j in range(Q, 0, -1):
    if not vis[a[j]]:
        b[k + 1] = a[j]
        vis[a[j]] = True
        k += 1
for j in range(m, 0, -1):
    if not vis[j]:
        b[j] = j
for i in range(1, m + 1):
    id[b[i]] = i
flag = True
cnt[0] = n
for i in range(Q, 0, -1):
    t = id[a[i]]
    if cnt[t - 1] > 0:
        cnt[t - 1] -= 1
        cnt[t] += 1
        vis[t] = True
    else:
        flag = False
        break
l = 0
while cnt[l] == 0:
    l += 1
for i in range(l + 1, m):
    flag &= b[i] < b[i + 1]
print("Yes" if flag else "No")



n, m = map(int, input().split())
Q = int(input())
a = list(map(int, input().split()))

vis = [False] * (m + 1)
b = []
for i in range(Q - 1, -1, -1):
    if not vis[a[i]]:
        b.append(a[i])
        vis[a[i]] = True

for i in range(m, 0, -1):
    if not vis[i]:
        b.append(i)

id = [0] * (m + 1)
for i in range(m):
    id[b[i]] = i

cnt = [0] * (m + 1)
cnt[0] = n
for i in range(Q - 1, -1, -1):
    t = id[a[i]]
    if cnt[t - 1] > 0:
        cnt[t - 1] -= 1
        cnt[t] += 1
        vis[t] = True
    else:
        if not vis[t]:
            print("No")
            exit(0)

l = 0
while cnt[l] == 0:
    l += 1

for i in range(l + 1, m):
    if b[i] < b[i + 1]:
        print("No")
        exit(0)

print("Yes")

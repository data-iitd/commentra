n, m, Q = map(int, input().split())
a = [0] * (Q + 1)
for i in range(1, Q + 1):
	a[i] = int(input())
b = [0] * (m + 1)
id = [0] * (m + 1)
vis = [False] * (m + 1)
cnt = [0] * (m + 1)

for i in range(1, Q + 1):
	if not vis[a[i]]:
		b[1] = a[i]
		vis[a[i]] = True
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
for i in range(l, m):
	if cnt[i] == 0:
		l = i + 1
for i in range(l, m):
	flag &= b[i] < b[i + 1]

print("Yes" if flag else "No")


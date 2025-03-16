n, m, Q = map(int, raw_input().split())
a = map(int, raw_input().split())
b = [0] * (m + 1)
id = [0] * (m + 1)
vis = [False] * (m + 1)
cnt = [0] * (m + 1)

for i in range(1, Q + 1):
	if not vis[a[i]]:
		b[k] = a[i]
		vis[a[i]] = True

for j in range(m, 0, -1):
	if not vis[j]:
		b[j] = i

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
for i in range(l, m + 1):
	if cnt[i] == 0:
		l = i
		break

for i in range(l + 1, m + 1):
	flag &= b[i] < b[i + 1]

print "Yes" if flag else "No"
#
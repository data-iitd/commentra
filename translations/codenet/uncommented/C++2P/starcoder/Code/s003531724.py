
n, m = map(int, raw_input().split())
e = [0] * (2 * m + 10)
u = [0] * (n + 10)
cnt = [0] * 3
d = [0] * (n + 10)
vis = [False] * (n + 10)
l = 0
T = 0

def ins(a, b, c):
	global l
	e[l] = (b, u[a], c)
	u[a] = l
	l += 1

for i in range(1, m + 1):
	a, b = map(int, raw_input().split())
	ins(a, b, 1)
	ins(b, a, 2)

def dfs(x, l):
	vis[x] = True
	cnt[l] += 1
	d[x] = l
	for i in range(u[x]):
		T += 1
		if not vis[v]: dfs(v, (l + ec) % 3)
		else:
			if (l + ec) % 3!= d[v]:
				ok = False

ans = 0
for i in range(1, n + 1):
	if not vis[i]:
		T = 0
		for j in range(3):
			cnt[j] = 0
		ok = True
		dfs(i, 0)
		s = cnt[0] + cnt[1] + cnt[2]
		if not ok:
			ans += s * s
		else:
			if cnt[0] and cnt[1] and cnt[2]:
				ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0]
			else:
				ans += T / 2

print ans


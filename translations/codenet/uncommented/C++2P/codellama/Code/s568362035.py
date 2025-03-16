#include <cstdio>

const int MAXN = 1E5 + 10;

n, m, Q = map(int, input().split())
a = list(map(int, input().split()))
b = [0] * (MAXN + 10)
id = [0] * (MAXN + 10)
vis = [False] * (MAXN + 10)
cnt = [0] * (MAXN + 10)

def main():
	for i in range(1, Q + 1):
		if not vis[a[i]]:
			b[i] = a[i]
			vis[a[i]] = True
	for j in range(m, 0, -1):
		if not vis[j]:
			b[j] = j
			vis[j] = True
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
		elif not vis[t]:
			flag = False
			break
	l = 0
	while cnt[l] == 0:
		l += 1
	for i in range(l + 1, m):
		flag &= b[i] < b[i + 1]
	print("Yes" if flag else "No")



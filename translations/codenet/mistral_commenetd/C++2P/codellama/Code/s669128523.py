/*
 depth first search algorithm implementation in Python
 not lying in the stack
 */
import sys

def dfs_visit(u):
	global color, d, f, tt, n, M
	color[u] = 1
	d[u] = tt
	tt += 1
	for v in range(n):
		if M[u][v] == 0:
			continue
		if color[v] == 0:
			dfs_visit(v)
	color[u] = 2
	f[u] = tt
	tt += 1

def dfs():
	global color, d, f, tt, n, M
	for i in range(n):
		color[i] = 0
	tt = 0
	for u in range(n):
		if color[u] == 0:
			dfs_visit(u)

	for i in range(n):
		print(i + 1, d[i], f[i])

n = int(sys.stdin.readline())
M = [[0] * n for i in range(n)]
color = [0] * n
d = [0] * n
f = [0] * n

for i in range(n):
	u, k = map(int, sys.stdin.readline().split())
	u -= 1
	for j in range(k):
		v = int(sys.stdin.readline()) - 1
		M[u][v] = 1

dfs()


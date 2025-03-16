
B = 13131
N = 500000 + 7

n = int(input())
s = input()

f = [0] * (n + 1)
g = [0] * (n + 1)

map = {}
cnt = 0

for i in range(1, n + 1):
	if s[i] == '+' or s[i] == '-':
		f[i] = f[i - 1] + (s[i] == '+' and 1 or -1) * pow(B, g[i] = g[i - 1])
	else:
		f[i] = f[i - 1]
		g[i] = g[i - 1] + (s[i] == '<' and -1 or 1)

for i in range(n, 0, -1):
	map[f[i]] = map.get(f[i], 0) + 1
	cnt += map.get(f[n] * pow(B, g[i - 1]) + f[i - 1], 0)

print(cnt)


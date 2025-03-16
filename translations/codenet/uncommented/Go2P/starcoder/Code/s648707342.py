n = int(input())
as = []
for i in range(n):
	x, l = map(int, input().split())
	as.append((x-l, x+l))

as.sort()

ans = 1
r = as[0][1]
for i in range(1, n):
	if as[i][0] >= r:
		ans += 1
		r = as[i][1]

print(ans)


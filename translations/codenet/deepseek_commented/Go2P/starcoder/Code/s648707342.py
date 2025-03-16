n = int(input())

class arm:
	def __init__(self, x, l):
		self.l = x - l
		self.r = x + l

as = []
for i in range(n):
	x, l = map(int, input().split())
	as.append(arm(x, l))

as.sort(key=lambda x: x.r)

ans = 1
r = as[0].r
for i in range(1, n):
	if as[i].l >= r:
		ans += 1
		r = as[i].r

print(ans)


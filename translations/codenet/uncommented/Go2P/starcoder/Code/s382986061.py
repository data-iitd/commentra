N, K = map(int, input().split())
as = {}
for i in range(1, N+1):
	as[i] = 0
for i in range(K):
	d = int(input())
	for j in range(d):
		a = int(input())
		as[a] += 1
ans = 0
for _, v in as.items():
	if v == 0:
		ans += 1
print(ans)


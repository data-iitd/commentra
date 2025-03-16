n, m = int(input()), int(input())
a = [int(input()) for _ in range(m)]
sum = 0
for i in range(m):
	sum += a[i]
if sum > n:
	print(-1)
else:
	print(n - sum)


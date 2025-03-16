def main():
	n = int(input())
	a = list(map(int, input().split()))

	ans = 0
	for i in range(n):
		l, r = i, i+1
		while r+1 < n and (a[r]-a[l])*(a[r+1]-a[r]) >= 0:
			r += 1
		ans += 1
		i = r
	print(ans)

main()


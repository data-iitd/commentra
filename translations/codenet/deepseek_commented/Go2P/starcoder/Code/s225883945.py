n, k = int(input()), int(input())
a = [0] + list(map(int, input().split()))

sum, ans = k, 1
while sum < n:
	sum = sum - 1 + k
	ans += 1

print(ans)
# 
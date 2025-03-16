n = int(input())

arrA = list(map(int, input().split()))

cumSumA = [0]
for i, a in enumerate(arrA):
	cumSumA.append(cumSumA[i] + a)

ans = float('inf')
for i in range(1, n):
	if abs(cumSumA[n]-(cumSumA[i]*2)) < ans:
		ans = abs(cumSumA[n]-(cumSumA[i]*2))

print(int(ans))


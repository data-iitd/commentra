

n = int(input())
arrA = list(map(int, input().split()))

cumSumA = [0] * (n + 1)
cumSumA[0] = 0
for i in range(n):
    cumSumA[i + 1] = cumSumA[i] + arrA[i]

ans = float('inf')
for i in range(1, n):
    temp = float(cumSumA[n]) - float(cumSumA[i]) * 2
    if abs(temp) < ans:
        ans = temp

print(int(ans))


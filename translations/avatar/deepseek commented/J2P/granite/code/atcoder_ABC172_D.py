

n = int(input())
ans = 0

for i in range(1, n + 1):
    term = n // i
    sum = term * (term + 1) // 2
    ans += i * sum

print(ans)

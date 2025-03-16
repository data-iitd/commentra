n, k = map(int, input().split())
a = list(map(int, input().split()))

sum = k
ans = 1
for sum < n:
    sum = sum - 1 + k
    ans += 1
print(ans)


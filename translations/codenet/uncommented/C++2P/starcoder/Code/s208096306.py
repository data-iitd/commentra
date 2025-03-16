
n = int(input())

ans = int(input())

for i in range(1, n):
    a = int(input())
    ans = gcd(ans, a)

print(ans)

# 
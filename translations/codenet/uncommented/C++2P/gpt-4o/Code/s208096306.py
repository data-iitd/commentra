def gcd(a, b):
    if a < b:
        a, b = b, a
    while (r := a % b) > 0:
        a, b = b, r
    return b

n = int(input())
ans = int(input())

for _ in range(1, n):
    a = int(input())
    ans = gcd(ans, a)

print(ans)

# <END-OF-CODE>

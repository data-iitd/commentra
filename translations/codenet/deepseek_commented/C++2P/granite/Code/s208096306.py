
import sys

def gcd(a, b):
    if a < b:
        a, b = b, a
    r = a % b
    while r > 0:
        a = b
        b = r
        r = a % b
    return b

n = int(input())
ans = int(input())

for i in range(1, n):
    a = int(input())
    ans = gcd(ans, a)

print(ans)


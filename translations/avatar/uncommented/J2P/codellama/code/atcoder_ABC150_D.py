
import sys

n, m = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))

lcd = 1
for i in range(n):
    gcd = getGCD(lcd, a[i])
    lcd = lcd * a[i] // gcd
    if lcd > m:
        print(0)
        sys.exit(0)

for i in range(n):
    if (lcd // a[i]) % 2 == 0:
        print(0)
        sys.exit(0)

print((m // lcd + 1) // 2)

def getGCD(a, b):
    if b == 0:
        return a
    else:
        return getGCD(b, a % b)


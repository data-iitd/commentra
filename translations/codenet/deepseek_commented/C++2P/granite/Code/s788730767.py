
import math

def nPr(n, r):
    res = 1
    for i in range(r):
        res *= (n - i)
    return res

def nCr(n, r):
    res = 1
    for i in range(r):
        res *= (n - i)
        res /= (i+1)
    return int(res)

n = int(input())
p = int(input())
a = list(map(int, input().split()))

b = 0
c = 0
for i in range(n):
    if a[i] % 2 == 0:
        b += 1
    else:
        c += 1

bsum = 2**b
csum = 0

if p == 0:
    for i in range(c+1):
        if i % 2 == 0:
            csum += nCr(c, i)
else:
    for i in range(c+1):
        if i % 2 == 1:
            csum += nCr(c, i)

ans = bsum * csum
print(ans)


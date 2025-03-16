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
        res /= (i + 1)
    return int(res)

n, p = map(int, input().split())
a = list(map(int, input().split()))

b = sum(1 for x in a if x % 2 == 0)
c = n - b

bsum = 2 ** b
csum = 0

if p == 0:
    for i in range(c + 1):
        if i % 2 == 0:
            csum += nCr(c, i)
else:
    for i in range(c + 1):
        if i % 2 == 1:
            csum += nCr(c, i)

ans = bsum * csum
print(ans)

# <END-OF-CODE>

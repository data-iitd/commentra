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
    return res

# Read input
n, p = map(int, input().split())
a = list(map(int, input().split()))

# Count even and odd numbers
b = sum(1 for x in a if x % 2 == 0)
c = n - b

# Calculate the number of subsets with even and odd numbers
bsum = 2 ** b
csum = 0

if p == 0:
    # Sum combinations where the number of elements is even
    for i in range(c + 1):
        if i % 2 == 0:
            csum += nCr(c, i)
else:
    # Sum combinations where the number of elements is odd
    for i in range(c + 1):
        if i % 2 == 1:
            csum += nCr(c, i)

# Calculate the final answer as the product of bsum and csum
ans = bsum * csum
print(int(ans))

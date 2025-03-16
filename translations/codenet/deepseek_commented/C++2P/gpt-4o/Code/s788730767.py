def nPr(n, r):
    res = 1
    for i in range(r):
        res *= (n - i)
    return res

def nCr(n, r):
    res = 1.0
    for i in range(r):
        res *= (n - i)
        res /= (i + 1)
    return int(res)

n, p = map(int, input().split())
a = list(map(int, input().split()))
b = 0
c = 0

for num in a:
    if num % 2 == 0:
        b += 1
    else:
        c += 1

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
print(ans)

# <END-OF-CODE>

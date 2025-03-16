
n = int(input())
m = n
n -= 1
for i in range(n-1):
    m *= n
    n -= 1
print(m)


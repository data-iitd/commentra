# <START-OF-CODE>

n = int(input())

m = 100000000
M = -100000000
c = 0

for i in range(1, n+1):
    a = int(input())
    if a > M:
        M = a
    if a < m:
        m = a
    c += a

print(m, M, c)

# 
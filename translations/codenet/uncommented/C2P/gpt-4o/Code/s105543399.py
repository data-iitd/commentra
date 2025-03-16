n = int(input())
c = 0
m = 100000000
M = -100000000

for i in range(1, n + 1):
    a = int(input())
    if a > M:
        M = a
    if a < m:
        m = a
    c += a

print(m, M, c)

# <END-OF-CODE>

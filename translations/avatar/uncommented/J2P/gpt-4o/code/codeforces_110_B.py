n = int(input())
p = 97
c = [''] * n

for i in range(4):
    for j in range(i, n, 4):
        c[j] = chr(p)
        p += 1

for i in range(n):
    print(c[i], end='')

# <END-OF-CODE>

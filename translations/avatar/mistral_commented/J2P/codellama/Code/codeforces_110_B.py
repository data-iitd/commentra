
import sys

n = int(sys.stdin.readline())
c = [0] * n
p = 'a'

for i in range(4):
    for j in range(i, n, 4):
        c[j] = p
        p = chr(ord(p) + 1)

for i in range(n):
    print(c[i], end='')

# 
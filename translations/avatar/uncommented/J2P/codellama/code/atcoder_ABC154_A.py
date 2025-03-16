import sys

a, b = sys.stdin.readline().split()
a, b = int(a), int(b)
u = sys.stdin.readline().strip()

if u == str[0]:
    print(a - 1, b)
else:
    print(a, b - 1)


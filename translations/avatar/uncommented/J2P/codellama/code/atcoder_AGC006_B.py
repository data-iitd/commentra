
import sys

n, x = map(int, sys.stdin.readline().split())

if x == 1 or x == n * 2 - 1:
    print("No")
    sys.exit()

print("Yes")

for i in range(x + n - 1, x + n + n * 2 - 2):
    print((i % (n * 2 - 1) + 1))

# 
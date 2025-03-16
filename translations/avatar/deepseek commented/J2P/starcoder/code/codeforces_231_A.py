
import sys

t = int(input())
count = 0

while t > 0:
    a, b, c = map(int, input().split())
    if (a == 1 or b == 1 or c == 1) and (a == 1 or b == 1 or c == 1 or a == 1 and b == 1 and c == 1):
        count += 1
    t -= 1

print(count)

# 

import sys

def sub(a, b):
    min = min(a, b)
    max = max(a, b)
    result = 0
    while min > 0:
        result += max / min
        max = max % min
        min, max = min % max, max % min
    return result

n = int(sys.stdin.readline())
for i in range(n):
    a, b = map(int, sys.stdin.readline().split())
    print(sub(a, b))

# 
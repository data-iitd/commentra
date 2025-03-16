
import sys
from bisect import bisect_left

def out(*args):
    print(*args)

def getInt():
    return int(input())

def getString():
    return input().strip()

def max(a, b):
    return a if a > b else b

def min(a, b):
    return a if a < b else b

def asub(a, b):
    return a - b if a > b else b - a

def abs(a):
    return a if a >= 0 else -a

def lowerBound(a, x):
    idx = bisect_left(a, x)
    return idx

def upperBound(a, x):
    idx = bisect_left(a, x + 1)
    return idx

N, M = getInt(), getInt()
s = []
for _ in range(N):
    a, b = getInt(), getInt()
    s.append((a, b))
s.sort(key=lambda x: x[0])

total = 0
for a, b in s:
    n = min(b, M)
    total += n * a
    M -= n
    if M == 0:
        break
out(total)


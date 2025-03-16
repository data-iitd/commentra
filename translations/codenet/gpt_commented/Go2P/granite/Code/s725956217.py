
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
    i = bisect_left(a, x)
    return i

def upperBound(a, x):
    i = bisect_left(a, x + 1)
    return i

class Shop:
    def __init__(self, a, b):
        self.a = a
        self.b = b

class Datas(list):
    def __lt__(self, other):
        return self.a < other.a

N, M = getInt(), getInt()
s = Datas()
for _ in range(N):
    a, b = getInt(), getInt()
    s.append(Shop(a, b))
s.sort()

total = 0
for e in s:
    n = min(e.b, M)
    total += n * e.a
    M -= n
    if M == 0:
        break
out(total)


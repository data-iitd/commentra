
import sys
from collections import deque

# I/O
def next_str():
    return input()

def next_int():
    return int(next_str())

def next_float():
    return float(next_str())

def next_rune_slice():
    return list(next_str())

def next_int_slice(n):
    return [next_int() for _ in range(n)]

def next_float_slice(n):
    return [next_float() for _ in range(n)]

# Arithmetic
def max(*nums):
    return max(nums)

def min(*nums):
    return min(nums)

def abs(x):
    return abs(x)

def pow(x, y):
    return x ** y

def ceil(a, b):
    return -(-a // b)

# Sort
class RuneSlice(list):
    def __lt__(self, other):
        return self[0] < other[0]

# Main
MOD = 1000000007
INF = 1 << 60

class Mon:
    def __init__(self, x, h):
        self.x = x
        self.h = h

class Queue(deque):
    def push(self, v):
        self.append(v)

    def first(self):
        return self[0]

    def pop(self):
        res = self[0]
        self.popleft()
        return res

    def isEmpty(self):
        return len(self) == 0

N, D, A = next_int(), next_int(), next_int()
M = [Mon(next_int(), next_int()) for _ in range(N)]
M.sort(key=lambda m: m.x)
q = Queue()
ans = 0
total = 0
for m in M:
    while not q.isEmpty() and q.first().x < m.x:
        total -= q.pop().h
    if total < m.h:
        m.h -= total
        count = ceil(m.h, A)
        ans += count
        damage = count * A
        q.push(Mon(m.x + 2 * D, damage))
        total += damage

print(ans)


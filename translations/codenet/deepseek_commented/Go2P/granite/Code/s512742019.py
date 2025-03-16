
import sys
from collections import deque

MOD = 1000000007
INF = 1 << 60

class Mon:
    def __init__(self, x, h):
        self.x = x
        self.h = h

class Queue:
    def __init__(self):
        self.arr = deque()

    def push(self, v):
        self.arr.append(v)

    def first(self):
        return self.arr[0]

    def pop(self):
        res = self.arr[0]
        self.arr.popleft()
        return res

    def isEmpty(self):
        return len(self.arr) == 0

def max(nums):
    m = nums[0]
    for i in nums:
        if m < i:
            m = i
    return m

def min(nums):
    m = nums[0]
    for i in nums:
        if m > i:
            m = i
    return m

def abs(x):
    if x > 0:
        return x
    return -x

def pow(x, y):
    res = 1
    for i in range(y):
        res *= x
    return res

def ceil(a, b):
    if a % b == 0:
        return a // b
    else:
        return a // b + 1

N, D, A = map(int, input().split())
M = [Mon(int(x), int(y)) for x, y in zip(input().split(), input().split())]
M.sort(key=lambda x: x.x)

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


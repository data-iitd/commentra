import sys
import math
from collections import deque

# I/O
class Scanner:
    def __init__(self):
        self.sc = sys.stdin.read().split()
        self.index = 0

    def next_str(self):
        res = self.sc[self.index]
        self.index += 1
        return res

    def next_int(self):
        return int(self.next_str())

    def next_float(self):
        return float(self.next_str())

    def next_int_slice(self, n):
        return [self.next_int() for _ in range(n)]

# Arithmetic
def max_value(*nums):
    return max(nums)

def min_value(*nums):
    return min(nums)

def abs_value(x):
    return abs(x)

def pow_value(x, y):
    return x ** y

def ceil_div(a, b):
    return -(-a // b)

# Main
MOD = int(1e+9) + 7
INF = 1 << 60

class Mon:
    def __init__(self, x, h):
        self.x = x
        self.h = h

def main():
    sc = Scanner()
    N = sc.next_int()
    D = sc.next_int()
    A = sc.next_int()
    M = [Mon(sc.next_int(), sc.next_int()) for _ in range(N)]
    M.sort(key=lambda m: m.x)

    q = deque()
    ans = 0
    total = 0

    for m in M:
        while q and q[0][0] < m.x:
            total -= q.popleft()[1]

        if total < m.h:
            m.h -= total
            count = ceil_div(m.h, A)
            ans += count
            damage = count * A
            q.append((m.x + 2 * D, damage))
            total += damage

    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

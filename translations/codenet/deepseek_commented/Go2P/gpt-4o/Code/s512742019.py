import sys
import math
from collections import deque

class Scanner:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next_str(self):
        res = self.data[self.index]
        self.index += 1
        return res

    def next_int(self):
        return int(self.next_str())

    def next_float(self):
        return float(self.next_str())

    def next_int_slice(self, n):
        return [self.next_int() for _ in range(n)]

class Mon:
    def __init__(self, x, h):
        self.x = x
        self.h = h

def ceil(a, b):
    return (a + b - 1) // b

def main():
    sc = Scanner()
    N = sc.next_int()
    D = sc.next_int()
    A = sc.next_int()
    
    M = []
    for _ in range(N):
        x = sc.next_int()
        h = sc.next_int()
        M.append(Mon(x, h))
    
    M.sort(key=lambda m: m.x)
    
    q = deque()
    ans = 0
    total = 0
    
    for m in M:
        while q and q[0][0] < m.x:
            total -= q.popleft()[1]
        
        if total < m.h:
            m.h -= total
            count = ceil(m.h, A)
            ans += count
            damage = count * A
            q.append((m.x + 2 * D, damage))
            total += damage
    
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

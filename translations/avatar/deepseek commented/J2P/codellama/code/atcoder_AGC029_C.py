
import sys
import collections

def solve():
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    s = collections.defaultdict(int)
    ng = 0
    ok = n
    while ok - ng > 1:
        k = (ng + ok) // 2
        if is_possible(k):
            ok = k
        else:
            ng = k
    print(ok)

def is_possible(k):
    s.clear()
    current = 0
    for ai in a:
        if ai <= current:
            if k == 1:
                return False
            while s and s[-1][0] >= ai:
                s.pop()
            p = ai - 1
            while True:
                if p < 0:
                    return False
                sp = s[p] + 1
                s[p] = sp
                if sp == k:
                    s.pop(p)
                    p -= 1
                else:
                    break
        current = ai
    return True

solve()

# 
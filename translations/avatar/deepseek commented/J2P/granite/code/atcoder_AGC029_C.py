

import sys
import io
import bisect

def main():
    n = int(input())
    a = list(map(int, input().split()))
    s = []
    ng = 0
    ok = n
    while ok - ng > 1:
        k = (ng + ok) // 2
        if is_possible(k, a, s):
            ok = k
        else:
            ng = k
    print(ok)

def is_possible(k, a, s):
    s.clear()
    current = 0
    for ai in a:
        if ai <= current:
            if k == 1:
                return False
            while s and s[-1] >= ai:
                s.pop()
            p = ai - 1
            while True:
                if p < 0:
                    return False
                sp = s.count(p) + 1
                bisect.insort(s, p)
                if sp == k:
                    s.remove(p)
                    p -= 1
                else:
                    break
        current = ai
    return True

if __name__ == "__main__":
    main()


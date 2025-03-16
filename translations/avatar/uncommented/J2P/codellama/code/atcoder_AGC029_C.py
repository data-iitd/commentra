
import sys
import collections

def main():
    n = int(sys.stdin.readline().strip())
    a = list(map(int, sys.stdin.readline().strip().split()))
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
            while not s.is_empty():
                p = s.pop()
                sp = s[p] + 1
                s[p] = sp
                if sp == k:
                    s.pop(p)
                else:
                    break
        current = ai
    return True

if __name__ == '__main__':
    main()


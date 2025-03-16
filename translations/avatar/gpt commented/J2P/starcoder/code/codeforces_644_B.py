
# <START-OF-CODE>

import sys

def main():
    n, b = map(int, sys.stdin.readline().split())
    ans = []
    q = []
    for i in range(n):
        t, d = map(int, sys.stdin.readline().split())
        while q and q[0] <= t:
            q.pop(0)
        if len(q) <= b:
            ans.append(q[0] if q else t)
            q.append(ans[-1] + d)
        else:
            ans.append(-1)
    print(' '.join(map(str, ans)))

if __name__ == '__main__':
    main()

# 
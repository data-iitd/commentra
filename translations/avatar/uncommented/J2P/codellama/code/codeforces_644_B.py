import sys
import math

def main():
    n, b = map(int, sys.stdin.readline().split())
    ans = [0] * n
    q = []
    for i in range(n):
        t, d = map(int, sys.stdin.readline().split())
        while q and q[0] <= t:
            q.pop(0)
        if len(q) <= b:
            ans[i] = (q[0] if q else t) + d
            q.append(ans[i])
        else:
            ans[i] = -1
    print(' '.join(map(str, ans)))

if __name__ == '__main__':
    main()


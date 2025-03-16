
import sys
import math
import bisect

MOD = 100000007
DX = [-1, 0, 1, 0]
DY = [0, -1, 0, 1]

def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    A.sort()

    ok = 10 ** 18 + 1
    ng = -10 ** 18 - 1
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if is_ok(mid, A, K):
            ok = mid
        else:
            ng = mid
    print(ok)

def is_ok(x, A, K):
    cnt = 0
    for a in A:
        if a >= 0:
            cnt += bisect.bisect_right(A, x // a - 1)
        else:
            cnt += N - bisect.bisect_left(A, x // a)
        if a * a < x:
            cnt -= 1
    return cnt // 2 >= K

if __name__ == '__main__':
    main()


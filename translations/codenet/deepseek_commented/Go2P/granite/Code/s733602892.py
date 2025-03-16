
import sys
from bisect import bisect_left

def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    F = list(map(int, input().split()))
    A.sort()
    F.sort(reverse=True)
    scores = [A[i] * F[i] for i in range(N)]
    scores.sort(reverse=True)
    ok = scores[0]
    ng = -1
    while ok - ng > 1:
        mid = (ok + ng) // 2
        k = K
        for i in range(N):
            if scores[i] > mid:
                k -= A[i] - mid // F[i]
            if k < 0:
                break
        if k >= 0:
            ok = mid
        else:
            ng = mid
    print(ok)

if __name__ == "__main__":
    main()


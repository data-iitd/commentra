
import sys
from bisect import bisect_left

def main():
    N, C, K = map(int, input().split())
    t = list(map(int, input().split()))
    t.sort()
    ans = 1
    cnt = 1
    end = t[0] + K
    for i in range(1, N):
        if cnt < C and t[i] <= end:
            cnt += 1
        else:
            cnt = 1
            end = t[i] + K
            ans += 1
    print(ans)

if __name__ == "__main__":
    main()


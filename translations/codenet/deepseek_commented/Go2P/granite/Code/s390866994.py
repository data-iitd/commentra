
import sys
from operator import itemgetter

def main():
    N, C, K = map(int, input().split())
    t = list(map(int, input().split()))
    t.sort(key=itemgetter(1))
    ans = 1
    cnt = 1
    end = t[0][1] + K
    for i in range(1, N):
        if cnt < C and t[i][1] <= end:
            cnt += 1
        else:
            cnt = 1
            end = t[i][1] + K
            ans += 1
    print(ans)

if __name__ == "__main__":
    main()




import sys
from bisect import bisect_left

def main():
    x = list(map(int, input().split()))
    max_x = max(x)
    k = int(input())
    a = [[] for _ in range(3)]
    for i in range(3):
        a[i] = list(map(int, input().split()))
        a[i].sort()
    ans = []
    for i in range(x[0]):
        for j in range(x[1]):
            for m in range(x[2]):
                if (i + 1) * (j + 1) * (m + 1) <= k:
                    tmp = a[0][x[0] - i - 1] + a[1][x[1] - j - 1] + a[2][x[2] - m - 1]
                    ans.append(tmp)
    ans.sort()
    for i in range(k):
        print(ans[max_x * max_x * max_x - i - 1])

if __name__ == "__main__":
    main()


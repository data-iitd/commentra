

import sys
from bisect import bisect_left

def main():
    x = list(map(int, input().split()))
    max_x = max(x)
    k = int(input())
    a = [[] for _ in range(3)]

    for i in range(3):
        for _ in range(x[i]):
            a[i].append(int(input()))
        a[i].sort(reverse=True)

    ans = []

    for i in range(x[0]):
        for j in range(x[1]):
            for m in range(x[2]):
                if (i + 1) * (j + 1) * (m + 1) <= k:
                    ans.append(a[0][i] + a[1][j] + a[2][m])

    ans.sort()

    for i in range(k):
        print(ans[-i - 1])

if __name__ == "__main__":
    main()


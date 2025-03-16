
import sys
import math
import bisect

def main():
    x = [int(x) for x in sys.stdin.readline().split()]
    max_x = max(x)
    k = int(sys.stdin.readline())
    a = [[] for _ in range(3)]
    for i in range(3):
        a[i] = [int(x) for x in sys.stdin.readline().split()]
        a[i].sort(reverse=True)
    ans = []
    for i in range(x[0]):
        for j in range(x[1]):
            for m in range(x[2]):
                if (i + 1) * (j + 1) * (m + 1) <= k:
                    tmp = a[0][i] + a[1][j] + a[2][m]
                    ans.append(tmp)
    ans.sort(reverse=True)
    for i in range(k):
        print(ans[i])

if __name__ == "__main__":
    main()


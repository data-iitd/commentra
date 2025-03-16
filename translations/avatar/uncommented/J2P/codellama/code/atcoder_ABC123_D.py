import sys
import math

def main():
    sc = sys.stdin
    x = [0] * 3
    max = 0
    for i in range(3):
        x[i] = int(sc.readline().strip())
        max = max(max, x[i])
    k = int(sc.readline().strip())
    a = [[0] * 3 for i in range(3)]
    for i in range(3):
        for j in range(x[i]):
            a[i][j] = int(sc.readline().strip())
        a[i].sort()
    sc.close()
    ans = []
    for i in range(x[0]):
        for j in range(x[1]):
            for m in range(x[2]):
                if (i + 1) * (j + 1) * (m + 1) <= k:
                    tmp = a[0][x[0] - i - 1] + a[1][x[1] - j - 1] + a[2][x[2] - m - 1]
                    ans.append(tmp)
    ans.sort()
    n = len(ans)
    for i in range(k):
        print(ans[n - i - 1])

if __name__ == "__main__":
    main()


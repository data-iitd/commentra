import sys
import math

def main():
    n = int(sys.stdin.readline())
    a = [int(x) for x in sys.stdin.readline().split()]
    dp = [0] * (n + 1)
    for i in range(n - 1, -1, -1):
        dp[i] = max(dp[i + 1], a[i])
    for i in range(n):
        if a[i] > dp[i + 1]:
            print(0, end=' ')
        else:
            print(dp[i + 1] - a[i] + 1, end=' ')
    print()

if __name__ == '__main__':
    main()


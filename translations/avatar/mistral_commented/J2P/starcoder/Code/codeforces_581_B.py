
import sys

def main():
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    a = data[1:(n + 1)]
    dp = [-1] * (n + 1)
    dp[n - 1] = a[n - 1]
    for i in range(n - 1, -1, -1):
        dp[i] = max(dp[i + 1], a[i])
    for i in range(n):
        if a[i] > dp[i + 1]:
            print(0, end=' ')
        else:
            print((dp[i + 1] - a[i] + 1), end=' ')
    print()

if __name__ == '__main__':
    main()


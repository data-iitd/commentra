

import sys

def main():
    n = int(input())
    maxn = 4010
    a, b, c = map(int, input().split())
    arr = [a, b, c]
    dp = [0] * maxn
    for i in range(3):
        for j in range(arr[i], maxn):
            dp[j] = max(dp[j], dp[j - arr[i]] + 1)
    print(dp[n])

if __name__ == "__main__":
    main()


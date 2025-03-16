import sys
import math

def chmin(a, b):
    if a > b:
        a = b
    return a

INF = 1 << 30

def main():
    dp = [INF] * 101000
    dp[0] = 0
    # input
    N, K = map(int, sys.stdin.readline().split())
    h = list(map(int, sys.stdin.readline().split()))

    # dp
    for i in range(N):
        for j in range(1, K + 1):
            if i + j < N:  # Ensure we don't go out of bounds
                dp[i + j] = chmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]))

    # output
    print(dp[N - 1])

if __name__ == "__main__":
    main()
# <END-OF-CODE>

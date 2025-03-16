
import sys

def min(n):
    if len(n) == 0:
        raise ValueError("len == 0")
    r = n[0]
    for i in range(1, len(n)):
        if n[i] <= r:
            r = n[i]
    return r

def main():
    H, N = map(int, sys.stdin.readline().split())
    dp = [2100000000] * (H + 10001)
    amax = 0
    for i in range(N):
        A, B = map(int, sys.stdin.readline().split())
        if A >= amax:
            amax = A
        dp[A] = min(dp[A], B)
        for j in range(A + 1, H + amax + 1):
            dp[j] = min(dp[j], dp[j - A] + B)
    print(min(dp[H:H + amax + 1]))


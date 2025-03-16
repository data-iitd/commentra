
import sys
import typing
import numpy as np

def main():
    N, T = map(int, input().split())
    AB = [tuple(map(int, input().split())) for _ in range(N)]
    AB.sort(key=lambda x: x[0])
    dp = np.zeros((N + 1, T + 1), dtype=np.int32)
    for i in range(1, N + 1):
        time, value = AB[i - 1]
        for j in range(T, time - 1, -1):
            dp[i, j] = max(dp[i, j], dp[i - 1, j])
            if j - time >= 0:
                dp[i, j] = max(dp[i, j], dp[i - 1, j - time] + value)
    print(dp[N, :].max())

if __name__ == "__main__":
    main()


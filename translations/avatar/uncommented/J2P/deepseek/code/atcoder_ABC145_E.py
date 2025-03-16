import sys
import numpy as np

def main():
    input = sys.stdin.readline
    N, T = map(int, input().split())
    AB = [list(map(int, input().split())) for _ in range(N)]
    AB.sort(key=lambda x: x[0])
    
    dp = np.zeros((N + 1, 6001), dtype=int)
    
    for i in range(1, N + 1):
        for time_after_eat in range(6001):
            dp[i][time_after_eat] = max(dp[i][time_after_eat], dp[i - 1][time_after_eat])
            time = AB[i - 1][0]
            value = AB[i - 1][1]
            if 0 <= time_after_eat - time and time_after_eat - time < T:
                dp[i][time_after_eat] = max(dp[i][time_after_eat], dp[i - 1][time_after_eat - time] + value)
    
    print(np.max(dp[N]))

if __name__ == "__main__":
    main()

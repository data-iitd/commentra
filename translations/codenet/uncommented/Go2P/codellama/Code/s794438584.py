
import math

def max(lhs, rhs):
    return int(math.fmax(lhs, rhs))

def main():
    N, M = map(int, input().split())
    values = list(map(int, input().split()))
    weights = list(map(int, input().split()))
    #print(N, M)
    #print(values, weights)
    dp = [[0 for _ in range(M+1)] for _ in range(N+1)]
    for i in range(1, N+1):
        for j in range(0, M+1):
            dp[i][j] = dp[i-1][j]
            if j >= weights[i-1]:
                dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i-1]]+values[i-1])
    print(dp[N][M])


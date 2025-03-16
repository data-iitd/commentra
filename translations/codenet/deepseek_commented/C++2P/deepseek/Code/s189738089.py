def chmin(a, b):
    if a > b:
        a = b
    return a

INF = 2**30

def main():
    # Initialization of the dp array
    dp = [INF] * 101000
    dp[0] = 0
    # input
    N, K = map(int, input().split())
    h = list(map(int, input().split()))

    # Dynamic Programming Loop
    for i in range(N):
        for j in range(1, K + 1):
            if i + j < N:
                dp[i + j] = chmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]))

    # Output
    print(dp[N - 1])

main()

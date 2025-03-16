def chmin(a, b):
    if a > b:
        a = b
    return a

INF = 2**30

def main():
    # Initialize a dp list to store the minimum cost to reach each step
    dp = [INF] * 101000
    dp[0] = 0  # Base case: cost to reach the first step is 0

    # Input the number of steps (N) and the maximum jump distance (K)
    N, K = map(int, input().split())
    h = list(map(int, input().split()))  # List to store the heights of the steps

    # Dynamic programming to calculate the minimum cost to reach each step
    for i in range(N):
        # Check possible jumps from the current step
        for j in range(1, K + 1):
            if i + j < N:
                # Update the minimum cost to reach step i + j
                dp[i + j] = chmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]))

    # Output the minimum cost to reach the last step
    print(dp[N - 1])

main()

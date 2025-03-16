import sys

# Function to update the minimum value
def chmin(a, b):
    return min(a, b)

INF = 1 << 30  # Define a constant for infinity

def main():
    # Initialize a dp list to store the minimum cost to reach each step
    dp = [INF] * 101000
    dp[0] = 0  # Base case: cost to reach the first step is 0

    # Input the number of steps (N) and the maximum jump distance (K)
    N, K = map(int, sys.stdin.readline().split())
    h = list(map(int, sys.stdin.readline().split()))  # Read the heights of the steps

    # Dynamic programming to calculate the minimum cost to reach each step
    for i in range(N):
        # Check possible jumps from the current step
        for j in range(1, K + 1):
            if i + j < N:  # Ensure we don't go out of bounds
                dp[i + j] = chmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]))

    # Output the minimum cost to reach the last step
    print(dp[N - 1])

if __name__ == "__main__":
    main()

# <END-OF-CODE>

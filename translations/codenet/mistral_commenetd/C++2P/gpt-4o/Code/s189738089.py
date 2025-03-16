import sys

def chmin(a, b):
    # Minimum update function
    if a > b:
        a = b
    return a

INF = 1 << 30

# Main function
def main():
    # Initialize dynamic programming list dp with initial value INF for all indices
    dp = [INF] * 101000
    dp[0] = 0

    # Read input
    N, K = map(int, sys.stdin.readline().split())  # Number of elements in the array and the size of the window
    h = list(map(int, sys.stdin.readline().split()))  # Array of heights

    # Dynamic programming calculation
    for i in range(N):  # Iterate through all indices i
        for j in range(1, K + 1):  # Iterate through all window sizes j
            if i + j < N:  # Ensure we do not go out of bounds
                dp[i + j] = chmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]))

    # Output the result
    print(dp[N - 1])  # Print the minimum cost to reach the last index with window size K

if __name__ == "__main__":
    main()

# <END-OF-CODE>

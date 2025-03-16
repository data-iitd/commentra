import sys

def main():
    # Read input values
    v1, v2, t, d = map(int, sys.stdin.readline().split())
    
    # Initialize the dp array
    dp = [[-(10**17) for _ in range(1150)] for _ in range(t - 1)]
    
    # Set the initial value for the first step
    dp[0][v1] = v1
    
    # Calculate the maximum sum
    for i in range(1, t - 1):
        for j in range(1150):
            for x in range(d + 1):
                if j + x < 1150:
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + x] + j)
            for x in range(d, -1, -1):
                if j - x >= 0:
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + j)
    
    # Find the maximum answer
    ans = float('-inf')
    for i in range(t - 2, t - 1):
        for j in range(1150):
            if abs(j - v2) <= d:
                ans = max(ans, dp[i][j] + v2)
    
    # Print the result
    print(ans)

if __name__ == "__main__":
    main()

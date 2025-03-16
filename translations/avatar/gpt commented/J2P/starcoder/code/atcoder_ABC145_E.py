import sys

def main():
    # Read the number of items (N) and the time limit (T)
    N, T = map(int, input().split())

    # Initialize a 2D array to store the time and value of each item
    AB = [[0 for _ in range(2)] for _ in range(N)]

    # Read the time and value for each item from the input
    for i in range(N):
        AB[i][0], AB[i][1] = map(int, input().split())

    # Sort the items based on the time required in ascending order
    AB.sort(key=lambda x: x[0])

    # Initialize a DP table where dp[i][j] represents the maximum value 
    # that can be obtained using the first i items within j time
    dp = [[0 for _ in range(6001)] for _ in range(N + 1)]

    # Fill the DP table
    for i in range(1, N + 1):
        for timeAfterEat in range(6001):
            # Carry forward the maximum value from the previous item
            dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat])

            # Get the time and value of the current item
            time = AB[i - 1][0]
            value = AB[i - 1][1]

            # Check if the current item can be taken within the remaining time
            if 0 <= timeAfterEat - time and timeAfterEat - time < T:
                # Update the DP table with the maximum value obtained by taking the current item
                dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat - time] + value)

    # Output the maximum value that can be obtained using all items
    print(max(dp[N]))

if __name__ == "__main__":
    main()

# 
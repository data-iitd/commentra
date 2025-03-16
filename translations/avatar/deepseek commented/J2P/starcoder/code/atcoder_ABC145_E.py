
import sys

def main():
    # Read the number of dishes
    N = int(input())

    # Read the time limit for eating dishes
    T = int(input())

    # Initialize the array to store dishes with their time and value
    AB = []
    for i in range(N):
        AB.append([int(x) for x in input().split()])

    # Sort the dishes based on their eating time
    AB.sort(key=lambda x: x[0])

    # Initialize the DP table with dimensions (N+1) x 6001
    dp = [[0] * 6001 for _ in range(N + 1)]

    # Fill the DP table
    for i in range(1, N + 1):
        for timeAfterEat in range(6001):
            # Inherit the maximum value from the previous dish
            dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat])

            # Get the time and value of the current dish
            time = AB[i - 1][0]
            value = AB[i - 1][1]

            # If the dish can be eaten after the given time, update the DP table
            if 0 <= timeAfterEat - time and timeAfterEat - time < T:
                dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat - time] + value)

    # Print the maximum value that can be obtained within the time limit
    print(max(dp[N]))

if __name__ == "__main__":
    main()

# 
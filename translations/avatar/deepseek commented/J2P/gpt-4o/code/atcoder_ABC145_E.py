import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])  # Read the number of dishes
    T = int(data[1])  # Read the time limit for eating dishes

    # Initialize the list to store dishes with their time and value
    AB = []
    index = 2
    for i in range(N):
        time = int(data[index])  # Read the time for each dish
        value = int(data[index + 1])  # Read the value for each dish
        AB.append((time, value))
        index += 2

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
            if 0 <= timeAfterEat - time < T:
                dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat - time] + value)

    # Print the maximum value that can be obtained within the time limit
    print(max(dp[N]))

if __name__ == "__main__":
    main()

# <END-OF-CODE>

# Import necessary Python utility classes
import sys

# Main function to start the program
def main():
    # Read the number of activities N and the time limit T from the console
    N, T = map(int, sys.stdin.readline().split())

    # Initialize a list to store the start time and value of each activity
    AB = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

    # Sort the AB list based on the start time of each activity
    AB.sort(key=lambda x: x[0])

    # Initialize a 2D list dp to store the maximum value that can be obtained up to a certain time after eating an activity
    dp = [[0] * 6001 for _ in range(N + 1)]

    # For each activity i from 1 to N, calculate the maximum value that can be obtained up to a certain time after eating the activity
    for i in range(1, N + 1):
        for timeAfterEat in range(6001):
            # Set the value of dp[i][timeAfterEat] to be the maximum of its previous value
            dp[i][timeAfterEat] = dp[i - 1][timeAfterEat]

            # If the timeAfterEat is within the time limit T after the start time of activity i, update the value of dp[i][timeAfterEat]
            time = AB[i - 1][0]
            value = AB[i - 1][1]
            if timeAfterEat >= time and timeAfterEat < time + T:
                dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat - time] + value)

    # Print the maximum value that can be obtained after eating all the activities
    print(max(dp[N]))

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>

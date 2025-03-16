
# Import necessary Python utility classes
import sys
import itertools

# Main function to start the program
def main():
    # Initialize a Scanner object to read input from the console
    sc = Scanner(sys.stdin)

    # Read the number of activities N and the time limit T from the console
    N = sc.nextInt()
    T = sc.nextInt()

    # Initialize a 2D array AB to store the start time and value of each activity
    AB = [[0, 0] for _ in range(N)]

    # Read the start time and value of each activity from the console and store it in the AB array
    for i in range(N):
        AB[i][0] = sc.nextInt() # Read the start time of activity i
        AB[i][1] = sc.nextInt() # Read the value of activity i

    # Sort the AB array based on the start time of each activity
    AB.sort(key=lambda x: x[0])

    # Initialize a 2D array dp to store the maximum value that can be obtained up to a certain time after eating an activity
    dp = [[0 for _ in range(6001)] for _ in range(N + 1)]

    # For each activity i from 1 to N, calculate the maximum value that can be obtained up to a certain time after eating the activity
    for i in range(1, N + 1):
        for timeAfterEat in range(6001):
            # Set the value of dp[i][timeAfterEat] to be the maximum of its previous value and the value obtained by eating the activity i at timeAfterEat
            dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat])

            # If the timeAfterEat is within the time limit T after the start time of activity i, update the value of dp[i][timeAfterEat] with the maximum value that can be obtained by eating activity i at timeAfterEat and adding the value of the activity to the previous value
            time = AB[i - 1][0]
            value = AB[i - 1][1]
            if timeAfterEat >= time and timeAfterEat < time + T:
                dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat - time] + value)

    # Print the maximum value that can be obtained after eating all the activities
    print(max(dp[N]))

# Call the main function to start the program
if __name__ == "__main__":
    main()


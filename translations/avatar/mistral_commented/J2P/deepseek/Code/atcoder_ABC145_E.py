import sys

# Read the number of activities N and the time limit T from the console
N, T = map(int, sys.stdin.readline().split())

# Initialize a list AB to store the start time and value of each activity
AB = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

# Sort the AB list based on the start time of each activity
AB.sort(key=lambda x: x[0])

# Initialize a 2D list dp to store the maximum value that can be obtained up to a certain time after eating an activity
dp = [[0] * (6001) for _ in range(N + 1)]

# For each activity i from 1 to N, calculate the maximum value that can be obtained up to a certain time after eating the activity
for i in range(1, N + 1):
    for time_after_eat in range(6001):
        # Set the value of dp[i][time_after_eat] to be the maximum of its previous value and the value obtained by eating the activity i at time_after_eat
        dp[i][time_after_eat] = max(dp[i][time_after_eat], dp[i - 1][time_after_eat])

        # If the time_after_eat is within the time limit T after the start time of activity i, update the value of dp[i][time_after_eat] with the maximum value that can be obtained by eating activity i at time_after_eat and adding the value of the activity to the previous value
        time = AB[i - 1][0]
        value = AB[i - 1][1]
        if time_after_eat >= time and time_after_eat < time + T:
            dp[i][time_after_eat] = max(dp[i][time_after_eat], dp[i - 1][time_after_eat - time] + value)

# Print the maximum value that can be obtained after eating all the activities
print(max(dp[N]))

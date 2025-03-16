# Function to solve the problem
def solver():

    # Read the number of actions from the user
    N = int(input())

    # Initialize an empty list to store the actions
    action = []

    # Read each action from the user and append it to the list
    for i in range(N):
        action.append(list(map(int, input().split())))

    # Initialize a 2D list to store the dynamic programming table
    dp = [[0 for _ in range(3)] for _ in range(N)]

    # Base case: Initialize the first row of the dynamic programming table
    for i in range(3):
        dp[0][i] = action[0][i]

    # Iterate through the remaining rows of the dynamic programming table
    for i in range(1, N):
        # Initialize the current cell in the first column
        dp[i][0] = max(dp[i-1][1] + action[i][0], dp[i-1][2] + action[i][0])
        # Initialize the current cell in the second column
        dp[i][1] = max(dp[i-1][0] + action[i][1], dp[i-1][2] + action[i][1])
        # Initialize the current cell in the third column
        dp[i][2] = max(dp[i-1][0] + action[i][2], dp[i-1][1] + action[i][2])

    # Print the maximum value in the last row of the dynamic programming table
    print(max(dp[N-1]))

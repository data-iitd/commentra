def solver():
    # Read the number of actions (N) from user input
    N = int(input())
    
    # Initialize a list to store the action values for each day
    action = []
    
    # Read the action values for each day and store them in the action list
    for i in range(N):
        action.append(list(map(int, input().split())))

    # Initialize a 2D list (dp) to store the maximum points for each action on each day
    dp = [[0 for _ in range(3)] for _ in range(N)]

    # Set the first day's action values in the dp table
    for i in range(3):
        dp[0][i] = action[0][i]

    # Fill the dp table for subsequent days
    for i in range(1, N):
        # Calculate the maximum points for action 0 on day i
        dp[i][0] = max(dp[i-1][1] + action[i][0], dp[i-1][2] + action[i][0])
        
        # Calculate the maximum points for action 1 on day i
        dp[i][1] = max(dp[i-1][0] + action[i][1], dp[i-1][2] + action[i][1])
        
        # Calculate the maximum points for action 2 on day i
        dp[i][2] = max(dp[i-1][0] + action[i][2], dp[i-1][1] + action[i][2])
    
    # Output the maximum points that can be achieved on the last day
    print(max(dp[N-1]))

# Call the solver function to execute the program
solver()

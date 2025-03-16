
def solver():
    # Step 1: Read the number of actions available
    N = int(input())
    
    # Step 2: Read the points available for each action
    action = []
    for i in range(N):
        action.append(list(map(int, input().split())))
    
    # Step 3: Initialize the dp list with zeros
    dp = [[0 for _ in range(3)] for _ in range(N)]
    
    # Step 4: Set the initial points for the first action in each activity
    for i in range(3):
        dp[0][i] = action[0][i]
    
    # Step 5: Iterate through the actions to update the dp list
    for i in range(1, N):
        # Update the dp list for each activity
        dp[i][0] = max(dp[i-1][1] + action[i][0], dp[i-1][2] + action[i][0])
        dp[i][1] = max(dp[i-1][0] + action[i][1], dp[i-1][2] + action[i][1])
        dp[i][2] = max(dp[i-1][0] + action[i][2], dp[i-1][1] + action[i][2])
    
    # Step 6: Print the maximum points from the last action
    print(max(dp[N-1]))

solver()


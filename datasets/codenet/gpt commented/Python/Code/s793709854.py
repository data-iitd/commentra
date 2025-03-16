# Read the number of items (N) and the total time (T)
N, T = map(int, input().split())

# Read the list of items where each item has a time and a value
# L[i][0] is the time required for item i, and L[i][1] is the value of item i
L = [[int(l) for l in input().split()] for _ in range(N)]

# Initialize a 2D list (dp) for dynamic programming
# dp[i][j] will store the maximum value that can be achieved with the first i items within j time
dp = [[0]*T for _ in range(N+1)]

# Fill the dp table
for i in range(N):
    for j in range(T):
        # If the current time j is less than the time required for item i
        if j < L[i][0]:
            # We cannot include item i, so the value remains the same as without it
            dp[i+1][j] = dp[i][j]
        else:
            # We can either exclude item i or include it
            # Take the maximum of excluding or including item i
            dp[i+1][j] = max(dp[i][j], dp[i][j-L[i][0]] + L[i][1])

# Backtrack to find which items were used to achieve the maximum value
used = []
B = dp[N][T-1]  # The maximum value achievable with all items and time T-1
j = T-1  # Start from the maximum time

# Iterate backwards through the items
for i in range(N-1, -1, -1):
    # If the value at dp[i][j] is the same as dp[i+1][j], item i was not used
    if B == dp[i][j]:
        continue
    # If item i was used, reduce the value and time accordingly
    B -= L[i][1]
    used.append(i)  # Keep track of the used item
    j -= L[i][0]  # Reduce the time by the time of the used item

# Calculate the final answer
ans = dp[N][T-1]  # The maximum value achievable
c = 0  # Variable to track the maximum value of unused items

# Find the maximum value of items that were not used
for i in range(N):
    if i in used:
        continue
    c = max(c, L[i][1])  # Update c with the maximum value of unused items

# Print the final result which is the sum of the maximum value and the maximum unused item value
print(ans + c)

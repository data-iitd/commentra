
N, T = map(int, input().split())  # Read number of jobs and days
L = [[int(l) for l in input().split()] for _ in range(N)]  # Read jobs details like start day and profit

# Initialize DP table with all zeros
dp = [[0]*T for _ in range(N+1)]

# Fill DP table in bottom up manner
for i in range(N):
    for j in range(T):
        # If current day is less than start day of the job, then the job cannot be done
        if j < L[i][0]:
            dp[i+1][j] = dp[i][j]
        else:
            # Else, check if the current job can be done on the current day or not
            dp[i+1][j] = max(dp[i][j], dp[i][j-L[i][0]]+L[i][1])

# Find the maximum profit subsequence ending at the last day
used = []
B = dp[N][T-1]
j = T-1
# Iterate through the DP table to find the last job in the maximum profit subsequence
for i in range(N-1, -1, -1):
    # If the maximum profit subsequence ends at the current job, then skip it
    if B == dp[i][j]:
        continue
    # Else, update the maximum profit subsequence and add the current job index to the list of used jobs
    B -= L[i][1]
    used.append(i)
    j -= L[i][0]

# Calculate the profit from the remaining jobs which are not in the maximum profit subsequence
ans = dp[N][T-1]
c = 0
# Iterate through the jobs and calculate the maximum profit from the remaining jobs
for i in range(N):
    # If the current job is already in the maximum profit subsequence, then skip it
    if i in used:
        continue
    # Else, calculate the maximum profit from the remaining jobs and update the maximum profit
    c = max(c, L[i][1])

# Print the final answer which is the sum of maximum profit from the maximum profit subsequence and the remaining jobs
print(ans+c)
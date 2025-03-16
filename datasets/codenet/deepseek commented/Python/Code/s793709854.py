
N, T = map(int, input().split())
L = [[int(l) for l in input().split()] for _ in range(N)]

# Step 1: Reading Input
# The code starts by reading the values of N (number of items) and T (capacity of the knapsack) from the input.

dp = [[0] * T for _ in range(N + 1)]

# Step 2: Initializing DP Table
# The dynamic programming table `dp` is initialized to store the maximum values that can be achieved with the given capacity.

for i in range(N):
    for j in range(T):
        # Step 3: Filling DP Table
        # The nested loops fill the DP table based on the weights and values of the items, ensuring that the maximum value is achieved without exceeding the capacity.
        if j < L[i][0]:
            dp[i + 1][j] = dp[i][j]
        else:
            dp[i + 1][j] = max(dp[i][j], dp[i][j - L[i][0]] + L[i][1])

used = []
B = dp[N][T - 1]
j = T - 1
for i in range(N - 1, -1, -1):
    # Step 4: Backtracking to Find Used Items
    # The code backtracks from the last item to determine which items are used to achieve the maximum value.
    if B == dp[i][j]:
        continue
    B -= L[i][1]
    used.append(i)
    j -= L[i][0]

ans = dp[N][T - 1]
c = 0
for i in range(N):
    # Step 5: Calculating Additional Value
    # The code calculates the additional value that can be achieved by not including any one of the items used.
    if i in used:
        continue
    c = max(c, L[i][1])

# Step 6: Printing the Result
# Finally, the code prints the sum of the maximum value and the additional value.
print(ans + c)
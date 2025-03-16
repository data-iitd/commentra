# Step 1: Input Reading
# The code starts by reading the input value N and the array A of size N.
N = int(input())
A = [0] * (N + 1)
for i in range(1, N + 1):
    A[i] = int(input())

# Step 2: Initialization
# The dp array is initialized to a very large negative value to represent infinity,
# except for dp[0][0][10] which is initialized to 0. This setup helps in finding the maximum value using dynamic programming.
dp = [[[-(1 << 60) for _ in range(20)] for _ in range(2)] for _ in range(N + 1)]
dp[0][0][10] = 0

# Step 3: Dynamic Programming Transition
# The main loop iterates through each element of the array A and updates the dp array based on the previous states.
# The transitions are carefully crafted to ensure the maximum value is computed considering two states: whether the current element is included or not.
for i in range(1, N + 1):
    for j in range(6, 14):
        if dp[i - 1][0][j]!= -(1 << 60):
            dp[i][1][j + 1] = max(dp[i][1][j + 1], dp[i - 1][0][j] + A[i])
            dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][0][j])
        if dp[i - 1][1][j]!= -(1 << 60):
            dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][1][j])

# Step 4: Calculating the Result
# After processing all elements, the code calculates the index V which is used to access the final states in the dp array.
# It then outputs the maximum value between dp[N][0][V] and dp[N][1][V].
V = 10 + (N // 2) - (N - (N // 2))
T1 = dp[N][0][V]
T2 = dp[N][1][V]
print(max(T1, T2))


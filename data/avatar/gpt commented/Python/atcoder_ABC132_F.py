# Define the modulus value for calculations to prevent overflow
mod = 10 ** 9 + 7

# Read input values for n and k
n, k = map(int, input().split())

# Initialize a list to store coefficients
coef = []

# Calculate coefficients based on the divisors of n
for i in range(1, int(n ** 0.5) + 1):
    # Append the count of divisors in the range
    coef.append((n // i) - (n // (i + 1)))

# Fill the remaining coefficients with 1s to ensure the length matches n
coef += [1] * (n - sum(coef))

# Reverse the coefficients list for further processing
coef = coef[::-1]

# Get the length of the coefficients list
nn = len(coef)

# Initialize a 2D list for dynamic programming
# dp[i][j] will store the result for i selections and j coefficients
dp = [[0] * nn for _ in range(k + 1)]

# Base case: there's one way to select 0 items (select nothing)
dp[0][0] = 1

# Fill the dp table for k selections
for i in range(1, k + 1):
    tmp = 0  # Temporary variable to accumulate values
    # Iterate through the coefficients in reverse order
    for j in range(nn - 1, -1, -1):
        # Accumulate the number of ways to select items
        tmp += dp[i - 1][(nn - 1) - j]
        tmp %= mod  # Ensure the value stays within modulus
        # Calculate the number of ways to select i items using the j-th coefficient
        dp[i][j] = coef[j] * tmp
        dp[i][j] %= mod  # Again, ensure the value stays within modulus

# Output the total number of ways to select k items, taking modulus
print(sum(dp[k]) % mod)

mod = 10 ** 9 + 7  # Set the modulus to 10^9 + 7
n, k = map(int, input().split())  # Read the values of n and k from input

# Calculate the coefficients for the number of multiples of each divisor up to n
coef = []
for i in range(1, int(n ** 0.5) + 1):
    coef.append((n // i) - (n // (i + 1)))  # Calculate the number of multiples of i
coef += [1] * (n - sum(coef))  # Adjust for remaining numbers
coef = coef[::-1]  # Reverse the coefficients for dynamic programming

nn = len(coef)  # Get the length of the coefficient list
dp = [[0] * nn for _ in range(k + 1)]  # Initialize the dp table
dp[0][0] = 1  # Base case: one way to achieve sum 0 with 0 elements

# Dynamic programming to calculate the number of ways to achieve sums with up to k elements
for i in range(1, k + 1):
    tmp = 0  # Temporary variable to accumulate the sum of previous row's values
    for j in range(nn - 1, -1, -1):
        tmp += dp[i - 1][(nn - 1) - j]  # Update the temporary sum
        tmp %= mod
        dp[i][j] = coef[j] * tmp  # Update the dp table
        dp[i][j] %= mod

# Print the result: the sum of the last row of dp modulo mod
print(sum(dp[k]) % mod)

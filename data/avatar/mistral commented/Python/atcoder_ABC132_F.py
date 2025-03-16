
# Set the modulus value
mod = 10 ** 9 + 7

# Read input values for n and k
n, k = map(int, input().split())

# Initialize a list 'coef' to store coefficients
coef = []

# Calculate coefficients for n up to its square root
for i in range(1, int(n ** 0.5) + 1):
    # Calculate the difference between the quotient and the next quotient
    coef.append(n // i - n // (i + 1))

# Add remaining coefficients to the list
coef += [1] * (n - sum(coef))

# Reverse the list 'coef'
coef = coef[::-1]

# Initialize a 2D list 'dp' to store intermediate results
nn = len(coef)
dp = [[0] * nn for _ in range(k + 1)]

# Initialize the first row of dp with 1 at index 0
dp[0][0] = 1

# Calculate dp[i][j] for i from 1 to k and j from nn-1 to 0
for i in range(1, k + 1):
    tmp = 0
    # Iterate through the reverse list 'coef' from j = nn-1 to j = 0
    for j in range(nn - 1, -1, -1):
        # Update 'tmp' with the sum of dp[i-1][j] and the product of coef[j] and tmp
        tmp += dp[i - 1][j]
        tmp = (tmp + coef[j]) % mod
        # Update dp[i][j] with the product of coef[j] and tmp
        dp[i][j] = coef[j] * tmp
        dp[i][j] %= mod

# Calculate the final answer by summing up dp[k]
print(sum(dp[k]) % mod)
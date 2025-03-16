# Define long long type for convenience
MOD = 10**9 + 7

# Read input values for n and k
n, k = map(int, input().split())

# Calculate the maximum possible value based on n and k
mx = n * (n + 1) // 2 - (n - k) * (n - k + 1) // 2

# Calculate the minimum possible value based on k
mn = k * (k - 1) // 2

# Initialize result variable
res = 0

# Loop through values from k to n+1 to compute the result
for i in range(k, n + 2):
    # Update result based on current mx and mn values
    res += mx - mn + 1

    # Update mx and mn for the next iteration
    mx += n - i
    mn += i

    # Ensure result stays within the bounds of MOD
    res %= MOD

# Output the final result
print(res)

# <END-OF-CODE>

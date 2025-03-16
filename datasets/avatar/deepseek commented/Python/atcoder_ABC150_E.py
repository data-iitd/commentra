
mod = 10 ** 9 + 7
# Define the modulo value as \(10^9 + 7\)

n = int(input())
# Read the integer input `n`

c = list(map(int, input().split()))
# Read the list of integers `c` and convert them to a list

c.sort(reverse=True)
# Sort the list `c` in descending order

b = pow(2, 2 * n - 2, mod)
# Calculate `b` using the power function with base 2, exponent \(2 * n - 2\), and modulo `mod`

a = 2 * b % mod
# Calculate `a` as twice `b` modulo `mod`

ans = 0
# Initialize `ans` to 0

for i in range(n):
    # Loop through each element in the range `n`
    ans += c[i] * (a + i * b)
    # Update `ans` with the sum of the product of `c[i]` and `(a + i * b)`
    ans %= mod
    # Take modulo `mod` at each step to prevent overflow

print(ans)
# Print the final result `ans`


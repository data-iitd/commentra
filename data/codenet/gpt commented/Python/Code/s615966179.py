# Read input values for n, a, and b from the user
n, a, b = map(int, input().split())

# Calculate the number of complete cycles of (a + b) that fit into n
# Each cycle contributes 'a' to the answer
ans = n // (a + b) * a

# Calculate the remaining items after accounting for complete cycles
# The remaining items can contribute up to 'a' more to the answer
r = min(n % (a + b), a)

# Add the contribution from the remaining items to the answer
ans += r

# Output the final result
print(ans)

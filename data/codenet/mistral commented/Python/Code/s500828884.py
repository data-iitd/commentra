# Read input values: n, a, and b
n, a, b = map(int, input().split())

# Calculate n * a
n_multiplied_by_a = n * a

# Determine the minimum value between n * a and b
minimum = min(n_multiplied_by_a, b)

# Print the minimum value
print(minimum)
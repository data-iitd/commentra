
# Read the values of N and M from the user
N, M = map(int, input().split())

# Calculate the sum of the first N natural numbers
a = N * (N - 1) // 2

# Calculate the sum of the first M natural numbers
b = M * (M - 1) // 2

# Print the sum of a and b
print(a + b)
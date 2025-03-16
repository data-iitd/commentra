# Define long long type for large integers
X, Y = map(int, input().split())

# Check if the sum of X and Y is divisible by 3
if (X + Y) % 3!= 0:
    print(0)
    exit()

# Calculate n based on the sum of X and Y
n = (X + Y) // 3 + 1

# Calculate k based on the relationship to the line y = 2x
k = 2 * (n - 1) - Y + 1

# Output the result of the binomial coefficient C(n-1, k-1)
print(C(n - 1, k - 1))


# Read a line of input, split it into components, and convert them to integers
ABC = list(map(int, input().split()))

# Assign the first, second, and third integers to variables A, B, and C respectively
A = ABC[0]
B = ABC[1]
C = ABC[2]

# Calculate the maximum value from the three possible combinations of A, B, and C
# Each combination represents a different way to arrange the digits
max_value = max([10 * A + B + C, 10 * B + C + A, 10 * C + A + B])

# Print the maximum value obtained from the combinations
print(max_value)

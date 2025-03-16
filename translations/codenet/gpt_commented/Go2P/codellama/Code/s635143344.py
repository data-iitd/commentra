
# Create a list to hold three integers
in = [0, 0, 0]

# Read three integers from standard input
in[0], in[1], in[2] = map(int, input().split())

# Sort the integers in ascending order
in.sort()

# Calculate the result based on the sorted integers
# The result is computed as: (largest number * 10) + (second largest number) + (smallest number)
print(in[2]*10 + in[1] + in[0])


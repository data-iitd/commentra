# Create a slice to hold three integers
in = []

# Read three integers from standard input
in = [int(x) for x in input().split()]

# Sort the integers in ascending order
in.sort()

# Calculate the result based on the sorted integers
# The result is computed as: (largest number * 10) + (second largest number) + (smallest number)
print(in[2]*10 + in[1] + in[0])


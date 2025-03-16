
# Initialize variables
N = 0

# Read input: number of values
N = int(input())

# Allocate memory for N float64 values
values = [0.0] * N

# Read input: N float64 values
for i in range(N):
	values[i] = float(input())

# Sort the slice in ascending order
values.sort()

# Calculate the median value
generated = 0.0
# Iterate through the slice, excluding the last value (which is the maximum)
for i in range(N-1):
	# Calculate the average of the current and next value
	generated = (values[i] + values[i+1]) / 2

	# Update the next value with the calculated average
	values[i+1] = generated

# Print the calculated median value
print(generated)

# 
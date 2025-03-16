# Read the number of values to be processed
N = int(input())

# Initialize a slice to hold the float64 values
values = []

# Read N float64 values from standard input
for i in range(N):
	values.append(float(input()))

# Sort the slice of float64 values in ascending order
values.sort()

# Variable to hold the generated average value
generated = 0.0

# Calculate the average of each pair of adjacent values
for i in range(N-1):
	generated = (values[i] + values[i+1]) / 2
	# Update the next value in the slice with the generated average
	values[i+1] = generated

# Print the last generated average value
print(generated)


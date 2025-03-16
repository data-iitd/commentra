

# Initialize variables
N = int(input())

# Read input: N float64 values
values = [float(input()) for _ in range(N)]

# Sort the list in ascending order
values.sort()

# Calculate the median value
generated = 0
# Iterate through the list, excluding the last value (which is the maximum)
for i in range(N-1):
    # Calculate the average of the current and next value
    generated = (values[i] + values[i+1]) / 2

    # Update the next value with the calculated average
    values[i+1] = generated

# Print the calculated median value
print(generated)


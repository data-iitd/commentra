# Read the number of elements from standard input
n = int(input())

# Initialize a slice to hold the float64 numbers
a = []

# Read n float64 numbers from standard input into the slice
for i in range(n):
	a.append(float(input()))

# Perform a series of operations to reduce the slice
for i in range(n-1):
	# Sort the slice in ascending order
	a.sort()

	# Create a new slice to hold the modified values
	na = []

	# Append all elements from the third element onward to the new slice
	for j in range(2, len(a)):
		na.append(a[j])

	# Calculate the average of the first two elements and append it to the new slice
	na.append((a[0]+a[1])/2)

	# Update the original slice to be the new slice
	a = na

# Print the final remaining element in the slice
print(a[0])

# 
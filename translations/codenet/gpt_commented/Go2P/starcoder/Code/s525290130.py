# <START-OF-CODE>

# Read the number of elements in the array
n = int(input())
a = [0] * n # Initialize a slice of integers with length n

# Populate the slice with integers from input
for i in range(n):
	a[i] = int(input()) # Read each integer and store it in the slice

# Read the number of queries
q = int(input())
# Process each query
for i in range(q):
	b = int(input()) # Read the starting index for the reversal
	e = int(input()) # Read the ending index for the reversal
	a[b:e] = a[b:e][::-1] # Reverse the slice from index b to e

# Write the modified array to output
for i in range(n):
	if i > 0:
		print(" ", end="") # Print a space before each element except the first
	print(a[i], end="") # Print the current element
print() # Print a newline after the output

# 
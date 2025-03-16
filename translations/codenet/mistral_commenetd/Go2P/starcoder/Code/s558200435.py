
# <START-OF-CODE>

# Initialize the variable 'n' to read the number of elements in the array 'a'
n = int(input())

# Create a slice 'a' of length 'n' to store the input elements
a = []

# Read 'n' elements from the standard input and store them in slice 'a'
for i in range(n):
	a.append(int(input()))

# Initialize an empty slice 'b' to store the unique elements
b = []

# Iterate through each element 'v' in slice 'a'
for v in a:
	# Use'sort.bisect_left' function to find the index 'x' where 'v' should be inserted in slice 'b'
	x = bisect.bisect_left(b, v)

	# If 'x' is equal to the length of slice 'b', it means 'v' is not present in the slice, so append it
	if x == len(b):
		b.append(v)
	else:
		# Otherwise, replace the element at index 'x' in slice 'b' with 'v'
		b[x] = v

# Print the length of slice 'b' as the output
print(len(b))

# 
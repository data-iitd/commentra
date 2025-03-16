
# Read the number of elements from standard input
n = int(input())

# Initialize a slice to hold the input integers
a = []
# Read n integers from standard input into the slice a
for i in range(n):
	a.append(int(input()))

# Initialize a slice b to hold the longest increasing subsequence
b = []
# Iterate over each value in the input slice a
for v in a:
	# Use binary search to find the index where v can be placed in b
	x = bisect.bisect_left(b, v)
	# If v is greater than all elements in b, append it to b
	if x == len(b):
		b.append(v)
	else:
		# Otherwise, replace the existing value at index x with v
		b[x] = v

# Output the length of the longest increasing subsequence
print(len(b))


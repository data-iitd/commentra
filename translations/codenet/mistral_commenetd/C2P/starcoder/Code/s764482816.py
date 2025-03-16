
# Read 5 integers from the user and store them in the array io
io = list(map(int,input().split()))

# Perform bubble sort on the array io
for i in range(5):
	# Initialize max and max_j with the first element of the array
	max = io[i]
	max_j = i

	# Compare the current element with the remaining elements
	for j in range(i+1,5):
		# If the current max is smaller than the next element, update max and max_j
		if max<io[j]:
			max = io[j]
			max_j = j

	# Swap the current element with the maximum element
	buf = io[i]
	io[i] = io[max_j]
	io[max_j] = buf

	# Print the sorted elements, except for the last one
	i<4?print(io[i],end=" "):print(io[i])

# Return 0 to indicate successful execution
0


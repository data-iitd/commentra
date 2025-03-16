

# Read 5 integers from the user and store them in the list io
io = list(map(int, input().split()))

# Perform bubble sort on the list io
for i in range(len(io)):
	# Initialize max and max_j with the first element of the list
	max = io[i]
	max_j = i

	# Compare the current element with the remaining elements
	for j in range(i+1, len(io)):
		# If the current max is smaller than the next element, update max and max_j
		if max < io[j]:
			max = io[j]
			max_j = j

	# Swap the current element with the maximum element
	io[i], io[max_j] = io[max_j], io[i]

	# Print the sorted elements, except for the last one
	if i < len(io)-1:
		print(io[i], end=" ")
	else:
		print(io[i])

# Print the sorted list
print(io)


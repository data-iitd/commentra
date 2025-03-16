
#include<stdio.h>

# Declare variables
i, j, max, max_j, buf = 0
io = [0, 0, 0, 0, 0]

# Read 5 integers from the user and store them in the array io
def read_input():
	io[0] = int(input())
	io[1] = int(input())
	io[2] = int(input())
	io[3] = int(input())
	io[4] = int(input())

# Perform bubble sort on the array io
def bubble_sort():
	for i in range(5):
		# Initialize max and max_j with the first element of the array
		max = io[i]
		max_j = i

		# Compare the current element with the remaining elements
		for j in range(i+1, 5):
			# If the current max is smaller than the next element, update max and max_j
			if max < io[j]:
				max = io[j]
				max_j = j

		# Swap the current element with the maximum element
		buf = io[i]
		io[i] = io[max_j]
		io[max_j] = buf

		# Print the sorted elements, except for the last one
		if i < 4:
			print(io[i], end=" ")
		else:
			print(io[i])

# Call the read_input function
read_input()

# Call the bubble_sort function
bubble_sort()

# Return 0 to indicate successful execution
return 0


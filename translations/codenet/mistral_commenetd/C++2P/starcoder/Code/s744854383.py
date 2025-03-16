# -*- coding: utf-8 -*-
# <START-OF-CODE>

# Define the main function
def main():
	# Read the number of elements from the standard input
	N = int(raw_input())

	# Allocate memory for the array and read its elements
	a = [0] * N
	for i in range(N):
		a[i] = int(raw_input())

	# Initialize variables
	idx = 1 # Index for checking the current element in the array
	ans = 0 # Variable to store the answer

	# Process the array
	for i in range(N):
		# Check if the current element matches the index
		if a[i] == idx:
			# Increment the index
			idx += 1
		else:
			# Increment the answer
			ans += 1

	# Output the result
	if idx == 1:
		print -1 # Output -1 if all elements are the same
	else:
		print ans # Output the answer otherwise

# Call the main function
if __name__ == "__main__":
	main()

# 


# Python code to translate the given C code

# Function to find the minimum of two integers
def min(a, b):
	# If 'a' is less than or equal to 'b', return 'a'. Otherwise, return 'b'.
	if a <= b:
		return a
	return b

# Function to check if there is a chain of 4 identical elements in the array 'b' of size 'n'
def Chain(b, n):
	i = 0
	j = 0
	count = 0
	color = 0
	a = b[:] # Create a copy of the input array 'b' to modify it in the function

	# Check for chains of 4 identical elements in the array 'a'
	while i < n - 4:
		# If the current element is not zero and it is identical to the next three elements
		if a[i]!= 0 and a[i] == a[i + 1] and a[i] == a[i + 2] and a[i] == a[i + 3]:
			# Count the number of consecutive identical elements
			count = 0
			color = a[i]

			# Find the length of the chain and replace the identified elements with zeros
			while i < n and a[i] == color:
				a[i] = 0
				count += 1
				i += 1

			# Swap the elements to maintain the order of the array
			for j in range(0, n):
				buf = a[j]
				a[j] = a[j + count]
				a[j + count] = buf

			# Debugging print statement (commented out)
			#print("-----")
			#for j in range(0, n):
			#	print(a[j])
			#print("-----")
			# Get a keypress to pause the execution for debugging purposes (commented out)
			#input()
		i += 1

	# Count the number of unprocessed non-zero elements in the array 'a'
	count = 0
	while a[count]!= 0:
		count += 1

	# If the count is 4 and all elements in the chain are identical, return 0
	if count == 4 and a[0] == a[1] and a[0] == a[2] and a[0] == a[3]:
		return 0

	# Return the length of the longest chain found
	return count

# Main function to read the input and call the 'Chain' function
def main():
	n = 0
	i = 0
	j = 0
	a = []
	ans = 0
	color = 0

	# Read the number of test cases
	while True:
		# Initialize the array 'a' with zeros
		a = [0] * 10000

		# Read the number of elements in the current test case
		n = int(input())
		if n == 0:
			break
		ans = n

		# Read the elements of the current test case
		for i in range(0, n):
			a[i] = int(input())

		# Find the longest chain in the current test case
		for i in range(0, n - 4):
			count = [0, 0, 0]
			for j in range(i, i + 4):
				# Update the count array for the current element
				if a[j] - 1 >= 0:
					count[a[j] - 1] += 1

			# Find the color of the chain
			color = 0
			for j in range(0, 3):
				# If the count of the current color is greater than or equal to 3, set the color
				if count[j] >= 3:
					color = j + 1
					break

			# If a chain of length 4 is found, update the answer
			if color!= 0:
				for j in range(i, i + 4):
					buf = a[j]
					# Swap the current element with the color and call the 'Chain' function recursively
					a[j] = color
					ans = min(ans, Chain(a, n))
					a[j] = buf

		# Print the answer for the current test case
		print(ans)

# Call the main function to start the execution
if __name__ == "__main__":
	main()


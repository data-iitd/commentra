
# Initialize variable N to store the number of elements in the array
N = int(input()) # Read the number of elements from the standard input

# Initialize a scanner to read words from the standard input
scanner = input().split()

# Initialize an array 'v' of size N to store the frequency of each element
v = [0] * N

# Iterate through the input elements and update the frequency in the array 'v'
for i in range(1, N):
	# Read the next element from the standard input
	a = int(scanner[i])
	# Update the frequency of the element 'a-1' in the array 'v'
	v[a-1] += 1

# Iterate through the array 'v' and print each element to the standard output
for e in v:
	# Print each element to the standard output
	print(e)

# End of the code


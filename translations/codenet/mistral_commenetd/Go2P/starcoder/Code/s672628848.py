# Declare variables a, b, c, d, and e of type int
a, b, c, d, e = int(input()), int(input()), int(input()), int(input()), int(input())

# Create a list named al with the values of variables a, b, c, d, and e
al = [a, b, c, d, e]

# Iterate through each element i in the list al starting from the index 0
for n, i in enumerate(al):
	# Assign the index number n and the current element i to the variables n and i respectively
	# Check if the current element i is equal to 0
	if i == 0:
		# Print the index number n+1 as output
		print(n + 1)
		# Break the loop as soon as the first zero element is found
		break


# Declare five integer variables to hold input values
a, b, c, d, e = int(input()), int(input()), int(input()), int(input()), int(input())

# Create a slice containing the five integers
al = [a, b, c, d, e]

# Iterate over the slice using a for loop with the range keyword
for n, i in enumerate(al):
	# Check if the current element is equal to 0
	if i == 0:
		# Print the position of the element (1-based index) and break out of the loop
		print(n + 1)
		break

# 
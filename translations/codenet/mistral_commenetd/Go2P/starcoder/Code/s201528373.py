
# <START-OF-CODE>

# Initialize variables
n = 0
x = 0
l = []

# Read input values for n and x
n = int(input("Enter the number of arrays: "))
x = int(input("Enter the sum of elements in an array that should not exceed: "))

# Initialize an empty slice l to store the arrays
l = []

# Read input values for each array and append them to the slice l
for i in range(n):
	# Read the length of the current array
	tmpL = int(input("Enter the length of array number " + str(i+1) + ": "))

	# Append the length of the current array to the slice l
	l.append(tmpL)

# Initialize variables for sum and result slice index
tmpSum = 0
rs = 0

# Iterate through the slice l to find the index of the last array whose sum is less than or equal to x
for i, v in enumerate(l):
	# Initialize a variable tmpSum to store the sum of elements in the current array
	tmpSum = 0

	# Calculate the sum of elements in the current array
	for j in range(v):
		# Read the value of the current element and add it to the sum
		tmp = int(input("Enter the value of element number " + str(j+1) + " in array number " + str(i+1) + ": "))
		tmpSum += tmp

	# Check if the sum of elements in the current array is greater than x
	if tmpSum > x:
		# If yes, break the loop as we don't need to check further arrays
		break

	# If the sum of elements in the current array is less than or equal to x, update the result slice index
	rs = i + 1

# Print the result slice index
print("The last array index whose sum of elements is less than or equal to", x, "is:", rs)

# 
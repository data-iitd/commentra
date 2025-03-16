
# <START-OF-CODE>

# Declare an integer array 'c' of size 3 to store the input values
c = [0, 0, 0]

# Start an infinite loop to read input values until EOF is reached
while True:
	# Read input values
	c[0], c[1], c[2] = map(int, input().split())

	# Check if EOF has been reached
	if c[0] == 0 and c[1] == 0 and c[2] == 0:
		break

	# Declare and initialize a character array 'card' of size 10 with all elements set to zero
	card = [0] * 10

	# Loop through the array 'c' to mark the corresponding index in 'card' array
	for i in range(3):
		card[c[i] - 1] = 1

	# Initialize count with 0
	count = 0

	# Loop through the array 'card' to check if there are at least 4 distinct numbers in the input
	for i in range(10):
		# If the index in 'card' array is not set to 1 and the sum of input values, index and 1 is less than or equal to 20
		if card[i] == 0 and c[0] + c[1] + i + 1 <= 20:
			count += 1

	# Check if the count is greater than or equal to 4 and print "YES" if true, otherwise print "NO"
	if count >= 4:
		print("YES")
	else:
		print("NO")

# 

# Import required modules
import sys

# Read input from stdin
sage = sys.stdin.readline()

# Check if input is "1"
if sage == "1\n":
	# Print "Hello World"
	print("Hello World")

# Check if input is "2"
elif sage == "2\n":
	# Declare sum variable to store the sum of two integers
	sum = 0

	# Read input from stdin
	for i in range(2):
		num = sys.stdin.readline()
		# Convert string to integer
		num = int(num)
		# Add the integer to the sum
		sum += num

	# Print the sum of the two integers
	print(sum)

# Print "
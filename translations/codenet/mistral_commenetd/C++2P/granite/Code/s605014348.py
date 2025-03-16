

# Function to find the greatest divisor of a given number
def div(n):
	# If the number is even, return 2 as the greatest divisor
	if n % 2 == 0: return 2
	# Calculate the square root of the number
	s = int(n**0.5)
	# Check for divisibility by odd numbers from 3 to the square root
	for i in range(3, s+1, 2):
		# If the number is divisible by the current odd number, return it as the greatest divisor
		if n % i == 0: return i
	# If no divisor is found, return the number itself
	return n

# Read the input number from the user
num = int(input())
# Print the input number
print(num, end=":")

# Continue the process until the number becomes 1
while num!= 1:
	# Print the greatest divisor of the current number
	print(" " + str(div(num)), end="")
	# Divide the current number by its greatest divisor
	num = num // div(num)

# Print a newline character to move the cursor to the next line
print()


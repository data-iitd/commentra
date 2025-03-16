# Define a constant N with the value 1000
N = 1000

# Declare a character array'su' of size N
su = [None] * N

# Initialize an integer variable'susum' to zero
susum = 0

# Initialize an integer variable 'j' to zero
j = 0

# Start an infinite loop
while True:
	# Iterate through each index of the array'su'
	for j in range(N):
		# Read a character from the standard input and store it in the array'su' at the current index
		su[j] = input()
		# If the character read is a newline character, break out of the loop
		if su[j] == '\n':
			break
	# If the first character of the array'su' is '0', break out of the loop
	if su[0] == '0':
		break
	# Print the sum of the digits read from the standard input
	print(susum)
	# Reset the variable'susum' to zero for the next iteration
	susum = 0

# Indicate successful termination of the program
exit(0)


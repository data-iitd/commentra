
# Declare variables to hold the input values
n, x = 0, 0

# Start of the infinite loop
while True:
	n, x = map(int, input().split()) # Read two integers from standard input
	if n == 0 and x == 0: # Check if both n and x are zero
		break # Exit the loop if true

	c = 0 # Initialize a counter to zero
	for i in range(1, n-2+1): # Loop over the first number
		for j in range(i+1, n-1+1): # Loop over the second number
			for k in range(j+1, n+1): # Loop over the third number
				if i+j+k == x: # Check if the sum of the three numbers equals x
					c += 1 # Increment the counter if true
	print(c) # Print the count of valid combinations

# 
import sys

# Declare a scanner variable for reading input
sc = bufio.Scanner(sys.stdin)

# Function to read the next string from input
def nextStr():
	sc.scan() # Scan the next token
	return sc.text() # Return the scanned text

# Function to read the next integer from input
def nextInt():
	sc.scan() # Scan the next token
	i, e = int(sc.text()), None # Convert the scanned text to an integer
	if e!= None:
		raise e # Raise an exception if there is an error during conversion
	return i # Return the integer value

# Read the number of integers to process
n = nextInt()

# Initialize variables for the answer and the previous integer
ans = 0
aPrev = 0

# Loop through each integer input
for i in range(n):
	a = nextInt() # Read the next integer

	# Check conditions based on the current and previous integers
	if a > i or a > aPrev+1: # If the current integer is greater than the index or previous integer + 1
		print(-1) # Print -1 and exit if the condition is met
		exit()
	elif a == aPrev+1: # If the current integer is exactly one more than the previous integer
		ans += 1 # Increment the answer
	else: # For all other cases
		ans += a # Add the current integer to the answer
	aPrev = a # Update the previous integer to the current one

# Print the final answer
print(ans)


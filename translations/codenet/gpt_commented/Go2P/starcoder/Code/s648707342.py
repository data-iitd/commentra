import sys

# Initialize a scanner to read input from standard input
sc = __import__('sys').stdin.readline

# Function to scan an integer from input
def scanInt():
	return int(sc())

# Initialize the scanner to split input by whitespace
sc = __import__('sys').stdin.readline

# Main function where the program execution begins
def main():
	# Read the number of arms
	n = scanInt()
	
	# Define a struct to represent an arm with left and right bounds
	class arm:
		def __init__(self, l, r):
			self.l = l
			self.r = r
	
	# Create a slice to hold the arms
	as = [None] * n
	
	# Read the arm data from input
	for i in range(n):
		x, l = scanInt(), scanInt() # Read the center and length of the arm
		as[i] = arm(x - l, x + l) # Create an arm with the left and right bounds
	
	# Sort the arms based on their right bounds
	as.sort(key = lambda a: a.r)

	# Initialize the count of non-overlapping arms and the rightmost bound
	ans = 1 # Start with the first arm
	r = as[0].r # Set the rightmost bound to the right of the first arm
	
	# Iterate through the sorted arms to count non-overlapping arms
	for i in range(1, n):
		# If the left bound of the current arm is greater than or equal to the rightmost bound
		if as[i].l >= r:
			ans += 1 # Increment the count of non-overlapping arms
			r = as[i].r # Update the rightmost bound to the current arm's right bound
	
	# Print the total count of non-overlapping arms
	print(ans)

# Entry point of program
if __name__ == '__main__':
	main()

